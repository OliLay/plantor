#ifndef PLANTOR_CONFIG_H
#define PLANTOR_CONFIG_H

// WiFi
static const auto HOSTNAME = "arduino";

// MQTT
static const auto MQTT_CLIENT_ID = "arduino";
static const auto MQTT_BROKER_ADDRESS = "pi.hole";
static const int MQTT_BROKER_PORT = 1883;

// LED Pins
static const uint8_t LED_EXTERNAL_GREEN_PIN = 2;
static const uint8_t LED_EXTERNAL_BLUE_PIN = 3;
static const uint8_t LED_EXTERNAL_RED_PIN = 4;

// Sensor Pins
static const uint8_t DHT22_PIN = 6;

#if defined(ARDUINO_SAMD_NANO_33_IOT)    
    static const uint8_t MOISTURE_SENSOR_PIN = A7;
#else
    static const uint8_t MOISTURE_SENSOR_PIN = A1;
#endif

#endif
