#include <bateria/bateria.h>

constexpr float MINIMO_BATERIA = 2.7;
constexpr float MAXIMO_BATERIA = 3.3;
constexpr int TENSAO_BATERIA = A0;

Bateria::Bateria(Adafruit_ST7789& tft) : tft(tft) {}

void Bateria::fillLeftSideRoundedRect(int x, int y, int width, int height, int radius, uint16_t color) {
  tft.fillRoundRect(x, y, width, height, radius, color);
  tft.fillRect(x+width-radius, y, radius, height, color);
}

void Bateria::desenharBateria() {
    tft.fillRoundRect(145, 5, 50, 20, 5, ST77XX_BLACK);
    tft.drawRoundRect(145, 5, 50, 20, 5, ST77XX_WHITE);
    largura_da_barra_de_carregado = 50*porcentagem;
    if ((largura_da_barra_de_carregado > 45) || (largura_da_barra_de_carregado<5)){
        tft.fillRoundRect(145, 5, largura_da_barra_de_carregado, 20, 5, ST77XX_WHITE);
    } else {
        fillLeftSideRoundedRect(145, 5, largura_da_barra_de_carregado, 20, 5, ST77XX_WHITE);
    }
    tft.fillRoundRect(197, 10, 5, 10, 5, ST77XX_WHITE);
    tft.setTextSize(1);
    tft.setCursor(205, 11);
    tft.print(bateria, 2);
    tft.print(F("V"));
}

void Bateria::atualizarBateria(){
    desenharBateria();
}

void Bateria::monitorarBateria() {
    if (abs(bateria - analogRead(TENSAO_BATERIA)*3.3/1023) > 0.03) {
        bateria = analogRead(TENSAO_BATERIA)*3.3/1023;
        porcentagem = (bateria-MINIMO_BATERIA)/(MAXIMO_BATERIA-MINIMO_BATERIA);
        if (porcentagem > 1) {
            porcentagem = 1;
        } else if (porcentagem < 0) {
            porcentagem = 0;
        } 
        atualizarBateria();
    }
}