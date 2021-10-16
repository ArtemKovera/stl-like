#include"regular_stl_timer.h"

RegularTimer::RegularTimer(float * vd): duration{vd}, start{std::chrono::high_resolution_clock::now()}
{

}

RegularTimer::~RegularTimer()
{
    end = std::chrono::high_resolution_clock::now();
    difference = end - start;
    *duration = difference.count();
}
