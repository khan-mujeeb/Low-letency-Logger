#include "utils.h"

#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

struct LogMessage
{
    uint64_t timestamp_ns;
    LogLevel level;
    char message[128];
};

#endif
