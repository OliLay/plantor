#include "Arduino.h"
#include "io/WiFiControl.h"
#include "io/MQTTControl.h"
#include "io/SensorControl.h"

std::shared_ptr<LEDControl> ledControl = std::unique_ptr<LEDControl>(new LEDControl());
std::shared_ptr<WiFiControl> wiFiControl = std::unique_ptr<WiFiControl>(new WiFiControl());
std::shared_ptr<MQTTControl> mqttControl = std::unique_ptr<MQTTControl>(new MQTTControl(ledControl));
std::shared_ptr<SensorControl> sensorControl = std::unique_ptr<SensorControl>(new SensorControl());

void setup() {
  // safety delay, to be able to upload a new sketch
  delay(4000);
  Serial.begin(9600);

  ledControl->setup();
  ledControl->displayLoadingState();
  WiFiControl::setup();
  mqttControl->setup();

  bool startupSucceeded = sensorControl->start() && wiFiControl->connect() && mqttControl->connect();
  ledControl->setStatus(startupSucceeded);
}

void loop() {
  ledControl->displayLoadingState();
  wiFiControl->assureConnection();
  mqttControl->assureConnection();

  mqttControl->publish("light/uv", sensorControl->getUVIndex());
  mqttControl->publish("light/ir", sensorControl->getIR());
  mqttControl->publish("light/visible", sensorControl->getVisibleLight());
  mqttControl->publish("temperature", sensorControl->getTemperature());
  mqttControl->publish("humidity", sensorControl->getHumidity());
  mqttControl->publish("moisture", SensorControl::getMoisture());

  ledControl->displayNormalState();
  delay(150000);
}


