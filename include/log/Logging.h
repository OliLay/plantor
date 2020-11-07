#ifndef PLANTOR_LOGGING_H
#define PLANTOR_LOGGING_H

#include <cstdio>
#include <Arduino.h>

void log(const char *string);

template<class Type1>
void log(const char *string, Type1 arg1) {
    char temp[200];
    snprintf(temp, sizeof(temp), string, arg1);

    Serial.println(temp);
}

template<class Type1, class Type2>
void log(const char *string, Type1 arg1, Type2 arg2) {
    char temp[200];
    snprintf(temp, sizeof(temp), string, arg1, arg2);

    Serial.println(temp);
}

template<class Type1, class Type2, class Type3>
void log(const char *string, Type1 arg1, Type2 arg2, Type3 arg3) {
    char temp[200];
    snprintf(temp, sizeof(temp), string, arg1, arg2, arg3);

    Serial.println(temp);
}

#endif
