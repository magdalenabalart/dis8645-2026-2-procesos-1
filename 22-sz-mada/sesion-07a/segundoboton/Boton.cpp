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
}

void Boton::leer() {
    // guarda el estado anterior
    bool estabaPresionado = Boton::presionado;

    // leer boton
    Boton::presionado = gpio_get(Boton::patita);

    // si antes no estaba presionado y ahora si,
    // es una presión nueva
    if (Boton::presionado && !estabaPresionado) {
      Boton::vecesPresionado++;
    }
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

void Boton::reiniciarContador() {
  Boton::vecesPresionado = 0;
}