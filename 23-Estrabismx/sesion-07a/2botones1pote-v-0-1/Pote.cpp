// Pote.cpp
// implementaciones de la clase

// importar el archivo header
#include "Pote.h"
#include "hardware/adc.h" // biblioteca ADC

// constructor
Pote::Pote(int nuevaConexion, int nuevoPinADC) {

  // guardar el valor
  // el doble : es para hacer un llamado dentro de un elemento
  Pote::conexion = nuevaConexion;
  Pote::pinADC = nuevoPinADC;
    // inicializar ADC
    // Analog to Digital Converte
    adc_init();

    //preparar GPio para entrada analoga
    adc_gpio_init(conexion);

    //seleccionar canal del ADC
    adc_select_input(pinADC);
    // debemos añadir esa variable a nuestra Pote.h

}

void Pote::leerPote() {
    // leer un pote
    Pote::valorPote; = adc_read(); 
}