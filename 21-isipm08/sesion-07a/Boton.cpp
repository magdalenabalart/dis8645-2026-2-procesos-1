#include "Boton.h"

// constructor

Boton::Boton(int nuevaPatita) {

  // guardar el valor

  Boton::patita = nuevaPatita;

  // inicializar patita

  gpio_init(Boton::patita);

  // definir la patita como entrada

  gpio_set_dir(Boton::patita, GPIO_IN);

  // Deshabilitar Pull-Up / Pull-Down internos de la Pico

  // porque ya estamos usando resistencias Pull-Down físicas externas en la protoboard/Wokwi

  gpio_disable_pulls(Boton::patita);

}

void Boton::leer() {

    // gpio_get devuelve 1 (true) cuando recibe 3.3V (botón presionado)

    // y 0 (false) cuando la resistencia lo lleva a GND (en reposo)

    Boton::presionado = gpio_get(Boton::patita);

}

// metodos

void Boton::presionar() {

  Boton::presionado = true;

  // queda pendiente calcular cuanto rato lleva presionado

}

void Boton::soltar() {

   Boton::presionado = false;

   Boton::duracionPresionado = 0;

}