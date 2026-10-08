#ifndef LED_H
#define LED_H

#include "pico/stdlib.h"

class Led {

public:
    int patita;
    bool encendido;

    Led(int nuevaPatita);

    void prender();
    void apagar();
    void cambiarEstado();
};

#endif