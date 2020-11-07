#include "io/LedControl.h"
#include "config/Config.h"


void LEDControl::setup() {
  auto internalLed = std::shared_ptr<LED>(new OnePinLED(LED_BUILTIN));

  addStatusLed(internalLed);
}

void LEDControl::addStatusLed(const std::shared_ptr<LED>& led) {
  led->setup();
  statusLeds.push_back(led);
}

void LEDControl::displayErrorState() {
  for (const auto& led : statusLeds) {
    led->displayErrorState();
  }
}

void LEDControl::displayNormalState() {
  for (const auto& led : statusLeds) {
    led->displayNormalState();
  }
}

void LEDControl::displayLoadingState() {
  for (const auto& led : statusLeds) {
    led->displayLoadingState();
  }
}

void LEDControl::setStatus(bool success) {
  if (success) {
    displayNormalState();
  } else {
    displayErrorState();
  }
}