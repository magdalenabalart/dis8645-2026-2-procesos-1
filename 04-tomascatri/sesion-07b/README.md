# sesion-07b

## apuntes sesión
En esta clase pasamos un codigo de mediante la web wokwi la cual simula una raspberry pi, nos enseñaron a un boton y que al presionarle mande una señal, de tarea nos dejaron hacer funcionar un boton adicional, lo logre añadiendo una parte del codigo:
```cpp
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
  Boton miSegundoBoton(8);
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

      if (miSegundoBoton.presionado) {
      printf("hola\n");
    }
    else {
      // cuando no este presionado
      printf("adios\n");
    }

    sleep_ms(100);

  }
}

```
Pagina para probar: https://wokwi.com/projects/477099138073325569
## encargos

## lectura
