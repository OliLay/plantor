#include "io/WiFiControl.h"

void WiFiControl::setup() {
  WiFi.hostname(HOSTNAME);
}

bool WiFiControl::connect() {
  status = WiFi.begin((char*) WIFI_SSID, (char*) WIFI_PASSWORD);

  if (status == WL_CONNECTED) {
    log("WiFi: Connected to WiFi %s.", WIFI_SSID);
    return true;
  } else {
    log("WiFi: Could not connect to WiFi, status is %i", status);
    return false;
  }
}

void WiFiControl::assureConnection() {
  while (WiFi.status() != WL_CONNECTED) {
    connect();
  }
}
