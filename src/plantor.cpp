#include <memory>

#include "Arduino.h"
#include "io/WiFiControl.h"
#include "io/MQTTControl.h"
#include "io/SensorControl.h"
#include "clock/Clock.h"

std::shared_ptr<LEDControl> ledControl = std::make_shared<LEDControl>();
std::shared_ptr<WiFiControl> wiFiControl = std::make_shared<WiFiControl>(ledControl);
std::shared_ptr<MQTTControl> mqttControl = std::make_shared<MQTTControl>(ledControl);
std::shared_ptr<SensorControl> sensorControl = std::make_shared<SensorControl>();
Clock clock;

void setup() {
    // safety delay, to be able to upload a new sketch
    delay(4000);
    Serial.begin(9600);

    ledControl->setup();
    ledControl->displayLoadingState();
    WiFiControl::setup();
    mqttControl->setup();
    clock.setup();

    bool startupSucceeded = sensorControl->start() && wiFiControl->connect() && mqttControl->connect();
    ledControl->setStatus(startupSucceeded);
}

void loop() {
    delay(100);
    mqttControl->loop();
}

void measure() {
    ledControl->displayLoadingState();
    wiFiControl->assureConnection();
    mqttControl->assureConnection();

    mqttControl->publish("light/uv", sensorControl->getUVIndex());
    mqttControl->publish("light/ir", sensorControl->getIR());
    mqttControl->publish("light/visible", sensorControl->getVisibleLight());
    mqttControl->publish("temperature", sensorControl->getTemperature());
    mqttControl->publish("humidity", sensorControl->getHumidity());
    mqttControl->publish("moisture", SensorControl::getMoisture());

    clock.reset();
    ledControl->displayNormalState();
}


