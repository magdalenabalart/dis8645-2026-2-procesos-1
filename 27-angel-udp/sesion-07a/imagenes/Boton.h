#ifndef BOTON_H
#define BOTON_H

// esto lo agregamos para GPIO
// general purpose input output
#include "hardware/gpio.h"


// Boton.h
// declaraciones de la clase Boton


// definir clase Boton
class Boton {

  // todo publico
  // nada de andar privatizando
  public:

  // Atributos
  bool presionado = false;
  int duracionPresionado = 0;
  int patita;

  // atributo nuevo
  int vecesPresionado = 0;

  // constructor
  Boton(int nuevaPatita);

  // metodos
  void leer();
  void presionar();
  void soltar();

  // metodo nuevo
  void contarPresion();
};

#endif