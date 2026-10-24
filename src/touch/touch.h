#pragma once

#include <Adafruit_ST7789.h>
#include <XPT2046_Touchscreen.h>

class Touch {
public:
  Touch(int touchCs, int touchIrq, int touchRotation);
  bool isThisAreaTouched(int xMin, int yMin, int xMax, int yMax, int zMin);

private:
  XPT2046_Touchscreen touch;
  bool isTouched();
};