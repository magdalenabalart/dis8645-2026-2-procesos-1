// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();

  // LED amarillo externo en la patita GP12
  // (con resistencia de 330 ohm en serie)
  const int LED_AMARILLO = 12;
  gpio_init(LED_AMARILLO);
  gpio_set_dir(LED_AMARILLO, GPIO_OUT);
  bool ledEncendido = false;

  // boton A: el de siempre, en GP7 con su resistencia externa
  Boton miPrimerBoton(7);

  // boton B: segunda instancia, en GP6
  Boton miSegundoBoton(6);

  while (true) {

    // ---- boton A: avisa si lo estan presionando ----
    miPrimerBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("Hola\n");
    }
    else {
      // cuando no este presionado
      printf("no hay nadie?\n");
    }

    // ---- boton B: prende y apaga el LED amarillo ----
    // y cuenta cuantos clics lleva
    miSegundoBoton.leer();

    if (miSegundoBoton.huboClic()) {
      ledEncendido = !ledEncendido;
      gpio_put(LED_AMARILLO, ledEncendido);
      printf("boton B: clic %d -> LED amarillo %s\n",
             miSegundoBoton.contador,
             ledEncendido ? "prendido" : "apagado");
    }

    sleep_ms(10);

  }
}