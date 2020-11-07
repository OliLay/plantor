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

void MQTTControl::publish(const char *topic, double payload) {
    ledControl->displayColor(255, 215, 0);
    log("Publishing on topic %s with payload %f.", topic, payload);

    mqttClient.beginMessage(topic, false, 2);
    mqttClient.print(payload, 8);
    mqttClient.endMessage();

    ledControl->displayLoadingState();
}

void MQTTControl::publish(const char *topic, uint16_t payload) {
    ledControl->displayColor(255, 215, 0);
    log("Publishing on topic %s with payload %i.", topic, payload);

    mqttClient.beginMessage(topic, false, 2);
    mqttClient.write((unsigned) payload & 0xFFu);
    mqttClient.write(((unsigned) payload >> 8u) & 0xFFu);
    mqttClient.endMessage();

    ledControl->displayLoadingState();
}

void MQTTControl::assureConnection() {
    ledControl->displayColor(255, 248, 220);
    if (connected()) {
        sendKeepAlive();
    } else {
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
