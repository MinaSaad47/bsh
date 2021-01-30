#ifndef __LOG_H_
#define __LOG_H_

#include <errno.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

int die(const char *fmt, ...);


#ifdef ENABLE_LOG
#define LOG(X) printf("%s:%d\t%s\n", __FILE__, __LINE__, X)
#define AT "[" __FILE__ ":" TOSTRING(__LINE__) "] "
#else
#define LOG(X)
#define AT 
#endif


#endif // __LOG_H_


