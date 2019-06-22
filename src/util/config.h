#pragma once
#define MAX_COMMAND_LENGTH 100
#define MAX_COMMAND_NUMBER 20
#define PROMPT "> "
#define VSHELL_SLIENT '*'
#define LINUX_SHELL_SLIENT '&'
#define print printf
#define MESSAGE                                                               \
    "--------\n"                                                              \
    "This is a minimum implemented shell coded by Vopaaz (Li YiFan) in June " \
    "2019.\n"                                                                 \
    "It's the course project for Computer System Architechture, Professor "   \
    "Mao.\n"                                                                  \
    "--------\n"

#define __NO_ARGS_INPUT__ 0

#define __BYE__ 1
#define __EXECUTION_FAILED__ -1
#define __EXECUTION_SUCCESS__ 0