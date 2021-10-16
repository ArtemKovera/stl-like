#pragma once
#include<chrono>

struct RegularTimer
{
    //constractor takes a pointer to a variable in which duration will be stored
    RegularTimer(float * vd);
    
    ~RegularTimer();

private:
    float * duration;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> difference;
};