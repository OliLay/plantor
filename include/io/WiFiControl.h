#ifndef PLANTOR_WIFICONTROL_H
#define PLANTOR_WIFICONTROL_H

#include <Arduino.h>
#include <WiFi101.h>
#include "config/Config.h"
#include "config/Secrets.h"
#include "log/Logging.h"

class WiFiControl {
  public:
    static void setup();

    void assureConnection();

    bool connect();

  private:
    char* ssid{};
    char* password{};
    int status = WL_IDLE_STATUS;
};

#endif
