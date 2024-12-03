#include <iostream>
#include <thread>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <mutex>

// Obj.h
class Obj
{
public:
    int ii;
    static int si;
    Obj();
    void incr_ii(std::mutex *m);
    static void incr_si(std::mutex *m);
};
// Obj.cpp
int Obj::si = 5;
Obj::Obj() : ii(0) {}
void Obj::incr_ii(std::mutex *m)
{
    std::lock_guard<std::mutex> lg(*m);
    int i = ii;
    std::this_thread::sleep_for(
        std::chrono::milliseconds(1));
    ii = ++i;
}
void Obj::incr_si(std::mutex *m)
{
    std::lock_guard<std::mutex> lg(*m);
    int i = si;
    std::this_thread::sleep_for(
        std::chrono::milliseconds(1));
    si = ++i;
}

// main.cpp
std::mutex l1;
std::mutex l2;
void incr(Obj &o, std::mutex *m)
{
    for (int i = 0; i < 1000; i++)
    {
        o.incr_ii(m);
    }
}
void incr_static(std::mutex *m)
{
    for (int i = 0; i < 1000; i++)
    {
        Obj::incr_si(m);
    }
}
int main(int argc, char **args)
{
    Obj o1;
    Obj o2;
    std::thread t1(
        incr, std::ref(o1), &l1);
    std::thread t2(
        incr, std::ref(o2), &l2);
    t1.join();
    t2.join();
    std::thread t3(incr_static, &l1);
    std::thread t4(incr_static, &l2);
    t3.join();
    t4.join();
    Obj::si = 0;
    std::thread t5(incr_static, &l1);
    std::thread t6(incr_static, &l1);
    t5.join();
    t6.join();
}
