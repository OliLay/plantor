#include "io/MQTTControl.h"

void MQTTControl::setup() {
  mqttClient.setId(MQTT_CLIENT_ID);
}

bool MQTTControl::connect() {
  if (!mqttClient.connect(MQTT_BROKER_ADDRESS, 1883)) {
    log("MQTT: Failure connecting to the MQTT broker %s:%i", MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT);
    return false;
  }

  log("MQTT: Connected to %s:%i", MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT);
  return true;
}

bool MQTTControl::connected() {
  return mqttClient.connected();
}

void MQTTControl::sendKeepAlive() {
  mqttClient.poll();
}
