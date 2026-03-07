#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/parser.h"
#include "../include/executor.h"

#define MAX_INPUT 256
#define MAX_HISTORY 100

char history[MAX_HISTORY][MAX_INPUT];
int history_count = 0;

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

        if (strlen(input) == 0)
            continue;
        if (history_count < MAX_HISTORY)
        {
            strcpy(history[history_count], input);
            history_count++;
        }

        parse_command(input, args);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
        {
            break;
        }

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

            continue;
        }

        if (strcmp(args[0], "history") == 0)
        {

            for (int i = 0; i < history_count; i++)
            {
                printf("%d %s\n", i + 1, history[i]);
            }

            continue;
        }

        execute_command(args);
    }

    return 0;
}