#ifndef __ERRORS_H__
#define __ERRORS_H__

#define _XOPEN_SOURCE 700

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
# define DPRINTF(arg) printf(farg)
#else
#define DPRINTF(arg)
#endif

#define ERR_ABORT(code, text) do { \
    fprintf(stderr, "%s at \"%s\":%d; %s\n", \
        text, __FILE__, __LINE__, strerror(code)); \
    abort(); \
} while (0)

#define ERRNO_ABORT(text) do { \
    fprintf(stderr, "%s at \"%s\": %d; %s\n", \
        text, __FILE__, __LINE__, strerror(errno)); \
    abort(); \
} while (0)

#endif // __ERRORS_H__
