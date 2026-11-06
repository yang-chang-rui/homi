#include <dirent.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

char *version = "0.0.2";

//debug first set
int g_debug = 0;

int debug_log(int debug, int print, char *fmt, ...){

    char log_msg[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(log_msg, sizeof(log_msg), fmt, args);
    va_end(args);

    struct timeval system_log_time_tmp;
    
    gettimeofday(&system_log_time_tmp, NULL);

    struct tm system_log_time_tm_tmp;
    localtime_r(&system_log_time_tmp.tv_sec, &system_log_time_tm_tmp);

    char system_log_time_str_tmp[32];
    strftime(system_log_time_str_tmp, sizeof(system_log_time_str_tmp), "%Y-%m-%d %H:%M:%S", &system_log_time_tm_tmp);


    FILE *log_file_tmp = fopen("./homi_log/log.txt", "a");
    if (log_file_tmp == NULL){
        printf("[%s:%ld]debug:system:log:error:output_path_null:file:%s\n", system_log_time_str_tmp, system_log_time_tmp.tv_usec/1000, log_msg);
        return -1;

    }

    if (debug == 1){
        printf("[%s:%ld]debug:system:log:output:%s\n", system_log_time_str_tmp, system_log_time_tmp.tv_usec/1000, log_msg);
    }else if (print == 1){
        printf("[%s:%ld]%s\n", system_log_time_str_tmp, system_log_time_tmp.tv_usec/1000, log_msg);
    }

    fprintf(log_file_tmp, "[%s:%ld]debug:system:log:output:%s\n", system_log_time_str_tmp, system_log_time_tmp.tv_usec/1000 , log_msg);
    fclose(log_file_tmp);
    return 0;
}

// scan plugin dir, write .so list to file: "name;name;"
int plugin_scan(char *path, int debug){

    debug_log(debug, 0, "debug:system:plugin:scan");

    DIR *dir = opendir(path);

    if (dir == NULL){
        debug_log(debug, 0, "debug:system:plugin:scan:error:dir_null");
        return -1;
    }

    struct dirent *plugin_scan_entry_tmp;
    FILE *plugin_scan_entry_file_tmp = fopen("./homi_plugin_tmp/plugin_scan_entry.txt", "w");
    if (plugin_scan_entry_file_tmp == NULL){
        debug_log(debug, 1, "debug:system:plugin:scan:error:file_null");
        closedir(dir);
        return 1;
    }

    while ((plugin_scan_entry_tmp = readdir(dir)) != NULL){
        int plugin_scan_entry_len_tmp = strlen(plugin_scan_entry_tmp -> d_name);
        // check .so suffix
        if (plugin_scan_entry_len_tmp >= 3 && strcmp(plugin_scan_entry_tmp -> d_name + plugin_scan_entry_len_tmp - 3, ".so") == 0){
                debug_log(debug, 0, "debug:system:plugin:scan:plugin:%s", plugin_scan_entry_tmp -> d_name);
            if (strlen(plugin_scan_entry_tmp -> d_name) > 50){
                debug_log(debug, 1, "debug:system:plugin:scan:error:file_too_long");
                fclose(plugin_scan_entry_file_tmp);
                closedir(dir);
                return -1;
            }
        
            fprintf(plugin_scan_entry_file_tmp, "%s;", plugin_scan_entry_tmp -> d_name); 
        }
    }
    fclose(plugin_scan_entry_file_tmp);
    closedir(dir);

    return 0;
}

char *plugin_read(int plugin_read_number, int debug){
    debug_log(debug, 0, "debug:system:plugin:read");

    FILE *read_plugin_entry_file_tmp = fopen("./homi_plugin_tmp/plugin_scan_entry.txt", "r");
    if (read_plugin_entry_file_tmp == NULL){
        debug_log(debug, 1, "debug:system:plugin:read:error:file_null");
        return NULL;
    }

    // parse file like "a.so;b.so;" into records
    static char plugin_read_entry_out[51];
    int plugin_read_entry_out_char_tmp;
    int plugin_read_entry_out_char_number_tmp = 0;
    int plugin_read_entry_out_number_tmp = 0;
    int plugin_read_entry_out_found = 0;

    while ((plugin_read_entry_out_char_tmp = fgetc(read_plugin_entry_file_tmp)) != EOF){

        if (plugin_read_entry_out_char_tmp == ';'){
            plugin_read_entry_out[plugin_read_entry_out_char_number_tmp] = '\0';
            if (plugin_read_number == plugin_read_entry_out_number_tmp) {
                plugin_read_entry_out_found = 1;
                break; 
            }
            plugin_read_entry_out_char_number_tmp = 0;
            plugin_read_entry_out_number_tmp++;
        } else {
            // accumulate char into buffer
            plugin_read_entry_out[plugin_read_entry_out_char_number_tmp] = plugin_read_entry_out_char_tmp;
            plugin_read_entry_out_char_number_tmp++;
            if (plugin_read_entry_out_char_number_tmp >= 51) {
                debug_log(debug, 1, "debug:system:plugin:read:error:The software has been modified by a third party!!!\nplease close this program.\nthis is not a game!!!\n");
                fclose(read_plugin_entry_file_tmp);                
                return "system:plugin:error:The software has been modified by a third party!!!\nplease close this program.\nthis is not a game!!!\n";
            }
        }
    }

    fclose(read_plugin_entry_file_tmp);
    if (plugin_read_entry_out_found) {
        return plugin_read_entry_out;
    }
    return NULL;
}

int main(int argc, char *argv[]) {

    if (argc > 1) {
        for (int argv_loop = 1; argv_loop < argc; argv_loop++) {
            if (strcmp(argv[argv_loop], "-h") == 0) {
                printf("system:plugin:help\n");
                return 0;
            }
            if (strcmp(argv[argv_loop], "-d") == 0) {
                //debug second set
                g_debug = 1;
                printf("system:version:%s\n", version);
            }
            if (strcmp(argv[argv_loop], "-v") == 0) {
                printf("version:%s\n", version);
                return 0;
            }

            if (strcmp(argv[argv_loop], "-67") == 0) {
                for (int i = 0; i < 67; i++) {
                    printf("error:");
                }
                printf("\n");
                printf("error:system:plugin:error_67:easter_egg\n");
                printf("error:system:main:error_67:easter_egg\n");
                printf("The software has been modified by a third party!!!\nyour server/computer is Being attacked!!!\nPlease open this webpage to see the solution:\nhttps://www.bilibili.com/video/BV1GJ411x7h7\n");
                printf("        ________         ________\n");
                printf("       /        /        \\       /\n");
                printf("      / /-------           ---/ /   \n");
                printf("     / /                     / /\n");
                printf("    /  -------/             / /\n");
                printf("   / /-----/ /             / /\n");
                printf("  / /     / /             / /\n");
                printf(" / ------- /             / /\n");
                printf("/_________/             /_/\n");

                printf("don't close this page, we're trying to recover\n");

                sleep(20);
                printf("\n\n\n");
                printf("invading[=                          ]\n");

                sleep(1);
                printf("invading[==                         ]\n");

                usleep(750000);
                printf("invading[===                        ]\n");
                printf("invading[====                       ]\n");  
                
                usleep(500000);
                printf("invading[=====                      ]\n");

                sleep(2);
                printf("invading[============               ]\n");

                sleep(1);
                printf("invading[========================== ]\n");

                sleep(1);
                printf("invading[========================== ]\n");
                usleep(500000);

                for (int row = 0; row < 108; row++) {
                    for (int col = 0; col < 228; col++) {
                    printf("\033[41m \033[0m"); 
                }
                    printf("\n");
                    fflush(stdout);
                }

                printf("\n");
                printf("horror@horror:~$\n");
                sleep(1);
                printf("horror@horror:~$bye=)\n");
                printf("can't find command 'bye=)'\n");
                sleep(1);
                printf("horror@horror:~$sudo rm -rf /*\n");      
                sleep(2);

                return -67;
            }
        }
    }

    debug_log(g_debug, 0, "debug:plugin_system:start");
    plugin_scan("./plugin",g_debug);
    plugin_read(1, g_debug);

    return 0;
}