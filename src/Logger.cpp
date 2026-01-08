#include "Logger.h"
#include <cstring>
#include <ctime>
#include "utils.h"

LogLevel currentLevel = INFO;

Logger::Logger()
{
    logFile.open("logs.txt", std::ios::app);
    worker = std::thread(&Logger::processLogs, this);
}

Logger::~Logger()
{
    running = false;
    worker.join();
    logFile.close();
}

void Logger::log(LogLevel level, const char *text)
{
    if (level < currentLevel) {
        return; // filtered out
    }
    LogMessage msg{};
    msg.timestamp_ns = getNanoTime();
    msg.level = level;
    strncpy(msg.message, text, 127);
    queue.push(msg);
}

void Logger::processLogs()
{
    LogMessage batch[BATCH_SIZE];


    while (running || !queue.isEmpty())
    {
        int count = 0;
        while (count < BATCH_SIZE && queue.pop(batch[count]))
        {
            count++;
        }
         // write batch
        for (int i = 0; i < count; i++) {
            logFile << batch[i].timestamp_ns<< " [" << batch[i].level << "] "<< batch[i].message << "\n";
        }

        if (count > 0) {
            logFile.flush();   // ensure data hits file
        }

        // this line will prevent busy waiting when there are no logs
        if (count == 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(50));
        }
    }
}
