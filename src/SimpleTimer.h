#include "Arduino.h"

#ifndef SIMPLE_TIMER_H
#define SIMPLE_TIMER_H

class SimpleTimer
{

private:
    uint32_t oldTime = 0;           // old time Timer execute callback()
    uint32_t interval = 0;         // delay time (ms)
    void (*callback)() = nullptr;   // callback function
    bool isSet = 0;                 // OBJ have set

public:
    SimpleTimer();
    SimpleTimer(uint32_t interval, void (*callback)());
    ~SimpleTimer();
    int8_t check();
    int8_t set(uint32_t interval, void (*callback)());
    int8_t setIntervalTime(uint32_t interval);
    
};

SimpleTimer::SimpleTimer()
{
}

SimpleTimer::SimpleTimer(uint32_t interval, void (*callback)())
{
    if (callback == nullptr)
    {
        return ;
    }
    
    this->interval = interval;
    this->callback = callback;
    isSet = 1;
    return ;
}

SimpleTimer::~SimpleTimer()
{

}

int8_t SimpleTimer::check()
{
    uint32_t now = millis();
    if (now - oldTime < interval)
    {
        return 0;
    }

    if (isSet == 0)
    {
        return -1;
    }

    callback();
    oldTime = now;
    return 1;
}
int8_t SimpleTimer::set(uint32_t interval, void (*callback)())
{   
    if (callback == nullptr)
    {
        return -1;
    }
    
    this->interval = interval;
    this->callback = callback;
    isSet = 1;
    return 1;
}
int8_t SimpleTimer::setIntervalTime(uint32_t interval){
    this->interval = interval;
    return 1;
}

#endif /* SIMPLE_TIMER_H */
