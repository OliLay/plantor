#include "Arduino.h"
#include "LedControl.h"
#include "WiFiControl.h"
#include "config/Secrets.h"

// IO PINs Setup
const uint8_t LED_EXTERNAL_GREEN_PIN = 2;
const uint8_t LED_EXTERNAL_BLUE_PIN = 3;
const uint8_t LED_EXTERNAL_RED_PIN = 4;

LED internalLed = LED(LED_BUILTIN);
RGB_LED externalLed = RGB_LED(LED_EXTERNAL_RED_PIN, LED_EXTERNAL_GREEN_PIN, LED_EXTERNAL_BLUE_PIN);
WiFiControl wiFiControl = WiFiControl((char*) WIFI_SSID, (char*) WIFI_PASSWORD);

void setup() {
  Serial.begin(9600);

  internalLed.setup();
  externalLed.setup();

  if (wiFiControl.connect()) {
    externalLed.getGreenLed().turnOn();
  } else {
    externalLed.getRedLed().turnOn();
  }
}

void loop() {

}


