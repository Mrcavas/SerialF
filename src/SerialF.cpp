#include "SerialF.h"
#include <Arduino.h>

void setSerial() {}

void sfprint(char* format, ...) {
  va_list argp;
  va_start(argp, format);
  printfchars(format, argp);
  va_end(argp);
}

void sfprintln(char* format, ...) {
  va_list argp;
  va_start(argp, format);
  printfchars(format, argp);
  Serial.println();
  va_end(argp);
}

void printfchars(char* format, va_list argp) {
  bool nextunsigned = false;
  while (*format != '\0') {
    if (*format == '%') {
      format++;
      if (*format == '%') {
        Serial.print('%');
      } else if (*format == 'f') {
        Serial.print(va_arg(argp, float));
      }  else if (*format == 'u') {
        nextunsigned = true;
      } else if (*format == 'c') {
        Serial.print((char) va_arg(argp, int));
      } else if (*format == 'i' && !nextunsigned) {
        Serial.print(va_arg(argp, int));
      } else if (*format == 'l' && !nextunsigned) {
        Serial.print(va_arg(argp, long));
      } else if (*format == 'i' && nextunsigned) {
        Serial.print(va_arg(argp, unsigned int));
        nextunsigned = false;
      } else if (*format == 'l' && nextunsigned) {
        Serial.print(va_arg(argp, unsigned long));
        nextunsigned = false;
      }else if (*format == 'd') {
        Serial.print(va_arg(argp, double));
      } else if (*format == 's') {
        Serial.print(va_arg(argp, short));
      } else if (*format == 'S') {
        Serial.print(va_arg(argp, char*));
      }
    } else {
      Serial.print(*format);
    }
    format++;
  }
}