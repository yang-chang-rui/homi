#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int plugin_use(char *path) {
    void *plugin_use_tmp;
    int (*plugin_init)(void);

    plugin_use_tmp = dlopen(path, RTLD_NOW);
    if (!plugin_use_tmp) {
        printf("system:plugin_use:error:%s\n", dlerror());
        return 1;
    }

    plugin_init = dlsym(plugin_use_tmp, "init");
    if (plugin_init) {
        plugin_init();
    } else {
        printf("system:plugin_use:error:no init\n");
        dlclose(plugin_use_tmp);
        return 1;
    }

    dlclose(plugin_use_tmp);
    return 0;
}

int main(int argc, char *argv[])
{
    int debug = 0;
    char *version = "0.0.1";

    if (argc > 1) {
        for (int argv_loop = 1; argv_loop < argc; argv_loop++) {
            if (strcmp(argv[argv_loop], "-h") == 0) {
                printf("help:\n  -h   help\n  -d  debug\nversion:0.0.1\n");
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
    if (debug){printf("debug:plugin:start");}
    plugin_use("/root/tmp.so");
    return 0;
}
