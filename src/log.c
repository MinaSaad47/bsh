#include "log.h"

int 
die(const char *fmt, ...)
{
        va_list vargs;
        va_start(vargs, fmt);
#ifdef ENABLE_LOG
        fprintf(stderr, "Err(%d): %s\n", errno, strerror(errno));
#endif
        vfprintf(stderr, fmt, vargs);
        fprintf(stderr, "\n");
        va_end(vargs);
        exit(errno);
}


