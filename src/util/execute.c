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

int execute(char** args) {
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
            printf("Command executing in child process [%d]\n", pid);
            return __EXECUTION_IN_BACKGROUND__;
        } else {
            int status;
            waitpid(pid, &status, 0);
            return status;
        }
    }
}
