// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();

  // crear Boton
  // que se llame miPrimerBoton
  // con el constructor
  Boton miPrimerBoton(7);
  Boton miSegundoBoton(6);


  while (true) {

    miPrimerBoton.leer();

    if (miPrimerBoton.presionado) {
       printf("bacan, estoy presionado pero igual me presiona\n");
     }
     else {
       // cuando no este presionado
       printf("no hay nadie presionandome\n");
     }
  
    miSegundoBoton.leer();

    if (miSegundoBoton.presionado) {
       printf("me presionaron %d veces\n",
       miSegundoBoton.vecesPresionado);
     }
     else {
       // cuando no este presionado
       printf("no hay nadie presionandome tampoco\n");
     }

     // al llegar a 5 presiones, reiniciar el contador
     if (miSegundoBoton.vecesPresionado >= 5) {
      printf("me presionaron 5 veces, me reinicio\n");
      miSegundoBoton.reiniciarContador();
     }

    sleep_ms(1000);
  }
}