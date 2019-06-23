#include "signalHandling.h"
#include <signal.h>
#include <stdio.h>

void sigintHandler(int signal) {
    // Handles the Ctrl+C signal.
    printf(
        "\nCtrl+C detected, but the shell does not terminate according to the "
        "instruction.\nTo exit the shell, either use 'bye' or press 'Ctrl+Z' "
        "\n");
}
