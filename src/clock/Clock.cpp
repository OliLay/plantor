#include "clock/Clock.h"

void Clock::setup(voidFuncPtr interruptCallback) {
    clock.begin();
    reset();
    clock.attachInterrupt(interruptCallback);
}

void Clock::reset() {
    clock.setTime(0, 0, 0);
    clock.setDate(0, 0, 0);
    clock.setAlarmTime(0, 1, 0);
    clock.enableAlarm(clock.MATCH_MMSS);
}

