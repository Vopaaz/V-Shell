#include "space.h"
#include <stdlib.h>

char *init_buffer(int length) {
    char *buffer = (char *)malloc(length * sizeof(char));
    buffer[0] = 0;
    return buffer;
}

char **init_args(int number, int length) {
    char **args = (char **)malloc(number * sizeof(char *));
    for (int i = 0; i < number; i++) {
        args[i] = (char *)malloc(length * sizeof(char));
        args[i][0] = 0;
    }
    return args;
}

void free_args(char **args, int number) {
    for (int i = 0; i < number; i++) {
        if (args[i] != NULL) free(args[i]);
    }
    free(args);
}