// Led.cpp
// implementaciones de la clase

// importar el archivo header
#include "Led.h"

// constructor
Led::Led(int nuevaConexionLed) {

  // guardar el valor
  // el doble : es para hacer un llamado dentro de un elemento
  conexionLed = nuevaConexionLed;

  
    // inicializar gpio
   gpio_init(conexionLed);
   // gpio es salida
   gpio_set_dir(conexionLed, GPIO_OUT);
}

void Led::encenderLed() {
 
 //el 1 corresponde a 3.3v
 // en IDE se describia HIGH
  gpio_put(conexionLed, 1); 

  //alteramos la variable que nos indica si un led enciende o no
  encendido = true;
}

void Led::apagarLed(){

  // 0 equivale a no haber señal
  // en IDE se describia LOW
  gpio_put(conexionLed, 0);

  //la variable encendido se vuelve falsa
  encendido = false;
}

void Led::oscilarLed() {

//calcula cuanto tiempo ha pasado desde que
//inicio el microcontrolador
//to_ms_since_boot es una funcion que devuelve el tiempo en milisegundos
//get_absolute_time es una funcion que devuelve el tiempo absoluto
uint32_t tiempoActual = to_ms_since_boot(get_absolute_time());

// si ha pasado mas tiempo que el que se definio en duracionEncendido
if (tiempoActual - ultimoCambio >= 500) {

//! encendido es una variable que nos indica si el led esta encendido o apagado
encendido = gpio_get_out_level(conexionLed);
//! corresponde a una negacion
gpio_put(conexionLed, !encendido);

ultimoCambio = tiempoActual;

}
