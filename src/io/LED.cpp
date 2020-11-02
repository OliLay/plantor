#include "io/LED.h"

OnePinLED::OnePinLED(uint8_t pin) {
  this->pin = pin;
}

void OnePinLED::setup() {
  pinMode(pin, OUTPUT);
  turnOff();
}

void OnePinLED::turnOn(uint8_t brightness) const {
  analogWrite(pin, brightness);
}

void OnePinLED::turnOn() {
  turnOn(MAX_BRIGHTNESS);
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

void OnePinLED::displayLoadingState() {
  // we only have binary on or off atm - so loading should be displayed as a "normal" state and LED should be off
  // TODO: rather blink
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

void RGBLED::displayLoadingState() {
  turnOff();
  redLed.turnOn(189);
  greenLed.turnOn(183);
  blueLed.turnOn(107);
}
