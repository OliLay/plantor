#include "io/MQTTControl.h"

void MQTTControl::setup() {
    mqttClient.begin(MQTT_BROKER_ADDRESS, 1883, wiFiClient);
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

void MQTTControl::publish(const char *topic, double payload) {
    ledControl->displayColor(255, 215, 0);
    log("Publishing on topic %s with payload %f.", topic, payload);

    mqttClient.publish(topic, String(payload), false, 2);

    ledControl->displayLoadingState();
}

void MQTTControl::publish(const char *topic, uint16_t payload) {
    ledControl->displayColor(255, 215, 0);
    log("Publishing on topic %s with payload %i.", topic, payload);

    // TODO: utf8
    byte a = (unsigned) payload & 0xFFu;
    byte b = ((unsigned) payload >> 8u) & 0xFFu;
    char c[2] = {a, b};

    mqttClient.publish(topic, String(c), false, 2);

    ledControl->displayLoadingState();
}

void MQTTControl::assureConnection() {
    ledControl->displayColor(255, 248, 220);
    if (!connected()) {
        while (!connected()) {
            ledControl->displayErrorState();
            log("Reconnecting to MQTT broker...");
            if (connect()) {
                ledControl->displayLoadingState();
                return;
            } else {
                delay(2500);
            }
        }
    }

    ledControl->displayLoadingState();
}