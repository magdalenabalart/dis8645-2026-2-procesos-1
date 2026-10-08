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
  // resistencia hacia abajo: si nadie presiona, lee 0
  gpio_pull_down(Boton::patita);
}

void Boton::leer() {
    // leer boton
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

// metodos nuevos para el LED
void Boton::configurarLed(int nuevaPatitaLed) {

  // guardar el valor
  Boton::patitaLed = nuevaPatitaLed;

  // inicializar patita del LED
  gpio_init(Boton::patitaLed);
  // la patita del LED es salida
  gpio_set_dir(Boton::patitaLed, GPIO_OUT);
}

void Boton::encenderLed() {
  // solo si el boton tiene LED configurado
  if (Boton::patitaLed >= 0) {
    gpio_put(Boton::patitaLed, true);
    Boton::ledEncendido = true;
  }
}

void Boton::apagarLed() {
  // solo si el boton tiene LED configurado
  if (Boton::patitaLed >= 0) {
    gpio_put(Boton::patitaLed, false);
    Boton::ledEncendido = false;
  }
}