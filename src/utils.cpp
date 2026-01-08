#include "utils.h"
#include <time.h>
#include <stdint.h>
#include <chrono>
using namespace std::chrono;

uint64_t getNanoTime() {
    
    return duration_cast<nanoseconds>(
        steady_clock::now().time_since_epoch()
    ).count();


    // for linux and POSIX compliant systems
    // timespec ts;
    // clock_gettime(CLOCK_MONOTONIC, &ts); // using monotonic clock because it's not affected by system time changes
    // return (uint64_t)ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

const char* levelToString(LogLevel level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO:  return "INFO";
        case WARN:  return "WARN";
        case ERROR: return "ERROR";
        default:    return "UNK";
    }
}
