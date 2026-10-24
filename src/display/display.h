#pragma once

#include <Adafruit_ST7789.h>

class Display {
public:
  Display();                 // Construtor: prepara o objeto
  void iniciar();            // Inicializa a tela
  Adafruit_ST7789& tela();   // Dá acesso à tela que o objeto guarda

private:
  Adafruit_ST7789 tft;       // O objeto da tela. Existe apenas um.
};