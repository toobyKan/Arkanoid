#include "../includes/Time.hpp"

time_t Time::milliseconds(){
        struct timeval time_now{
        };
        gettimeofday(&time_now, nullptr);
        time_t msec_time = (time_now.tv_sec * 1000) + (time_now.tv_usec / 1000);
        return msec_time;
    }