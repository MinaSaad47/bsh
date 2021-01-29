#include "cmd.h"




ssize_t
getcmd(char **arg_cmd)
{
            char *_cmd = NULL;
            size_t _len = 0;
            ssize_t _read;
            //(void) getchar();
            _read = getline(&_cmd, &_len, stdin); 
            _read--;
            _cmd[_read] = '\0';
            *arg_cmd = _cmd;
            return _read;
}
