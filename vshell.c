#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMAND_NUMBER 20
#define PROMPT "> "
#define VSHELL_SLIENT '*'
#define LINUX_SHELL_SLIENT '&'
#define print printf

void print_args(char **args, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s \n", args[i]);
    }
}

int main(int argc, char const *argv[]) {
    char *buffer = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
    buffer[0] = 0;

    char **args = (char **)malloc(MAX_COMMAND_NUMBER * sizeof(char *));
    for (int i = 0; i < MAX_COMMAND_NUMBER; i++) {
        args[i] = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
        args[i][0] = 0;
    }

    while (true) {
        int count_args = 0;

        printf(PROMPT);
        char this_ = getchar();

        if (this_ == '\n') {
            continue;
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

        if (strcmp(args[0], "bye") == 0) break;

        char *tmp = args[count_args];
        args[count_args] = NULL;
        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
        } else {
            wait(NULL);
            args[count_args] = tmp;
        }
    }

    for (int i = 0; i < MAX_COMMAND_NUMBER; i++) {
        free(args[i]);
    }
    free(args);

    return 0;
}
