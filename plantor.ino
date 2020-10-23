#include "LedControl.h"

// IO PINs Setup
const uint8_t LED_STATUS_GREEN_PIN = 2;
const uint8_t LED_STATUS_BLUE_PIN = 3;
const uint8_t LED_STATUS_RED_PIN = 4;

LED internalLed = LED(LED_BUILTIN);
RGB_LED statusLed = RGB_LED(LED_STATUS_RED_PIN, LED_STATUS_GREEN_PIN, LED_STATUS_BLUE_PIN);

void setup() {
  Serial.begin(9600);

  internalLed.setup();  
  statusLed.setup();
}

void loop() {
  statusLed.getGreenLed().blinkSmoothly(3);
  statusLed.getRedLed().blinkSmoothly(3);
  statusLed.getBlueLed().blinkSmoothly(3);
}
