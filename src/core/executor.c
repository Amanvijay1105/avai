#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "../include/executor.h"

void execute_command(char **args)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execvp(args[0], args);
        perror("exec failed");
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("fork failed");
    }
}