#ifndef PLANTOR_MQTTCONTROL_H
#define PLANTOR_MQTTCONTROL_H

#include <ArduinoMqttClient.h>

#include <utility>
#include "WiFiControl.h"
#include "log/Logging.h"
#include "LedControl.h"

class MQTTControl {
public:
    explicit MQTTControl(std::shared_ptr<LEDControl> ledControlPointer) : ledControl(std::move(ledControlPointer)) {};

    void setup();

    void assureConnection();

    bool connect();

    bool connected();

    void sendKeepAlive();

    void publish(const char *topic, double payload);

    void publish(const char *topic, uint16_t payload);

private:
    WiFiClient wiFiClient = WiFiClient();
    MqttClient mqttClient = MqttClient(wiFiClient);
    std::shared_ptr<LEDControl> ledControl;
};

#endif //PLANTOR_MQTTCONTROL_H
