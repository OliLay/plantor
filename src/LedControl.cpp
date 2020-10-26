#include "LedControl.h"

LED::LED(uint8_t pin) {
  this->pin = pin;
}

void LED::setup() const {
  pinMode(pin, OUTPUT);
  turnOff();
}

void LED::turnOn() const {
  analogWrite(pin, MAX_BRIGHTNESS);
}

void LED::turnOff() const {
  analogWrite(pin, MIN_BRIGHTNESS);
}

void LED::blinkSmoothly(int repetitions) const {
  uint8_t current = MIN_BRIGHTNESS;
  uint8_t desired = MAX_BRIGHTNESS;

  repetitions = repetitions * 2;

  while (repetitions > 0) {
    while (current != desired) {
      if (current < desired) {
        current = current + 5;
      } else {
        current = current - 5;
      }
      analogWrite(pin, current);

      delay(25);
    }

    if (desired == MAX_BRIGHTNESS) {
      desired = MIN_BRIGHTNESS;
    } else {
      desired = MAX_BRIGHTNESS;
    }

    repetitions--;
    delay(500);
  }
}

void RGB_LED::setup() {
  redLed.setup();
  greenLed.setup();
  blueLed.setup();
}


LED RGB_LED::getRedLed() {
  return redLed;
}

LED RGB_LED::getGreenLed() {
  return greenLed;
}

LED RGB_LED::getBlueLed() {
  return blueLed;
}

void RGB_LED::turnOffAll() {
  redLed.turnOff();
  greenLed.turnOff();
  blueLed.turnOff();
}
