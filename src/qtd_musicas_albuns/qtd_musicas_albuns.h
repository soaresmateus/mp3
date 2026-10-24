#pragma once

#include <Adafruit_ST7789.h>

class QtdMusicasAlbuns {
public:
    QtdMusicasAlbuns(Adafruit_ST7789& tft);
    void desenharQtdMusicas();
    void atualizarQtdMusicas();
    void desenharQtdAlbuns();
    void atualizarQtdAlbuns();
    void consultarQtdMusicas();
    void consultarQtdAlbuns();
private:
    Adafruit_ST7789& tft;
    int qtdMusicas;
    int qtdAlbuns;
    void desenharContagem(int qtd, int x, uint16_t cor, bool albuns);
};