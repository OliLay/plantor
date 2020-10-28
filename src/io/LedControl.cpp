#include "io/LedControl.h"
#include "config/Config.h"


void LEDControl::setup() {
  auto internalLed = std::shared_ptr<LED>(new OnePinLED(LED_BUILTIN));
  auto externalLed = std::shared_ptr<LED>(new RGBLED(LED_EXTERNAL_RED_PIN, LED_EXTERNAL_GREEN_PIN, LED_EXTERNAL_BLUE_PIN));

  addStatusLed(internalLed);
  addStatusLed(externalLed);
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
