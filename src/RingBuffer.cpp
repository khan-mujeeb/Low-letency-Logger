#include "RingBuffer.h"

bool RingBuffer::isFull() {
    return ((head + 1) % RINGBUFFER_SIZE) == tail;
}

bool RingBuffer::isEmpty() {
    return head == tail;
}

bool RingBuffer::push(const LogMessage& msg) {
    if (isFull()) return false;
    buffer[head] = msg;
    head = (head + 1) % RINGBUFFER_SIZE;
    return true;
}

bool RingBuffer::pop(LogMessage& msg) {
    if (isEmpty()) return false;
    msg = buffer[tail];
    tail = (tail + 1) % RINGBUFFER_SIZE;
    return true;
}
