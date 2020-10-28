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

void MQTTControl::sendKeepAlive() {
  mqttClient.poll();
}

void MQTTControl::publish(const char *topic, const char *message) {
  log("Published message %s on topic %s.", message, topic);
  mqttClient.beginMessage(topic);
  mqttClient.print(message);
  mqttClient.endMessage();
}
