#include "io/WiFiControl.h"

#include <TimeLib.h>

void WiFiControl::setup()
{
#if defined(ARDUINO_SAMD_NANO_33_IOT)
  WiFi.setHostname(HOSTNAME);
#else
  WiFi.hostname(HOSTNAME);
#endif
}

bool WiFiControl::connect()
{
  log("WiFi: Connecting to WiFi %s ...", WIFI_SSID);
  WiFi.lowPowerMode(); // enable low power mode
  status = WiFi.begin((char *)WIFI_SSID, (char *)WIFI_PASSWORD);

  if (status == WL_CONNECTED)
  {
    log("WiFi: Connected to WiFi %s.", WIFI_SSID);
    return true;
  }
  else
  {
    log("WiFi: Could not connect to WiFi, status is %i", status);
    return false;
  }
}

void WiFiControl::assureConnection()
{
  while (WiFi.status() != WL_CONNECTED)
  {
    ledControl->displayErrorState();
    connect();
  }

  ledControl->displayLoadingState();
}

void WiFiControl::disconnect()
{
  WiFi.disconnect();
}
