#include "io/SensorControl.h"

bool SensorControl::start() {
  tempHumiditySensor.begin();
  return lightSensor.begin();
}

uint16_t SensorControl::getVisibleLight() {
  return lightSensor.readVisible();
}

uint16_t SensorControl::getIR() {
  return lightSensor.readIR();
}

double SensorControl::getUVIndex() {
  return lightSensor.readUV() / 100.0;
}

double SensorControl::getHumidity() {
  double humidity = tempHumiditySensor.readHumidity();

  if (isnan(humidity)) {
    log("Failed to read humidity from sensor, trying once more this run...");
    delay(2000);
    humidity = tempHumiditySensor.readHumidity();
  }
  return humidity;
}

double SensorControl::getTemperature() {
  double temperature = tempHumiditySensor.readTemperature();

  if (isnan(temperature)) {
    log("Failed to read temperature from sensor, trying once more this run...");
    delay(2000);
    temperature = tempHumiditySensor.readTemperature();
  }
  return temperature;
}

uint16_t SensorControl::getMoisture() {
  return analogRead(MOISTURE_SENSOR_PIN);
}
