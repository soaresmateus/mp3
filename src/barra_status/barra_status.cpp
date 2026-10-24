#include <barra_status/barra_status.h>
#include <qtd_musicas_albuns/qtd_musicas_albuns.h>
#include <bateria/bateria.h>

BarraStatus::BarraStatus(Adafruit_ST7789& tft)
    : tft(tft), bateria(tft), contagens(tft) {}

void BarraStatus::desenharBarra() {
  tft.drawFastHLine(0, 30, 240, ST77XX_WHITE);
  contagens.desenharQtdMusicas();
  contagens.desenharQtdAlbuns();
  bateria.desenharBateria();
  contagens.desenharQtdMusicas();
}

void BarraStatus::atualizarBarra() {
  bateria.monitorarBateria();
}

void BarraStatus::atualizarQtdMusicas() {
  contagens.atualizarQtdMusicas();
}

void BarraStatus::atualizarQtdAlbuns() {
  contagens.atualizarQtdAlbuns();
}