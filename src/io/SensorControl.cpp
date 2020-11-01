#include "io/SensorControl.h"

bool SensorControl::start() {
  return lightSensor.Begin();
}

uint16_t SensorControl::getVisibleLight() {
  return lightSensor.ReadVisible();
}

uint16_t SensorControl::getIR() {
  return lightSensor.ReadIR();
}

double SensorControl::getUVIndex() {
  return lightSensor.ReadUV() / 100.0;
}
