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

  // crear segundo Boton en la patita 9
  Boton miSegundoBoton(9);
  // este boton controla un LED en la patita 15
  miSegundoBoton.configurarLed(15);
  
  while (true) {

    miPrimerBoton.leer();
    miSegundoBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    else {
      // cuando no este presionado
      printf("no hay nadie presionandome\n");
    }

    // el segundo boton hace otra cosa:
    // prende el LED mientras lo presionan
    if (miSegundoBoton.presionado) {
      miSegundoBoton.encenderLed();
    }
    else {
      miSegundoBoton.apagarLed();
    }

    sleep_ms(10);

  }
}