#ifndef __EXEC_H__
#define __EXEC_H__
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define _LOG_ 1

#include "log.h"


int execute(char *cmd, ssize_t len);


int getargs(char ***argsptr, char *cmd, ssize_t len);


#endif // __EXEC_H__
