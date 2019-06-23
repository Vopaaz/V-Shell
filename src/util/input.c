#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "input.h"


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

int get_args(char*** p_global_args) {
    char* buffer = init_buffer(MAX_COMMAND_LENGTH);
    char** args = init_args(MAX_COMMAND_NUMBER, MAX_COMMAND_LENGTH);

    int count_args = 0;
    char this_ = getchar();

    if (this_ == '\n') {
        return __NO_ARGS_INPUT__;
    } else {
        while (this_ == ' ') this_ = getchar();
    }

    while (true) {
        if (this_ != ' ' && this_ != '\n') {
            int l = strlen(buffer);
            buffer[l] = this_;
            buffer[l + 1] = 0;
        } else {
            if (strlen(buffer) != 0) {
                strcpy(args[count_args], buffer);
                buffer[0] = 0;
                count_args++;
            }
        }
        if (this_ == '\n') break;
        this_ = getchar();
    }

    free(buffer);
    free(args[count_args]);
    args[count_args] = NULL;
    *p_global_args = args;
}