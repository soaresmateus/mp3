#include "display/display.h"

constexpr int TFT_CS = 10;
constexpr int TFT_DC = 9;
constexpr int TFT_RST = 8;

Display::Display() : tft(TFT_CS, TFT_DC, TFT_RST) {}

void Display::iniciar() {
    tft.init(240, 320);
    tft.invertDisplay(false);
    tft.setRotation(0);
    tft.fillScreen(ST77XX_BLACK);
}

Adafruit_ST7789& Display::tela() {
  return tft;
}