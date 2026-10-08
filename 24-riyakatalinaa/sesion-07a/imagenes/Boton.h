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

  // atributos nuevos para el LED
  // -1 significa que este boton no tiene LED
  int patitaLed = -1;
  bool ledEncendido = false;


  // constructor
  Boton(int nuevaPatita);

  // metodos
  void leer();
  void presionar();
  void soltar();

  // metodos nuevos para el LED
  void configurarLed(int nuevaPatitaLed);
  void encenderLed();
  void apagarLed();

};

#endif