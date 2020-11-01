#ifndef PLANTOR_SENSORCONTROL_H
#define PLANTOR_SENSORCONTROL_H

#include <cstdint>
#include "log/Logging.h"
#include "Adafruit_SI1145.h"
#include "DHT.h"
#include "config/Config.h"

class SensorControl {
public:
    bool start();

    uint16_t getVisibleLight();

    uint16_t getIR();

    double getUVIndex();

    double getHumidity();

    double getTemperature();

    static uint16_t getMoisture();


private:
    Adafruit_SI1145 lightSensor = Adafruit_SI1145();
    DHT tempHumiditySensor = DHT(DHT22_PIN, DHT22);
};

#endif //PLANTOR_SENSORCONTROL_H
