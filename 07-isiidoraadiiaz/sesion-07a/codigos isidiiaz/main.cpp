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

  // crear un segundo Boton
  // conectado a la patita 8
  Boton miSegundoBoton(8);


  while (true) {

    // leer los dos botones
    miPrimerBoton.leer();
    miSegundoBoton.leer();


    // primer boton
    if (miPrimerBoton.presionado) {

      printf("bacan estoy presionado, pero igual me presiona\n");

    }
    else {

      // cuando no este presionado
      printf("no hay nadie presionandome\n");

    }


    // segundo superboton
    if (miSegundoBoton.presionado) {

      // usar nuestro nuevo metodo
      miSegundoBoton.contarPresion();

      printf("soy el segundo boton\n");

      printf(
        "me han contado %d presiones\n",
        miSegundoBoton.cantidadPresiones
      );

    }

    sleep_ms(500);

  }
}