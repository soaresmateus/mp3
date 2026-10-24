#pragma once

#include <Adafruit_ST7789.h>
#include <touch/touch.h>

class PaginaInicial {
public:
  PaginaInicial(Adafruit_ST7789& tft, Touch& touch);
  void desenharPaginaInicial();
  void monitorarCliques();

private:
  Adafruit_ST7789& tft;
  Touch& touch;
};