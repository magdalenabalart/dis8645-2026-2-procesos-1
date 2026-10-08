// Boton.cpp
// implementaciones de la clase

// importar el archivo header
#include "Boton.h"

// constructor
Boton::Boton(int nuevaPatita) {

  // guardar el valor
  Boton::patita = nuevaPatita;

  // inicializar patita
  gpio_init(Boton::patita);
  // la patita es entrada
  gpio_set_dir(Boton::patita, GPIO_IN);
  // pull-down interno: la patita queda en 0 cuando
  // el boton esta suelto, sin necesitar resistencia externa
  gpio_pull_down(Boton::patita);
}

void Boton::leer() {
  // guardar como estaba antes de volver a leer
  Boton::anterior = Boton::presionado;

  // gpio_get recibe directo el numero de GP
  // (con pull-down, presionado = 1)
  Boton::presionado = gpio_get(Boton::patita);
}

// metodos
void Boton::presionar() {
  Boton::presionado = true;
  // queda pendiente calcular
  // cuanto rato lleva presionado
}

void Boton::soltar() {
  Boton::presionado = false;
  Boton::duracionPresionado = 0;
}

bool Boton::huboClic() {
  // clic = ahora presionado Y antes suelto
  if (Boton::presionado && !Boton::anterior) {
    Boton::contador++;
    return true;
  }
  return false;
}