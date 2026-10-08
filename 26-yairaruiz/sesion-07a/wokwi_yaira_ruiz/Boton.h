#ifndef BOTON_H
#define BOTON_H

#include "hardware/gpio.h"

class Boton {

  public:

  // atributos
  bool presionado = false;
  int duracionPresionado = 0;
  int patita;
  char nombre[20];

  // constructor
  Boton(int nuevaPatita);

  // métodos
  void leer();
  void presionar();
  void soltar();
  void mostrarNombre();

};

#endif