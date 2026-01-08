#include <cstdint>


#ifndef UTILS_H
#define UTILS_H

enum LogLevel {
    DEBUG = 0,
    INFO  = 1,
    WARN  = 2,
    ERROR = 3
};


uint64_t getNanoTime();
const char* levelToString(LogLevel level);




#endif