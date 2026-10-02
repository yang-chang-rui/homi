#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


char *version = "0.0.2";
int debug = 0;

int plugin_scan(char *path, int debug){

    if (debug == 1){
        printf("system:plugin:scan\n");
    }

    DIR *dir = opendir(path);

    if (dir == NULL){
        printf("system:plugin:scan:error:dir_null\n");
        if (debug == 1){
            printf("system:plugin:scan:error:output_path_null:path:%s\n", path);
        }
        return 1;
    }

    struct dirent *plugin_scan_entry_tmp;
    FILE *plugin_scan_entry_file_tmp = fopen("./homi_plugin_tmp/plugin_scan_entry.txt", "w");
    if (plugin_scan_entry_file_tmp == NULL){
        printf("system:plugin:scan:error:file_null\n");
        closedir(dir);
        return 1;
    }
   
    while ((plugin_scan_entry_tmp = readdir(dir)) != NULL){
        int plugin_scan_entry_len_tmp = strlen(plugin_scan_entry_tmp -> d_name);
        if (plugin_scan_entry_len_tmp >= 3 && strcmp(plugin_scan_entry_tmp -> d_name + plugin_scan_entry_len_tmp - 3, ".so") == 0){
            if (debug == 1){
                printf("system:plugin:scan:plugin:%s\n", plugin_scan_entry_tmp -> d_name);
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
        printf("system:plugin:read\n");
    }

    FILE *read_plugin_entry_file_tmp = fopen("./homi_plugin_tmp/plugin_scan_entry.txt", "r");
    if (read_plugin_entry_file_tmp == NULL){
        printf("system:plugin:read:error:file_null\n");
        return NULL;
    }

    //"\0"and";"
    static char plugin_read_entry_out[53];

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
            plugin_read_entry_out[plugin_read_entry_out_char_number_tmp] = plugin_read_entry_out_char_tmp;
            plugin_read_entry_out_char_number_tmp++;
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
                printf("help:\n  -h   help\n  -d  debug\n  -v  version\nsystem:version:%s\n", version);
                return 0;
            }
            if (strcmp(argv[argv_loop], "-d") == 0) {
                debug = 1;
                printf("system:version:%s\n", version);
            }
            if (strcmp(argv[argv_loop], "-v") == 0) {
                printf("version:%s\n", version);
                return 0;
            }
        }
    }

    if (debug) {
        printf("debug:plugin_system:start\n");
    }

    plugin_scan("./plugin",debug);
    
    plugin_read("./plugin", 0 ,debug);

    return 0;
}