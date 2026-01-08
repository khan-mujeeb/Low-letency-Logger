#include <thread>
#include <fstream>
#include <atomic>
#include "RingBuffer.h"

#ifndef LOGGER_H
#define LOGGER_H

#define BATCH_SIZE 32


class Logger {
    RingBuffer queue;
    std::atomic<bool> running;
    std::thread worker;
    std::ofstream logFile;

    void processLogs();

    public: 
        Logger();
        ~Logger();
        void log(LogLevel level, const char* text);
};

#endif