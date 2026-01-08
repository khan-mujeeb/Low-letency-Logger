#include <iostream>
#include <thread>
#include <chrono>
#include "Logger.h"
#include "utils.h"

int main() {
    Logger logger;

    const int N = 1'000'000;

    uint64_t start = getNanoTime();

    for (int i = 0; i < N; i++) {
        logger.log(INFO, "Order received");
        logger.log(DEBUG, "Price matched");   // filtered
        logger.log(ERROR, "Order rejected");
    }

    uint64_t end = getNanoTime();

    double total_ns = (double)(end - start);
    double avg_ns = total_ns / N;

    std::cout << "Total logs: " << N << std::endl;
    std::cout << "Total time (ms): " << total_ns / 1e6 << std::endl;
    std::cout << "Average latency per log (ns): " << avg_ns << std::endl;

    return 0;
}


// cd /f/web/Low\ letency\ Logger'[ ]
// g++ -std=c++17 -Iinclude src/main.cpp src/Logger.cpp src/RingBuffer.cpp src/MatchingEngine.cpp -O2 -pthread -o logger