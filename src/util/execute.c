#include "execute.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "config.h"
#include "debug.h"
#include "dir.h"

bool check_and_modify_args_for_background(char*** p_args) {
    for (int i = 1; i < MAX_COMMAND_NUMBER - 1; i++) {
        if ((*p_args)[i] != NULL & (*p_args)[i + 1] == NULL) {
            if (strcmp((*p_args)[i], BACKGROUND_EXECUTION_SYNTAX) == 0) {
                free((*p_args)[i]);
                (*p_args)[i] = NULL;
                return true;
            }
        }
        if ((*p_args)[i] == NULL) {
            return false;
        }
    }
    return false;
}

int execute_one_command(char** args) {
    if (strcmp(args[0], "bye") == 0) {
        return __BYE__;
    }

    if (strcmp(args[0], "cd") == 0) {
        return cd(args);
    }

    bool background = check_and_modify_args_for_background(&args);

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        return __BACKGROUND_PROCESS_ERROR__;
    } else {
        if (background) {
            printf("Command executing in the background, child process id [%d]\n", pid);
            return __EXECUTION_IN_BACKGROUND__;
        } else {
            int status;
            waitpid(pid, &status, 0);
            return status;
        }
    }
}

int execute(char** args) {
    int ix_start = 0;
    for (int i = 1; i < MAX_COMMAND_NUMBER; i++) {
        if (args[i] == NULL) return execute_one_command(args + ix_start);

        if (strcmp(args[i], MULTIPLE_COMMAND_SPLIT_SYNTAX) == 0) {
            free(args[i]);
            args[i] = NULL;
            int status = execute_one_command(args + ix_start);
            if (status != __SUCCESS__) {
                return status;
            }
            ix_start = i + 1;
        }
    }
    return __SUCCESS__;
}
