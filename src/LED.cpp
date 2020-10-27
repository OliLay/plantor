#include "io/LED.h"

OnePinLED::OnePinLED(uint8_t pin) {
  this->pin = pin;
}

void OnePinLED::setup() {
  pinMode(pin, OUTPUT);
  turnOff();
}

void OnePinLED::turnOn() {
  analogWrite(pin, MAX_BRIGHTNESS);
}

void OnePinLED::turnOff() {
  analogWrite(pin, MIN_BRIGHTNESS);
}

void OnePinLED::blinkSmoothly(int repetitions) const {
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

void OnePinLED::displayErrorState() {
  turnOn();
}

void OnePinLED::displayNormalState() {
  turnOff();
}

void RGBLED::setup() {
  redLed.setup();
  greenLed.setup();
  blueLed.setup();
}


OnePinLED RGBLED::getRedLed() {
  return redLed;
}

OnePinLED RGBLED::getGreenLed() {
  return greenLed;
}

OnePinLED RGBLED::getBlueLed() {
  return blueLed;
}

void RGBLED::turnOff() {
  redLed.turnOff();
  greenLed.turnOff();
  blueLed.turnOff();
}

void RGBLED::turnOn() {
  // yellow should be default when just 'turning on'
  redLed.turnOn();
  greenLed.turnOn();
}

void RGBLED::displayErrorState() {
  turnOff();
  redLed.turnOn();
}

void RGBLED::displayNormalState() {
  turnOff();
  greenLed.turnOn();
}
