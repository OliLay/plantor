#include "Arduino.h"
#include "io/LedControl.h"
#include "io/WiFiControl.h"
#include "io/MQTTControl.h"
#include "io/SensorControl.h"

LEDControl ledControl = LEDControl();
WiFiControl wiFiControl = WiFiControl();
MQTTControl mqttControl = MQTTControl();
SensorControl sensorControl = SensorControl();

void setStatus(bool status) {
  if (status) {
    ledControl.displayNormalState();
  } else {
    ledControl.displayErrorState();
  }
}

void setup() {
  // safety delay, to be able to upload a new sketch
  delay(4000);
  Serial.begin(9600);

  ledControl.setup();
  WiFiControl::setup();
  mqttControl.setup();

  bool startupSucceeded = sensorControl.start() && wiFiControl.connect() && mqttControl.connect();
  setStatus(startupSucceeded);
}

void loop() {
  mqttControl.sendKeepAlive();

  while (!mqttControl.connected()) {
    setStatus(false);
    log("Reconnecting to MQTT broker...");
    if (mqttControl.connect()) {
      setStatus(true);
    } else {
      delay(2500);
    }
  }

  mqttControl.publish("light/uv", sensorControl.getUVIndex());
  mqttControl.publish("light/ir", sensorControl.getIR());
  mqttControl.publish("light/visible", sensorControl.getVisibleLight());

  delay(300000);
}


