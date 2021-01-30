#ifndef __EXEC_H__
#define __EXEC_H__

#include "config.h"

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "log.h"


int execute(char *cmd, ssize_t len);


int getargs(char ***argsptr, char *cmd, ssize_t len);


#endif // __EXEC_H__
