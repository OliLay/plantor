#include "WiFiControl.h"

void WiFiControl::setup() {
  WiFi.hostname(HOSTNAME);
}

bool WiFiControl::connect() {
  status = WiFi.begin(ssid, password);

  if (status == WL_CONNECTED) {
    return true;
  } else {
    Serial.println("Could not connect to WiFi");
    return false;
  }

}
