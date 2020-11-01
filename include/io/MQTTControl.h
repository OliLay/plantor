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

    template<class PayloadType>
    void publish(const char* topic, PayloadType payload) {
      log("Publishing on topic %s with dynamic payload.", topic, payload);

      mqttClient.beginMessage(topic, false, 2);
      mqttClient.print(payload);
      mqttClient.endMessage();
    }

    void publish(const char* topic, uint16_t payload) {
      log("Publishing on topic %s with payload %i.", topic, payload);

      mqttClient.beginMessage(topic, false, 2);
      mqttClient.write((unsigned) payload & 0xFFu);
      mqttClient.write(((unsigned) payload >> 8u) & 0xFFu);
      mqttClient.endMessage();
    }

private:
    WiFiClient wiFiClient = WiFiClient();
    MqttClient mqttClient = MqttClient(wiFiClient);
};

#endif //PLANTOR_MQTTCONTROL_H
