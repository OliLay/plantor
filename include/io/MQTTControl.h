#ifndef PLANTOR_MQTTCONTROL_H
#define PLANTOR_MQTTCONTROL_H

#include <ArduinoMqttClient.h>
#include "WiFiControl.h"
#include "log/Logging.h"

class MQTTControl {
public:
    void setup();

    bool connect();

    void sendKeepAlive();

    void publish(const char* topic, const char* message);

private:
    WiFiClient wiFiClient = WiFiClient();
    MqttClient mqttClient = MqttClient(wiFiClient);
};

#endif //PLANTOR_MQTTCONTROL_H
