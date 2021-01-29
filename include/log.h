#ifndef __LOG_H_
#define __LOG_H_


#if _LOG_
#include <errno.h>
#include <stdio.h>



#define LOG(X) printf("%s:%d\t%s\n", __FILE__, __LINE__, X)
#else
#define LOG(X)
#endif


#endif // __LOG_H_


