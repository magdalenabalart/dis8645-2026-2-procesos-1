#include "Led.h"

Led::Led(int nuevaPatita) {
    patita = nuevaPatita;
    encendido = false;

    gpio_init(patita);
    gpio_set_dir(patita, GPIO_OUT);
}

void Led::prender() {
    gpio_put(patita, 1);
    encendido = true;
}

void Led::apagar() {
    gpio_put(patita, 0);
    encendido = false;
}

void Led::cambiarEstado() {
    if (encendido) {
        apagar();
    } else {
        prender();
    }
}