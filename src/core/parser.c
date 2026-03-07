#include <string.h>
#include "../include/parser.h"

void parse_command(char *input, char **args)
{
    int i = 0;

    char *token = strtok(input, " ");

    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }

    args[i] = NULL;
}