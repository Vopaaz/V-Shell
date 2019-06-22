#include "execute.h"
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "config.h"
#include "debug.h"

int execute(char** args) {
    if (strcmp(args[0], "bye") == 0) {
        return __BYE__;
    }

    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
    } else {
        int status;
        wait(&status);
        return status;
    }
}