// Led.cpp
// implementaciones de la clase

// importar el archivo header
#include "Led.h"

// constructor
Led::Led(int nuevaPatita) {

  // guardar el valor
  Led::patita = nuevaPatita;

   // inicializar patita
  gpio_init(Led::patita);
  // el LED es salida, no como el boton
  // el cual es entrada
  // por lo que usamos GPIO_OUT
  gpio_set_dir(Led::patita, GPIO_OUT);
}


// metodos
void Led::encender() {
  Led::encendido = true;
  // se manda 3.3V a la patita
  gpio_put(Led::patita, 1);
}

void Led::apagar() {
  Led::encendido = false;
  Led::duracionEncendido = 0;
  // le llega 0V a la patita
  gpio_put(Led::patita, 0);
}