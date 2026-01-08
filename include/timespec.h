#ifndef TIMESPEC_H
#define TIMESPEC_H
#include <time.h>

struct timespec {
    time_t tv_sec;   // seconds
    long   tv_nsec;  // nanoseconds
};

#endif // TIMESPEC_H