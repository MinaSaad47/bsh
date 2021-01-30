#include "exec.h"



int
execute(char *cmd, ssize_t len)
{
        char **args;
        int size = getargs(&args, cmd, len);
        pid_t pid = fork();
        if (pid == 0) {
                if (execvp(args[0], args) == -1) {
                        die(AT "Unknown Command: %s", args[0]);
                }
        }
        for (int i = 0; i < size; i++) {
                free(args[i]);
        }
        free(args);
        wait(NULL);
        return 0;
}


int
getargs(char ***argsptr, char *cmd, ssize_t len)
{
        char *copy = malloc(len); 
        strcpy(copy, cmd);
        char **args = NULL;
        int i;
        char *j, *token;
        for (i = 0, j = copy; ; i++, j = NULL) {
                token = strtok(j, " "); 
                if (token == NULL) break;
                size_t toklen = strlen(token);
                if(token[0] == '\"') {
                        char *subtok = token;
                        int subtoklen = toklen;
                        while(subtok[subtoklen - 1] != '\"') {
                                subtok = strtok(j, " "); 
                                token = realloc(token, subtoklen + 1); 
                                strcat(token, " ");
                                strcat(token, subtok);
                        }
                }
                args = realloc(args, 1);
                args[i] = malloc(toklen);
                strcpy(args[i], token);
        }
        *argsptr = args;
        return i;
}
