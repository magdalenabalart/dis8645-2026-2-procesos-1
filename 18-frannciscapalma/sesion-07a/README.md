# sesion-07a

## apuntes sesión

29.09.2026 7a

### clase e instancia

en una clase puede haber más de un constructor 
while true: mientras esto sea verdad, hazlo. esto puede ser un problema cuando queremos que sigan pasando mas cosas porque se va a quedar pegado
class boton {

### atributos
bool presionado=0;
bool normalAbierto=true;
int duracionPresionado=0;
int patita;
int vecespresionado=0;

### constructor 
(se  hacen con paréntesis (), para parámetros. se hacen con murciélagos{})
Botón (int nuevaPatita){
patita=nuevaPatita; //la información fugaz queda guardada en patita, si o si hay que asignarle un valor entero que signifique algo

### métodos 
analocReed y digitalReal (arduino)
void leer(); void actualizar();
para una clase vamos a hacer dos archivos: boton.h y boton.cpp, esto es por cada clase. el .h habra informacion de todo, las delcaraciones, de promesas. y el archivo .cpp va a tomar las promesas y hara algo con ellas, es un archivo grande. un archivo es estructural y el otro de implementación, por ejemplo qué es un botón, y el otro te va a explicar cómo usarlo. ejemplo: .h pastel de choclo, .cpp dos aceitunas, pino, choclo, etc.

#include “Boton.h”
en Boton.h ponemos los constructores y métodos. definir boton.h, tres lineas obligatorias #indef BOTON_H, 
en Boton.cpp tenemos que #incluide boton.h, las cosas no existen, estan en el vacío, están en la clase y para q funcione hay que poner Boton::Boton(), esto va en el constructor
en main.cpp esta todo lo que queremos hacer
no tenemos que saber todo, solo saber las cosas macro y guiarse de documentación ya existente, ser capaces de discriminar la documentación presente 

```cpp
// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// esto lo agregamos para GPIO
// general purpose input output
#include "hardware/gpio.h"

// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();

  // inicializar patita 7
  gpio_init(7);
  // la patita 7 es entrada
  gpio_set_dir(7, GPIO_IN);
  
  // crear Boton
  // que se llama miPrimerBoton
  // con el constructor
  // habia hecho un error
  // que era usar parentesis sin nada
  // que no son necesarios cuando
  // el constructor no tiene parametros
  // Boton miPrimerBoton();
  Boton miPrimerBoton;
  
  while (true) {


—
#ifndef BOTON_H
#define BOTON_H


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


  // constructor
  Boton();


  // metodos
  void presionar();
  void soltar();


};


#endif

—
// Boton.cpp
// implementaciones de la clase


// importar el archivo header
#include "Boton.h"


// constructor
Boton::Boton() {


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



    // leer boton
    bool lectura = gpio_get(7);




    if (lectura) {
     printf("caramba estoy presionado\n"); 
    } else {
      printf("pucha no hay nadie\n"); 
    }


    // digitalRead();


    // if (miPrimerBoton.presionado) {
    //   printf("bacan estoy presionado, pero igual me presiona\n");
    //   printf("o como dice matias, estoy impresionado jaja\n");
    //   miPrimerBoton.soltar();
    // }
    // else {
    //   // cuando no este presionado
    //   printf("no hay nadie presionandome\n");
    //   miPrimerBoton.presionar();
    // }










    // printf("Hello, Wokwi!\n");
    sleep_ms(1000);
  }
}


—
encargo: más botones con más parámetros y mas atributos, complejizar el asunto



## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

Siendo sincera no entendí como se hace, no estaba concentrada en esa clase, voy a averiguar bien y subiré esto más tarde



## lectura

En estas paginas que leí, el autor habla de que Japón, Europa y EEUU se equivocaron en enfocarse en mejorar la calidad de las imagenes en la televisión, porque lo importante es el contenido y la tecnología, ya que esto permite la adaptabilidad y así no tener normas fijas.

"ser digital es poder crecer. Ya de entrada, no tenemos por qué poner todos los puntos sobre las íes. Podemos construir enlaces para futuras expansiones y desarrollar protocolos de modo que unas cadenas de bits puedan informar a las demás sobre sí mismas"

"En un sistema abierto, se compite con la imaginación, no con una llave y una cerradura. Como resultado de esto, se crean un gran número de empresas competitivas y el consumidor puede elegir entre una mayor variedad"

Habla de cómo tener estándares rígidos es un error, también de que cree que la televisión terminará siendo un computador. Y en parte tiene razón ya que esto se ve en las diversas plataformas de videos que hay.
