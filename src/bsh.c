#include "args.h"
#include "cmd.h"
#include "exec.h"
#include <unistd.h>



int 
main(int argc, char **argv, char **envp)
{
        process_argv(argc, argv); 
        char *prompt = getenv("BSH_PROMPT");
        if (prompt == NULL) {
                prompt = malloc(sizeof(char) * 3);
                strcpy(prompt, "$ ");
        }
        int prolen = strlen(prompt);

        while(1) {
                write(STDOUT_FILENO, prompt, sizeof(char) * prolen);
                char *cmd;
                ssize_t len = getcmd(&cmd);
                execute(cmd, len);
                free(cmd);
        }
        return 0;
}
