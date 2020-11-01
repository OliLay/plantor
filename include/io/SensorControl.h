#ifndef PLANTOR_SENSORCONTROL_H
#define PLANTOR_SENSORCONTROL_H

#include <cstdint>
#include "SI114X.h"

class SensorControl {
public:
    bool start();

    uint16_t getVisibleLight();

    uint16_t getIR();

    double getUVIndex();


private:
    SI114X lightSensor = SI114X();
};


#endif //PLANTOR_SENSORCONTROL_H
