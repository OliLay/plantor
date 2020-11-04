#ifndef PLANTOR_WIFICONTROL_H
#define PLANTOR_WIFICONTROL_H

#include <Arduino.h>

#if defined(ARDUINO_SAMD_NANO_33_IOT)    
  #include <WiFiNINA.h>
#else
  #include <WiFi101.h>
#endif

#include "config/Config.h"
#include "config/Secrets.h"
#include "log/Logging.h"
#include "LedControl.h"

class WiFiControl {
  public:
    explicit WiFiControl(std::shared_ptr<LEDControl> ledControlPointer) : ledControl(std::move(ledControlPointer)) {};

    static void setup();

    void assureConnection();

    bool connect();

  private:
    std::shared_ptr<LEDControl> ledControl;

    char* ssid{};
    char* password{};
    int status = WL_IDLE_STATUS;
};

#endif
