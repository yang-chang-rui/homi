#include <dirent.h>
#include <stdio.h>
#include <string.h>



char *version = "0.0.2";
int debug = 0;

int plugin_scan(char *path, int debug){

  if (debug == 1){
    printf("system:plugin:scan\n");
  }

  DIR *dir = opendir(path);

  if (dir == NULL){
    printf("system:plugin:scan:error:dir_null\n");
    return 1;
  }

  struct dirent *plugin_scan_entry_tmp;

  while ((plugin_scan_entry_tmp = readdir(dir)) != NULL){
    int plugin_scan_entry_len_tmp = strlen(plugin_scan_entry_tmp -> d_name);
    if (plugin_scan_entry_len_tmp >= 3 && strcmp(plugin_scan_entry_tmp -> d_name + plugin_scan_entry_len_tmp - 3, ".so") == 0){
	if (debug == 1){
	  printf("system:plugin:scan:plugin:%s\n", plugin_scan_entry_tmp -> d_name);
	}
    }

  }

  closedir(dir);

  return 0;
}


int main(int argc, char *argv[]) {

    if (argc > 1) {
        for (int argv_loop = 1; argv_loop < argc; argv_loop++) {
            if (strcmp(argv[argv_loop], "-h") == 0) {
                printf("help:\n  -h   help\n  -d  debug\n  -v  version\nsystem:version:0.0.1\n");
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

    return 0;
}
