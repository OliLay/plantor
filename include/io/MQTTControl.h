#ifndef PLANTOR_MQTTCONTROL_H
#define PLANTOR_MQTTCONTROL_H

#include <ArduinoMqttClient.h>
#include "WiFiControl.h"
#include "log/Logging.h"

class MQTTControl {
public:
    void setup();

    bool connect();

    bool connected();

    void sendKeepAlive();

    void publish(const char* topic, double payload);

    void publish(const char* topic, uint16_t payload);

private:
    WiFiClient wiFiClient = WiFiClient();
    MqttClient mqttClient = MqttClient(wiFiClient);
};

#endif //PLANTOR_MQTTCONTROL_H
