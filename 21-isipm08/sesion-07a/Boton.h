
#ifndef BOTON_H
#define BOTON_H
#include "hardware/gpio.h"


class Boton {

  public:

  // atributos

  bool presionado = false;

  int duracionPresionado = 0;

  int patita;

  // constructor

  Boton(int nuevaPatita);

  // metodos

  void leer();

  void presionar();

  void soltar();

};

#endif



