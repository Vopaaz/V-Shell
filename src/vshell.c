#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util/config.h"
#include "util/execute.h"
#include "util/input.h"
#include "util/space.h"

int main(int argc, char const *argv[]) {
    char **args;

    while (true) {
        printf(PROMPT);

        int arg_status = get_args(&args);
        if (arg_status == __NO_ARGS_INPUT__) continue;

        int execute_status = execute(args);
        if (execute_status == __BYE__) break;
    }

    free_args(args, MAX_COMMAND_NUMBER);

    return 0;
}
