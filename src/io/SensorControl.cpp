#include "io/SensorControl.h"

bool SensorControl::start() {
  return lightSensor.begin() && tempHumiditySensor.begin();
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
  double humidity = tempHumiditySensor.getHumidity();

  if (isnan(humidity)) {
    log("Failed to read humidity from sensor, trying once more this run...");
    delay(2000);
    humidity = tempHumiditySensor.getHumidity();
  }
  return humidity;
}

double SensorControl::getTemperature() {
  double temperature = tempHumiditySensor.getTemperature();

  if (isnan(temperature)) {
    log("Failed to read temperature from sensor, trying once more this run...");
    delay(2000);
    temperature = tempHumiditySensor.getTemperature();
  }
  return temperature;
}

uint16_t SensorControl::getMoisture() {
  return analogRead(MOISTURE_SENSOR_PIN);
}
