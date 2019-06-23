#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "input.h"

char *init_buffer(int length) {
    // Initiallize the buffer space.

    // Parameters:
    //     - length: length of the buffer

    // Returns:
    //     A pointer to the buffer space
    char *buffer = (char *)malloc(length * sizeof(char));
    buffer[0] = 0;
    return buffer;
}

char **init_args(int number, int length) {
    // Initiallize the argument space.

    // Parameters:
    //     - number: number of arguments
    //     - length: length of one argument

    // Returns:
    //     A pointer to the argument space

    char **args = (char **)malloc(number * sizeof(char *));
    for (int i = 0; i < number; i++) {
        args[i] = (char *)malloc(length * sizeof(char));
        args[i][0] = 0;
    }
    return args;
}

void free_args(char **args, int number) {
    // Free the argument space.

    // Parameters:
    //     - args: argument array
    //     - number: number of arguments in the array

    for (int i = 0; i < number; i++) {
        if (args[i] != NULL) free(args[i]);
    }
    free(args);
}

int get_args(char ***p_global_args) {
    // Get the arguments from stdin and split them by space, store them in new
    // spaces, and point the global argument list pointer to them.

    // Parameter:
    //     - p_global_args: pointer to the global argument list

    // Returns:
    //     - Signal indication success or failure of the command-getting-process

    // Side effect:
    //     - Point the global_args to the new space containing argument list

    char *buffer = init_buffer(MAX_COMMAND_LENGTH);
    char **args = init_args(MAX_COMMAND_NUMBER, MAX_COMMAND_LENGTH);

    int count_args = 0;
    char this_ = getchar();

    // Handle spaces before any valid input
    if (this_ == '\n') {
        return __NO_ARGS_INPUT__;
    } else {
        while (this_ == ' ') this_ = getchar();
    }

    // Start valid input
    while (true) {
        if (this_ != ' ' && this_ != '\n') {
            int l = strlen(buffer);
            buffer[l] = this_;
            buffer[l + 1] = 0;
        } else {
            // One argument input finished, line-break or space encountered
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
    // Set the position after the last argument as NULL for further identification of the end of the args array.
    args[count_args] = NULL;
    *p_global_args = args;
    return __ARGS_INPUT_SUCCESS__;
}