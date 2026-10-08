#include "Boton.h"
#include <stdio.h>

// constructor
Boton::Boton(int nuevaPatita) {

  Boton::patita = nuevaPatita;

  gpio_init(Boton::patita);
  gpio_set_dir(Boton::patita, GPIO_IN);
}

// métodos

void Boton::leer() {
  Boton::presionado = gpio_get(Boton::patita);
}

void Boton::presionar() {
  Boton::presionado = true;
}

void Boton::soltar() {
  Boton::presionado = false;
  Boton::duracionPresionado = 0;
}

void Boton::mostrarNombre() {
  printf("Soy el boton %s\n", Boton::nombre);
}