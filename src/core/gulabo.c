#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/parser.h"
#include "../include/executor.h"

#define MAX_INPUT 256

int main()
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1)
    {

        printf("gulabo> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0)
            break;
        parse_command(input, args);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;

        if (strcmp(args[0], "cd") == 0)
        {

            if (args[1] == NULL)
            {
                printf("cd: missing argument\n");
            }
            else if (chdir(args[1]) != 0)
            {
                perror("cd failed");
            }
        }
        else
        {

            execute_command(args);
        }
    }

    return 0;
}