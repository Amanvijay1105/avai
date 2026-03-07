#ifndef REDIRECTION_H
#define REDIRECTION_H

int find_redirect(char **args);
int find_append(char **args);

void execute_redirect(char **args, int redirect_index);
void execute_append(char **args, int append_index);

#endif