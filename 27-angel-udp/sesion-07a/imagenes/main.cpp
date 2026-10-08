// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();

  // crear Boton que se llama miPrimerBoton
  // con el constructor
  Boton miPrimerBoton(7);
  Boton segundoBoton(8);
  while (true) {

    miPrimerBoton.leer();
    segundoBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    else {
      // cuando no este presionado
      printf("no hay nadie presionandome\n");
    }

    if (segundoBoton.presionado) {
      // cuenta la cantidad de presiones al oprimir el "segundoBoton"
      segundoBoton.contarPresion();
      // imprime el texto con la cantidad de veces presionando el "segundoBoton"
      printf(
        "estilo porta en la suela, llevo %d presiones\n",
        segundoBoton.vecesPresionado
      );
    }
    // es lo que se ve si no se presiona nada
    else {
      printf("tranquilo se la navega\n");
    }

    sleep_ms(100);
  }
}