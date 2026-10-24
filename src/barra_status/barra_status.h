#pragma once

#include <Adafruit_ST7789.h>
#include <bateria/bateria.h>
#include <qtd_musicas_albuns/qtd_musicas_albuns.h>

class BarraStatus {
public:
  explicit BarraStatus(Adafruit_ST7789& tft);
  void desenharBarra();
  void atualizarBarra();
  void atualizarQtdMusicas();
  void atualizarQtdAlbuns();

private:
  Adafruit_ST7789& tft;      // Referência à tela recebida
  Bateria bateria;
  QtdMusicasAlbuns contagens;
};