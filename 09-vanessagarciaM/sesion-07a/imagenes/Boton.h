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

  // atributos
  bool presionado = false;
  int duracionPresionado = 0;
  int patita;

  // NUEVO: cuantos clics lleva el boton
  int contador = 0;
  // NUEVO: estado de la lectura anterior
  // para saber cuando recien lo apretaron
  bool anterior = false;


  // constructor
  Boton(int nuevaPatita);

  // metodos
  void leer();
  void presionar();
  void soltar();

  // NUEVO: true solo en el instante del clic
  // (pasa de suelto a presionado) y suma al contador
  bool huboClic();

};

#endif