#ifndef PLANTOR_CLOCK_H
#define PLANTOR_CLOCK_H

#include <RTCZero.h>

class Clock {
public:
    void setup();

    void reset();

private:
    RTCZero clock;
};

#endif //PLANTOR_CLOCK_H
