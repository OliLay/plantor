#include <Arduino.h>
#include <WiFi101.h>
#include "config/Config.h"

class WiFiControl {
  public:
    WiFiControl(char _ssid[], char _password[]) : ssid(_ssid), password(_password) {
    };

    static void setup();

    bool connect();

  private:
    char* ssid{};
    char* password{};
    int status = WL_IDLE_STATUS;
};
