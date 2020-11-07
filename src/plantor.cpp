#include "Arduino.h"
#include "io/WiFiControl.h"
#include "io/MQTTControl.h"
#include "io/SensorControl.h"
#include <RTCZero.h>

RTCZero rtc;
bool matched = false;

std::shared_ptr<LEDControl> ledControl = std::unique_ptr<LEDControl>(new LEDControl());
std::shared_ptr<WiFiControl> wiFiControl = std::unique_ptr<WiFiControl>(new WiFiControl(ledControl));
std::shared_ptr<MQTTControl> mqttControl = std::unique_ptr<MQTTControl>(new MQTTControl(ledControl));
std::shared_ptr<SensorControl> sensorControl = std::unique_ptr<SensorControl>(new SensorControl());

void alarmMatch()
{
  matched = true;
}

void setup()
{
  rtc.begin();

  rtc.setDate(0, 0, 0);
  rtc.setTime(0, 0, 0);

  rtc.enableAlarm(rtc.MATCH_MMSS);

  rtc.attachInterrupt(alarmMatch);

  rtc.setAlarmMinutes(2);
}

void loop()
{
  if (matched)
  {
    matched = false;
    pinMode(LED_BUILTIN, OUTPUT);
    // safety delay, to be able to upload a new sketch
    digitalWrite(LED_BUILTIN, HIGH);

    //ledControl->setup();
    //ledControl->displayLoadingState();

    WiFiControl::setup();
    mqttControl->setup();

    bool _startupSucceeded = sensorControl->start() && wiFiControl->connect() && mqttControl->connect();
    //ledControl->setStatus(startupSucceeded);

    mqttControl->publish("planto/uv", sensorControl->getUVIndex());
    mqttControl->publish("planto/ir", sensorControl->getIR());
    mqttControl->publish("planto/vis", sensorControl->getVisibleLight());
    mqttControl->publish("planto/temp", sensorControl->getTemperature());
    mqttControl->publish("planto/hum", sensorControl->getHumidity());
    mqttControl->publish("planto/moisture", SensorControl::getMoisture());
    mqttControl->sendKeepAlive();

    mqttControl->disconnect();
    wiFiControl->disconnect();

    digitalWrite(LED_BUILTIN, LOW);

    rtc.setTime(0, 0, 0);
    rtc.setAlarmMinutes(2);
    rtc.standbyMode(); // Sleep until next alarm match
  }
}
