# Low-Latency Logger 

## Overview
This project demonstrates a simplified stock exchange matching engine integrated with a low-latency, asynchronous logging system.

The logger is designed to ensure that business-critical logging does not impact
order matching latency.

## Key Features
- Lock-free asynchronous logger (SPSC ring buffer)
- Nanosecond-precision monotonic timestamps
- Batch-based file writing
- Log level filtering (DEBUG / INFO / WARN / ERROR)
- CPU-pinned logger thread for predictable latency
- Simple limit order matching engine (BUY / SELL)
- Integrated logging for order lifecycle & trades

## Architecture
Producer threads enqueue log messages into a lock-free ring buffer.
A dedicated consumer thread flushes logs to disk asynchronously in batches.

## Tech Stack
- C++17
- std::atomic (lock-free programming)
- POSIX threads (CPU affinity)
- Linux environment

## Sample Output
