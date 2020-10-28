#include "Arduino.h"
#include "io/LedControl.h"
#include "io/WiFiControl.h"
#include "io/MQTTControl.h"

LEDControl ledControl = LEDControl();
WiFiControl wiFiControl = WiFiControl();
MQTTControl mqttControl = MQTTControl();

void setup() {
  // safety delay, to be able to upload a new sketch
  delay(4000);
  Serial.begin(9600);

  ledControl.setup();
  WiFiControl::setup();
  mqttControl.setup();

  if (wiFiControl.connect() && mqttControl.connect()) {
    ledControl.displayNormalState();
  } else {
    ledControl.displayErrorState();
  }
}

void loop() {
  mqttControl.sendKeepAlive();
  mqttControl.publish("Topic", "Test");

  delay(1337);
}


