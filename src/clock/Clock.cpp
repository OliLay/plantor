#include "clock/Clock.h"

void Clock::setup() {
    clock.begin();

    clock.setTime(0, 0, 0);
    clock.setDate(0, 0, 0);
    clock.setAlarmTime(0, 2, 0);
    clock.enableAlarm(clock.MATCH_MMSS);
}

void Clock::reset() {
    setup();
}

