// Led.h
// declaraciones de la clase Led

#ifndef LED_H
#define LED_H

// esto lo agregamos para GPIO
// general purpose input output
#include "hardware/gpio.h"

// definir clase Boton
class Led {

  // todo publico
  // nada de andar privatizando
  public:

  // atributos
  bool encendido = false;
  int duracionEncendido = 0;
  int patita;

 // constructor
  Led(int nuevaPatita);

  // metodos
  void encender();
  void apagar();

};
          
#endif