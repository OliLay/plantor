#include <Arduino.h>

const uint8_t MAX_BRIGHTNESS = 155;
const uint8_t MIN_BRIGHTNESS = 0;

class LED {
public:
    virtual void setup() = 0;

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    virtual void displayErrorState() = 0;
    virtual void displayNormalState() = 0;
    virtual void displayLoadingState() = 0;
    virtual void displayColor(uint8_t r, uint8_t g, uint8_t b) = 0;
};

class OnePinLED : public LED {
  public:
    explicit OnePinLED(uint8_t pin);

    void setup() override;

    void turnOn() override;
    void turnOn(uint8_t brightness) const;
    void turnOff() override;

    void displayErrorState() override;
    void displayNormalState() override;
    void displayLoadingState() override;
    void displayColor(uint8_t r, uint8_t g, uint8_t b) override;

    void blinkSmoothly(int repetitions) const;

  private:
    uint8_t pin;
};

class RGBLED : public LED {
  public:
    RGBLED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) : redLed(redPin), greenLed(greenPin), blueLed(bluePin) {};

    void setup() override;

    void turnOn() override;
    void turnOff() override;

    void displayErrorState() override;
    void displayNormalState() override;
    void displayLoadingState() override;
    void displayColor(uint8_t r, uint8_t g, uint8_t b) override;

    OnePinLED getRedLed();
    OnePinLED getGreenLed();
    OnePinLED getBlueLed();
    
  private:
    OnePinLED redLed;
    OnePinLED greenLed;
    OnePinLED blueLed;
};
