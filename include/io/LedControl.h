#ifndef PLANTOR_LEDCONTROL_H
#define PLANTOR_LEDCONTROL_H

#include "LED.h"
#include <ArxSmartPtr.h>
#include <Array.h>

class LEDControl {
public:
    void setup();

    void setStatus(bool success);

    void addStatusLed(const std::shared_ptr<LED>& led);

    void displayErrorState();

    void displayLoadingState();

    void displayNormalState();

    void displayColor(uint8_t r, uint8_t g, uint8_t b);

private:
    // currently, this supports 2 LEDs (so we do not need a vector)
    static const uint8_t MAX_STATUS_LEDS = 2;
    Array<std::shared_ptr<LED>, MAX_STATUS_LEDS> statusLeds;
};

#endif