#ifndef TIME_H
#define TIME_H

#include <chrono>
#include <sys/time.h>
#include <time.h>

class Time{
public:
    static time_t milliseconds();
};

#endif