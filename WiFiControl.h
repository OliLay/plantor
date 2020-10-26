#include <Arduino.h>
#include <WiFi.h>

class WiFiControl {
  public:
    WiFiControl(String _ssid, String _password) { 
      _ssid.toCharArray(ssid, _ssid.length());
      _password.toCharArray(password, _password.length());
    };

    bool connect();

  private:
    char* ssid;
    char* password;
};
