#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include <atomic>
#include "LogMessage.h"

#define RINGBUFFER_SIZE 1024

class RingBuffer {
    LogMessage buffer[RINGBUFFER_SIZE];
    std::atomic<int> head = 0;
    std::atomic<int> tail = 0;

    

public:
    bool isFull();
    bool isEmpty();
    bool push(const LogMessage& msg);
    bool pop(LogMessage& msg);
};

#endif
