#include <pagina_inicial/pagina_inicial.h>

PaginaInicial::PaginaInicial(Adafruit_ST7789& tft, Touch& touch) : tft(tft), touch(touch) {}

void PaginaInicial::desenharPaginaInicial() {
  tft.drawRoundRect(20, 50, 200, 115, 15, ST77XX_WHITE);

  uint16_t azulBT = tft.color565(75,245,66);
  int cx = 120, cy = 107;   // centro do retângulo
  int h = 40;               // meia altura do símbolo
  int w = 22;               // meia largura do símbolo

  for (int d = -1; d <= 1; d++) {   // 3 linhas lado a lado pra ficar grosso
    int x = cx + d;
    tft.drawLine(x, cy - h, x, cy + h, azulBT);                       // linha vertical
    tft.drawLine(x - w, cy - h/2, x + w, cy + h/2, azulBT);           // esq. cima → dir. baixo
    tft.drawLine(x + w, cy + h/2, x, cy + h, azulBT);                 // dir. baixo → ponta de baixo
    tft.drawLine(x - w, cy + h/2, x + w, cy - h/2, azulBT);           // esq. baixo → dir. cima
    tft.drawLine(x + w, cy - h/2, x, cy - h, azulBT);                 // dir. cima → ponta de cima
  }

  
  tft.drawRoundRect(20, 185, 200, 115, 15, ST77XX_WHITE);

  uint16_t corMusica = tft.color565(245,66,135);
  cx = 120, cy = 242;   // centro do retângulo
  int r  = 10;              // raio das cabeças
  int topo = cy - 34;       // altura onde fica a barra

  int xe = cx - 24;         // centro da cabeça esquerda
  int xd = cx + 24;         // centro da cabeça direita
  int yc = cy + 28;         // altura das cabeças

  // cabeças
  tft.fillCircle(xe, yc, r, corMusica);
  tft.fillCircle(xd, yc, r, corMusica);

  // hastes (3 linhas lado a lado pra ficar grossa)
  for (int d = 0; d < 3; d++) {
    tft.drawFastVLine(xe + r - 2 + d, topo, yc - topo, corMusica);
    tft.drawFastVLine(xd + r - 2 + d, topo, yc - topo, corMusica);
  }

  // barra ligando as duas hastes
  tft.fillRect(xe + r - 2, topo, (xd - xe) + 3, 8, corMusica);

  
}

void PaginaInicial::monitorarCliques() {
  if (touch.isThisAreaTouched(145, 5, 195, 25, 100)) {
    tft.fillRoundRect(145, 5, 50, 20, 5, ST77XX_WHITE);
    delay(100);
    tft.drawRoundRect(145, 5, 50, 20, 5, ST77XX_WHITE);
  }
}