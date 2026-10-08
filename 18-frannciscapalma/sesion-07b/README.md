# sesion-07b

## apuntes sesión

06.10.26 7b
apuntes 
clase lucecita 


encendido (si/no)
resumido


umbral (hacia arriba encendido, hacia abajo apagado)


brillo (255-0)


parpadeo ->tiempo


LuzNavidad = Lucecita[100];
[1
0
1
0
1
0]


color = {rojo, verde, azul


EspantaCuco
int precio;
Lucecita espantada;
Sensor lumínico;


Clase Helado{
}int precio
cremosidad


mandar por discord fotos de perillas y botones para poder programarlos
microcontroladores y salidas 

ejemplo en woki: 

#### archivo main.cpp

```cpp
// hay 3 elementos
// lucecita
// perilla
// pulsador

// lucecita necesita R de 220
// perilla necesita nada
// pulsador necesita R de 10k

// entradas
// o sensores
// perilla - posicion rotacional / giro
// pulsador - si o no hay presion

// salidas
// o actuadores
// lucecita

// ya pero y?

// pulsador: prender y apagar todo
// potenciometro: frecuencia de parpadeo

// lucecita: prender y apagarse
// segun lo que diga boton y perilla

// por lo tanto
// boton tiene dos estados
// prendido y apagado

// perilla va a tener
// una posicion que va a ser
// usada por el sistema
// para impactar en parpadeo lucecita



#include <stdio.h>
#include "pico/stdlib.h"

#include "Boton.h"
#include "Perilla.h"
#include "Lucecita.h"

int main() {
  stdio_init_all();


  // instanciar Boton llamado pulsador
  // a partir de la clase Boton
  // con el parametro
  Boton pulsador(7);

  // lo mismo pero con perilla
  Perilla parpadeo(26);

  Lucecita luz(6);


  while (true) {
    
    // leer perilla parpadeo
    parpadeo.leer();

    // si perilla esta izquierda
    // led apagado
    // si perilla esta derecha
    // led prendido

    if (parpadeo.posicion < 4096 /2) {

      luz.apagar();
    } else {
      luz.prender();
    }

   
    printf("%d\n", parpadeo.posicion);
    sleep_ms(250);
  }
}
```
#### archivo Boton.h

```cpp
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


  // constructor
  Boton(int nuevaPatita);

  // metodos
  void leer();
  void presionar();
  void soltar();

};

#endif
```
#### archivo Perilla.h

```cpp
#ifndef PERILLA_H
#define PERILLA_H

// esto lo agregamos para GPIO
// general purpose input output
#include "hardware/gpio.h"
// la perilla es mas sofisticada
// necesita ADC
// analog to digital conversion
#include "hardware/adc.h"


class Perilla {

  public:

// atributos
int posicion = 0;
int patita;

// constructor
Perilla (int nuevaPatita);

// metodos
void leer();


};


#endif
```
#### archivo Lucecita.h

```cpp
#ifndef LUCECITA_H
#define LUCECITA_H

// esto lo agregamos para GPIO
// general purpose input output
#include "hardware/gpio.h"


class Lucecita {
  public:

  // atributos
  int patita;
  int prendida = false;

  // constructor
  Lucecita(int nuevaPatita);

  // metodos
  void prender();
  void apagar();


};


#endif
```
#### archivo Boton.cpp

```cpp
// Boton.cpp
// implementaciones de la clase

// importar el archivo header
#include "Boton.h"

// constructor
Boton::Boton(int nuevaPatita) {

  // guardar el valor
  Boton::patita = nuevaPatita;

   // inicializar patita
  gpio_init(Boton::patita);
  // la patita es entrada
  gpio_set_dir(Boton::patita, GPIO_IN);
}

void Boton::leer() {
    // leer boton
    Boton::presionado = gpio_get(Boton::patita);
}

// metodos
void Boton::presionar() {
  Boton::presionado = true;
  // queda pendiente calcular
  // cuanto rato lleva presionado
}
  
void Boton::soltar() {
   Boton::presionado = false;
   Boton::duracionPresionado = 0;
}
```
#### archivo Perilla.cpp

```cpp
// importar el archivo header
#include "Perilla.h"

// este prefijo
// Perilla::
// significa dentro de la clase Perilla

// constructor
Perilla::Perilla (int nuevaPatita) {

  // guardar el valor
  Perilla::patita = nuevaPatita;

  // preparar la entrada analoga
  // duda para el futuro
  // es necesario para cada perilla?
  // da lo mismo si cada perilla lo hace?
  // o quizas horror sera un problema?
  adc_init();

  // inicializar patita
  adc_gpio_init(Perilla::patita);


}

// metodos
void Perilla::leer() {

  // seleccionar canal del ADC
  // eso se hace con la patita
  // ese - 26 es porque
  // patita 26 va a ADC0
  // 27 va a ADC1 ec revisar
  adc_select_input(Perilla::patita - 26);

  // leer con ADC
  // y guardar en posicion
  Perilla::posicion = adc_read(); 

}

```
#### archivo Lucecita.cpp

```cpp
// importar el archivo header
#include "Lucecita.h"



// constructor
Lucecita::Lucecita(int nuevaPatita) {
  

  // guardar el valor
  Lucecita::patita = nuevaPatita;

  // inicializar patita
  gpio_init(Lucecita::patita);

  // la patita es salida
  gpio_set_dir(Lucecita::patita, GPIO_OUT);
 
  // partir apagada
  Lucecita::apagar();

}

// metodos
void Lucecita::prender() {


  // hacer true la variable interna
  Lucecita::prendida = true;

  // usar la variable para prender
  // con gpio_put que es de raspico sdk
  gpio_put(Lucecita::patita, true);


}

void Lucecita::apagar() {

   // hacer false la variable interna
  Lucecita::prendida = false;

  // usar la variable para prender
  // con gpio_put que es de raspico sdk
  gpio_put(Lucecita::patita, false);
}
```

## encargos

## lectura
