#ifndef PLANTOR_MQTTCONTROL_H
#define PLANTOR_MQTTCONTROL_H

#include <MQTT.h>
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

    void loop();

    template<class Payload>
    void publish(const char *topic, Payload payload) {
        auto stringifiedPayload = String(payload);
        log("Publishing on topic %s with payload %s.", topic, stringifiedPayload.c_str());

        mqttClient.publish(topic, stringifiedPayload, false, 0);

        ledControl->displayLoadingState();
    }

private:
    WiFiClient wiFiClient = WiFiClient();
    MQTTClient mqttClient = MQTTClient();
    std::shared_ptr<LEDControl> ledControl;
};

#endif //PLANTOR_MQTTCONTROL_H
