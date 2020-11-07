#include "io/MQTTControl.h"

void MQTTControl::setup()
{
}

bool MQTTControl::connect()
{
  mqttClient.begin(MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT, wiFiClient);
  log("MQTT: Connecting to broker");
  if (!mqttClient.connect(MQTT_CLIENT_ID))
  {
    log("MQTT: Failure connecting to the MQTT broker %s:%i", MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT);
    return false;
  }

  log("MQTT: Connected to %s:%i", MQTT_BROKER_ADDRESS, MQTT_BROKER_PORT);
  return true;
}

bool MQTTControl::disconnect()
{
  return mqttClient.disconnect();
}

bool MQTTControl::connected()
{
  return mqttClient.connected();
}

void MQTTControl::sendKeepAlive()
{
}

void MQTTControl::publish(const char *topic, double payload)
{
  log("Publishing on topic %s with payload %d.", topic, payload);
  mqttClient.publish(topic, String(payload, 8));
}

void MQTTControl::publish(const char *topic, uint16_t payload)
{
  log("Publishing on topic %s with payload %i.", topic, payload);
  mqttClient.publish(topic, String(payload));
  log("done publishing");
}

void MQTTControl::publish(const char *topic, uint32_t payload)
{
  log("Publishing on topic %s with payload %i.", topic, payload);
  mqttClient.publish(topic, String(payload));
  log("done publishing");
}

void MQTTControl::assureConnection()
{
  while (!mqttClient.loop()) // this checks if connected and polls messages
  {
    ledControl->displayErrorState();
    log("Reconnecting to MQTT broker...");
    if (connect())
    {
      ledControl->displayLoadingState();
      return;
    }
  }
}
