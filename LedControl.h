#include <Arduino.h>

const uint8_t MAX_BRIGHTNESS = 155;
const uint8_t MIN_BRIGHTNESS = 0;

class LED {
  public:
    LED(uint8_t pin);

    void setup();
    void turnOn();
    void turnOff();
    void blinkSmoothly(int repetitions);

  private:
    uint8_t pin;
};

class RGB_LED {
  public:
    RGB_LED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) : redLed(redPin), greenLed(greenPin), blueLed(bluePin) {};

    void setup();

    LED getRedLed();
    LED getGreenLed();
    LED getBlueLed();
    
  private:
    LED redLed;
    LED greenLed;
    LED blueLed;
};
