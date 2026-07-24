#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int debug = 0;
  char *version = "0.0.1";
  
  if (argc > 1)
    {
    for(int argv_loop = 1;argv_loop < argc;argv_loop++)
      {
         if (strcmp(argv[argv_loop],"-h") == 0)
           {
             printf("help:\n  -h   help\n  -d  debug\n  version:0.0.1\n");
             return 0;
           } 
         if (strcmp(argv[argv_loop],"-d") == 0)
           {
              debug = 1;
              printf("system:version:%s\n",version);
           }
      }
    }
  return 0;
}
