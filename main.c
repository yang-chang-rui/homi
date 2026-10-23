#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h> 
#include <unistd.h>


char *version = "0.0.2";

//debug first set
int g_debug = 0;

// scan plugin dir, write .so list to file: "name;name;"
int plugin_scan(char *path, int debug){

    if (debug == 1){
        printf("debug:system:plugin:scan\n");
    }

    DIR *dir = opendir(path);

    if (dir == NULL){
        printf("debug:system:plugin:scan:error:dir_null\n");
        if (debug == 1){
            printf("debug:system:plugin:scan:error:output_path_null:path:%s\n", path);
        }
        return -1;
    }

    struct dirent *plugin_scan_entry_tmp;
    FILE *plugin_scan_entry_file_tmp = fopen("./homi_plugin_tmp/plugin_scan_entry.txt", "w");
    if (plugin_scan_entry_file_tmp == NULL){
        printf("debug:system:plugin:scan:error:file_null\n");
        closedir(dir);
        return 1;
    }
   
    while ((plugin_scan_entry_tmp = readdir(dir)) != NULL){
        int plugin_scan_entry_len_tmp = strlen(plugin_scan_entry_tmp -> d_name);
        // check .so suffix
        if (plugin_scan_entry_len_tmp >= 3 && strcmp(plugin_scan_entry_tmp -> d_name + plugin_scan_entry_len_tmp - 3, ".so") == 0){
            if (debug == 1){
                printf("debug:system:plugin:scan:plugin:%s\n", plugin_scan_entry_tmp -> d_name);
            }
            if (strlen(plugin_scan_entry_tmp -> d_name) > 50){

                printf("debug:system:plugin:scan:error:file_too_long\n");
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

char *plugin_read(char *path, int plugin_read_number, int debug){
    (void)path;

    if (debug == 1){
        printf("debug:system:plugin:read\n");
    }

    FILE *read_plugin_entry_file_tmp = fopen("./homi_plugin_tmp/plugin_scan_entry.txt", "r");
    if (read_plugin_entry_file_tmp == NULL){
        printf("system:plugin:read:error:file_null\n");
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
                printf("system:plugin:read:plugin:%s\n", plugin_read_entry_out);
                plugin_read_entry_out_found = 1;
            }
            plugin_read_entry_out_char_number_tmp = 0;
            plugin_read_entry_out_number_tmp++;
        } else {
            // accumulate char into buffer
            plugin_read_entry_out[plugin_read_entry_out_char_number_tmp] = plugin_read_entry_out_char_tmp;
            plugin_read_entry_out_char_number_tmp++;
        }
    }

    fclose(read_plugin_entry_file_tmp);
    if (plugin_read_entry_out_found) {
        printf("system:plugin:read:plugin:%s\n", plugin_read_entry_out);
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
                printf("error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:error:\n");
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
                printf("horror@horror:~$bye=)\n");
                printf("can't find command 'bye=)'\n");
                printf("horror@horror:~$sudo rm -rf /*\n");      

                return -67;
            }
        }
    }

    if (g_debug) {
        printf("debug:plugin_system:start\n");
    }

    plugin_scan("./plugin",g_debug);
    
    return 0;
}