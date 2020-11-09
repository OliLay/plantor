#include "io/MQTTControl.h"

void MQTTControl::setup() {
    mqttClient.begin(MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT, wiFiClient);
}

bool MQTTControl::connect() {
    if (mqttClient.connect(MQTT_CLIENT_ID)) {
        log("MQTT: Connected to %s:%i", MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT);
        return true;
    } else {
        log("MQTT: Failure connecting to the MQTT broker %s:%i", MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT);
        return false;
    }
}

bool MQTTControl::connected() {
    return mqttClient.connected();
}

void MQTTControl::loop() {
    mqttClient.loop();
}

void MQTTControl::assureConnection() {
    bool isConnected = connected();
    while (!isConnected) {
        ledControl->displayErrorState();
        log("Reconnecting to MQTT broker...");

        isConnected = connect();
        if (isConnected) {
            ledControl->displayLoadingState();
        } else {
            delay(2500);
        }
    }
}