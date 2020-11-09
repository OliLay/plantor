#include "io/SensorControl.h"

bool SensorControl::start() {
    tempHumiditySensor.begin();
    return lightSensor.begin();
}

uint16_t SensorControl::getVisibleLight() {
    log("Reading visible...");
    return lightSensor.readVisible();
}

uint16_t SensorControl::getIR() {
    log("Reading IR...");
    return lightSensor.readIR();
}

double SensorControl::getUVIndex() {
    log("Reading UV index...");
    return lightSensor.readUV() / 100.0;
}

double SensorControl::getHumidity() {
    log("Reading humidity...");
    double humidity = tempHumiditySensor.readHumidity();

    if (isnan(humidity)) {
        log("Failed to read humidity from sensor, trying once more this run...");
        tempHumiditySensor.begin();
        delay(2000);
        humidity = tempHumiditySensor.readHumidity();
    }
    return humidity;
}

double SensorControl::getTemperature() {
    log("Reading temperature...");
    double temperature = tempHumiditySensor.readTemperature();

    if (isnan(temperature)) {
        log("Failed to read temperature from sensor, trying once more this run...");
        tempHumiditySensor.begin();
        delay(2000);
        temperature = tempHumiditySensor.readTemperature();
    }
    return temperature;
}

uint16_t SensorControl::getMoisture() {
    log("Reading moisture...");
    return analogRead(MOISTURE_SENSOR_PIN);
}
