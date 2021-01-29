#include "args.h"
#include <stdlib.h>


void process_argv(int argc, char **argv) {
    if (argc == 1) {
        return;
    }
    printf("Basic Shell\n");
    if (!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v")) {
        printf("\n\tVersion: %s\n", VERSION);
    } 
    exit(EXIT_SUCCESS);
}
