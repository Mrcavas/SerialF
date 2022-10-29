#ifndef SERIALF_H
#define SERIALF_H

#include <Arduino.h>

void setSerial();

void sfprint(char* format, ...);
void sfprintln(char* format, ...);

void printfchars(char* format, va_list argp);

#endif