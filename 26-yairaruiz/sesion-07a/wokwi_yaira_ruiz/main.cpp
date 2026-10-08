#include <stdio.h>
#include "pico/stdlib.h"
#include "Boton.h"

int main() {

  stdio_init_all();

  // crear botones con el constructor
  Boton miPrimerBoton(7);
  Boton miSegundoBoton(22);

  miPrimerBoton.nombre[0] = 'P';
  miPrimerBoton.nombre[1] = '\0';

  miSegundoBoton.nombre[0] = 'S';
  miSegundoBoton.nombre[1] = '\0';

  while (true) {

    // PRIMER BOTÓN
    miPrimerBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    else {
      printf("no hay nadie presionandome\n");
    }

    // SEGUNDO BOTÓN
    miSegundoBoton.leer();

    if (miSegundoBoton.presionado) {
      printf("hola, soy el segundo boton\n");
      miSegundoBoton.mostrarNombre();
    }
    else {
      printf("el segundo boton esta libre\n");
    }

    sleep_ms(10);
  }
}