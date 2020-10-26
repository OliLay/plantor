#include "WiFiControl.h"

bool WiFiControl::connect() {
  int status = WL_IDLE_STATUS;

  while (status != WL_CONNECTED) {
    status = WiFi.begin(ssid, password);
    delay(5000);
  }

  Serial.println(WiFi.SSID());
  
}
