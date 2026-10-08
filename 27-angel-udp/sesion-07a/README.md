# sesion-07b

29-09-2026

## apuntes sesión

%d: Es un placeholder (marcador de posición) para el número "int".

\n: Salto de línea, o si no, se imprime todo de corrido a la derecha.

Vamos a programar botones y ver los estados en los que pasan de cero a uno por unos instantes; y esa vez que pasan de cero a uno, se puede grabar.

Tendremos una clase que será:

C++
class Nombre {
public:
    // Variables internas (atributos) { int, bool, char }

    // Método constructor
    Nombre(...) {
    }

    abrir(...);
    cerrar(...);
};
O SEA:

ATRIBUTOS

MÉTODO CONSTRUCTOR

MÉTODOS (abrir, cerrar)

![tranquilo se la navega](./imagenes/tranquiloselanavega.jpg)

Class Btotn {

atributos

bool presionado=0;

bool normalAbierto=true;

Uint duracionPresionado=0; (U int permite que este valor sea siempre cero)

int patita;

Uint vecesPresionado=0;

CONSTRUCTOR: BOTON () {} 

Boton (int nuevaPatita){

 patita=nuevaPatita;

METODOS

Boton para (GP1);

Boton reproDICIR (GP3);

bOTON apagar (GP30)

}
👀 🐱

Metodos

void leer()

voidactualizar(); esto es una declaración y va en los archivos .h

vamos a ver una clase Boton.h

Boton.cpp

header

Nuestro MAin va a ser cpp

A todos los archivos.h le vamos a poner el #ifndef, #define, #endif

while true es una manera de pedirle a main que se repita para siempre
y como trata de decir siempre la verdad lo importante es poner algo que siempre sea la verdad osea (true)

¿Como comenta "//" todo con la selección?

y ¿como borra hacia adelante?

finalmente este fue el código:
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


## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

**SOLUCIÓN ENCARGO**

En general quedaron así los ajustes:

**Boton.h**

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

  // Atributos
  bool presionado = false;
  int duracionPresionado = 0;
  int patita;

  // atributo nuevo
  int vecesPresionado = 0;

  // constructor
  Boton(int nuevaPatita);

  // metodos
  void leer();
  void presionar();
  void soltar();

  // metodo nuevo
  void contarPresion();
};

#endif
```
**Boton.cpp**

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

// metodo nuevo
void Boton::contarPresion() {
  Boton::vecesPresionado++;
}
```
**main.cpp**

```cpp
// esto venia en wokwi
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();

  // crear Boton que se llama miPrimerBoton
  // con el constructor
  Boton miPrimerBoton(7);
  Boton segundoBoton(8);
  while (true) {

    miPrimerBoton.leer();
    segundoBoton.leer();

    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    else {
      // cuando no este presionado
      printf("no hay nadie presionandome\n");
    }

    if (segundoBoton.presionado) {
      // cuenta la cantidad de presiones al oprimir el "segundoBoton"
      segundoBoton.contarPresion();
      // imprime el texto con la cantidad de veces presionando el "segundoBoton"
      printf(
        "estilo porta en la suela, llevo %d presiones\n",
        segundoBoton.vecesPresionado
      );
    }
    // es lo que se ve si no se presiona nada
    else {
      printf("tranquilo se la navega\n");
    }

    sleep_ms(100);
  }
}
```

Y acá está el link al wokwi directamente: https://wokwi.com/projects/477107804422557697

2. Los archivos wokwi que descomprimí los coloqué en la carpeta "/imagenes" de este repositorio

## lectura

Comienzo en la pág. 47, donde se sigue explicando el uso de LibreOffice Writer. Además de servir para escribir documentos, también permite cambiar el estilo, el color y el tamaño de las letras, agregar imágenes, gráficos y tablas. También se menciona que puede ayudar a identificar algunos errores, como faltas de ortografía o problemas gramaticales. Finalmente, se explica cómo guardar un documento asignándole un nombre y utilizando la opción de guardar.

Luego, se recomienda guardar el trabajo constantemente, incluso cuando todavía no esté terminado, para evitar perderlo en caso de que ocurra algún problema. También se muestran otros programas que forman parte de LibreOffice, como Base, Calc, Draw, Impress y Math. Cada uno cumple una función diferente, como trabajar con bases de datos, hojas de cálculo, ilustraciones, presentaciones o fórmulas matemáticas.

Se presenta la herramienta Recommended Software, que permite buscar e instalar diferentes programas compatibles con Raspberry Pi. Los programas aparecen organizados por categorías y, si uno tiene una marca de verificación, significa que ya está instalado. También se pueden seleccionar varios programas para instalarlos al mismo tiempo, aunque hay que tener en cuenta el espacio disponible en la tarjeta microSD.

También se explica que es posible instalar o desinstalar programas mediante la herramienta Add/Remove Software. Después se presenta la herramienta Configuración de Raspberry Pi, que sirve para modificar diferentes opciones del sistema y se parece al asistente que aparece cuando se configura la Raspberry Pi por primera vez.

En la pág. 51 se explican algunas de las opciones que se pueden cambiar desde esta herramienta. Por ejemplo, se puede modificar la contraseña, el nombre de la Raspberry Pi dentro de la red, algunas opciones de la pantalla y la configuración regional. También existen opciones relacionadas con interfaces, rendimiento y localización, aunque varias de ellas no es necesario cambiarlas si no se sabe exactamente para qué sirven.

Finalmente, en las pág. 52 y 53 se explica cómo apagar correctamente la Raspberry Pi. No es recomendable simplemente desconectar el cable, ya que el sistema puede estar trabajando con archivos en ese momento y esto podría causar problemas o incluso hacer que algunos datos se pierdan. Para apagarla correctamente se debe utilizar la opción Shutdown y esperar hasta que el sistema termine de cerrar todos los programas y archivos.

Diferencia entre Shutdown, Reboot y Logout. Shutdown apaga completamente la Raspberry Pi, Reboot la reinicia y Logout sirve principalmente para cerrar la sesión de un usuario. Se advierte que desconectar directamente el cable sin apagar primero el sistema podría dañar el sistema operativo o provocar la pérdida de archivos.

2 Citas:

1. “Acostúmbrate a guardar tu trabajo, aunque aún no lo hayas terminado”.
 
2. “No tires del cable de Raspberry Pi sin antes apagar el ordenador”.

Pregunta:

¿Por qué desconectar directamente el cable de alimentación de la Raspberry Pi puede provocar problemas en el sistema o la pérdida de archivos?

Referente:

LibreOffice y las herramientas de Raspberry Pi para trabajar con documentos, instalar o desinstalar programas, configurar diferentes opciones del sistema y apagar correctamente la Raspberry Pi.
