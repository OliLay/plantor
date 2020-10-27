#include "LED.h"
#include <ArxSmartPtr.h>
#include <Array.h>

class LEDControl {
public:
    void setup();

    void addStatusLed(const std::shared_ptr<LED>& led);

    void displayErrorState();

    void displayNormalState();

private:
    // currently, this supports 2 LEDs (so we do not need a vector)
    static const uint8_t MAX_STATUS_LEDS = 2;
    Array<std::shared_ptr<LED>, MAX_STATUS_LEDS> statusLeds;
};
