#ifndef REDIRECTION_H
#define REDIRECTION_H

int find_redirect(char **args);
int find_append(char **args);
int find_input(char **args);

void execute_redirect(char **args, int redirect_index);
void execute_append(char **args, int append_index);
void execute_input(char **args, int input_index);

#endif