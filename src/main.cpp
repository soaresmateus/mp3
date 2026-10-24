#include <Arduino.h>
#include <display/display.h>
#include <barra_status/barra_status.h>
#include <pagina_inicial/pagina_inicial.h>
#include <touch/touch.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS 2
#define TFT_IRQ 9
#define TFT_ROTATION 0

Display display;
Touch touch{TFT_CS, TFT_IRQ, TFT_ROTATION};
BarraStatus barraStatus(display.tela());
PaginaInicial paginaInicial(display.tela(), touch);


void setup() {
  pinMode(A0, INPUT);
  display.iniciar();
  barraStatus.desenharBarra();
  paginaInicial.desenharPaginaInicial();
}

void loop() {
  barraStatus.atualizarBarra();
  paginaInicial.monitorarCliques();
  // porcentagem-=0.001;
  // if (porcentagem>=0){
  //   atualizarBateria();
  // }
  // delay(20);
}