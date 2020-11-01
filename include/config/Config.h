#ifndef PLANTOR_CONFIG_H
#define PLANTOR_CONFIG_H

// WiFi
static const auto HOSTNAME = "mkr1ooo";

// MQTT
static const auto MQTT_CLIENT_ID = "mkr1ooo-mqtt";
static const auto MQTT_BROKER_ADDRESS = "pi.hole";
static const int MQTT_BROKER_PORT = 1883;

// LED Pins
static const uint8_t LED_EXTERNAL_GREEN_PIN = 2;
static const uint8_t LED_EXTERNAL_BLUE_PIN = 3;
static const uint8_t LED_EXTERNAL_RED_PIN = 4;

// Sensor Pins
static const uint8_t DHT22_PIN = 6;
static const uint8_t MOISTURE_SENSOR_PIN = A1;

#endif
