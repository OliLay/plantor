#include "log/Logging.h"

void printTimestamp()
{
    auto now_time = now();

    char temp[22];
    snprintf(temp, sizeof(temp), "%04d/%02d/%02d %02d-%02d-%02d: ",
             year(now_time),
             month(now_time),
             day(now_time),
             hour(now_time),
             minute(now_time),
             second(now_time));
    Serial.print(temp);
}

void log(const char *string)
{
    printTimestamp();
    Serial.println(string);
}