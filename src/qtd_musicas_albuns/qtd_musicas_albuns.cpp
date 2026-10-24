#include <qtd_musicas_albuns/qtd_musicas_albuns.h>

QtdMusicasAlbuns::QtdMusicasAlbuns(Adafruit_ST7789& tft) : tft(tft), qtdMusicas(0), qtdAlbuns(0) {}

void QtdMusicasAlbuns::desenharContagem(int qtd, int x, uint16_t cor, bool albuns) {
    tft.fillRect(x, 0, 70, 30, ST77XX_BLACK);

    tft.setTextSize(1);
    tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    tft.setCursor(x + 2, 11);
    tft.print(qtd);

    const int xIcone = x + 24;
    if (albuns) {
        const int discoX = xIcone + 19;
        const int centroY = 15;
        tft.fillCircle(discoX, centroY, 9, cor);
        tft.fillCircle(discoX, centroY, 3, ST77XX_BLACK);
        tft.fillCircle(discoX, centroY, 1, cor);

        const int capaX = xIcone;
        const int capaY = 3;
        tft.fillRoundRect(capaX, capaY, 19, 21, 2, ST77XX_BLACK);
        tft.drawRoundRect(capaX, capaY, 19, 21, 2, cor);
        tft.fillCircle(capaX + 5, capaY + 16, 2, cor);
        tft.drawFastVLine(capaX + 7, capaY + 4, 12, cor);
        tft.drawFastVLine(capaX + 8, capaY + 4, 12, cor);
        tft.drawLine(capaX + 7, capaY + 4, capaX + 15, capaY + 2, cor);
        tft.drawLine(capaX + 7, capaY + 5, capaX + 15, capaY + 3, cor);
        tft.drawFastVLine(capaX + 15, capaY + 2, 9, cor);
        tft.drawFastVLine(capaX + 16, capaY + 2, 9, cor);
    } else {
        tft.fillCircle(xIcone + 8, 22, 2, cor);
        tft.fillCircle(xIcone + 18, 19, 2, cor);
        tft.drawFastVLine(xIcone + 10, 5, 17, cor);
        tft.drawFastVLine(xIcone + 11, 5, 17, cor);
        tft.drawLine(xIcone + 10, 5, xIcone + 20, 2, cor);
        tft.drawLine(xIcone + 10, 6, xIcone + 20, 3, cor);
        tft.drawFastVLine(xIcone + 20, 2, 17, cor);
        tft.drawFastVLine(xIcone + 21, 2, 17, cor);
    }
}

void QtdMusicasAlbuns::desenharQtdMusicas() {
    consultarQtdMusicas();
    desenharContagem(qtdMusicas, 0, tft.color565(245, 66, 135), false);
}

void QtdMusicasAlbuns::atualizarQtdMusicas() {
    desenharQtdMusicas();
}

void QtdMusicasAlbuns::desenharQtdAlbuns() {
    consultarQtdAlbuns();
    desenharContagem(qtdAlbuns, 72, tft.color565(75, 245, 66), true);
}

void QtdMusicasAlbuns::atualizarQtdAlbuns() {
    desenharQtdAlbuns();
}

void QtdMusicasAlbuns::consultarQtdMusicas() {
    qtdMusicas = 10;
}

void QtdMusicasAlbuns::consultarQtdAlbuns() {
    qtdAlbuns = 2;
}