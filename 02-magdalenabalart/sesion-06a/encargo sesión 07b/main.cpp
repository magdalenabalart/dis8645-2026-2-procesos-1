// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"
#include "Led.h"

int main() {

  stdio_init_all();

  // crear Boton que se llama miPrimerBoton
  // con el constructor
  Boton miPrimerBoton(7);
  Boton miSegundoBoton(8);
  Led miLed(15);


  while (true) {

    miPrimerBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado\n");

      miLed.prender();
    }
    
    else {
      // cuando no este presionado
      printf("No hay nadie presionandome\n");

      miLed.apagar();
    }

    miSegundoBoton.leer();

    if (miSegundoBoton.presionado) {
      printf("Hola soy segundo botón");

      miLed.prender();
    }
    else {
      // cuando no este presionado
      printf("no hay nadie presionandome\n");

      miLed.apagar();
    }

  
    sleep_ms(10);

  }
}