#include "Arduino.h"
#include "io/LedControl.h"
#include "io/WiFiControl.h"
#include "config/Secrets.h"

WiFiControl wiFiControl = WiFiControl((char*) WIFI_SSID, (char*) WIFI_PASSWORD);
LEDControl ledControl = LEDControl();

void setup() {
  // safety delay, to be able to upload a new sketch
  delay(4000);
  Serial.begin(9600);

  ledControl.setup();

  if (wiFiControl.connect()) {
    ledControl.displayNormalState();
  } else {
    ledControl.displayErrorState();
  }
}

void loop() {

}


