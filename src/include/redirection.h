#ifndef REDIRECTION_H
#define REDIRECTION_H

int find_redirect(char **args);
void execute_redirect(char **args, int redirect_index);

#endif