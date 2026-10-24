#pragma once

#include <Adafruit_ST7789.h>

class Bateria {
    public:
        Bateria(Adafruit_ST7789& tft);
        void desenharBateria();
        void monitorarBateria();
        Adafruit_ST7789& tela();
        private:
        Adafruit_ST7789& tft;
        float bateria;
        float porcentagem;
        float largura_da_barra_de_carregado;
        void atualizarBateria();
        void fillLeftSideRoundedRect(int x, int y, int width, int height, int radius, uint16_t color);
};