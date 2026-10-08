# sesion-07a

2026.09.29

## apuntes sesión

### Bloque 9:00 - 10:30

Comenzamos hablando del [código actualizado](https://wokwi.com/projects/476140065507309569) que mandó Aarón al discord durante el fin de semana
`%d` es un placeholder número `int`, `\n` es el salto de línea

Un botón solo tiene dos estados, 0 y 1. Si mantengo apretado el botón, lo lee como "0111111...0" con el cero final siendo cuando dejé de presionar el botón. El código puede leer cuándo (en tiempo) se dejó de presionar el botón, y definir una ventana de tiempo en el que puedo volver a presionar el botón y se defina como un "doble click" (0111111...01111...0)

```cpp
clase Nombre {
    // public permite cambiarlo externamente? 
    // i assume it means the code itself can change it
    // while private makes it so the code can only be read, and not affected
   public:
   // aquí van variables o atributos 
   int variableInt = 0;
   char variableChar = v;
   bool variableBool = true;

   Nombre(. . .);

   abrir(. . .);
   cerrar(. . .);
}
```

```cpp
// método constructor
// con un parámetro cuantosML
Termo(int, cuantosML) {
    cantidadML = cuantosML;
}
```

I state `cuantosML` as separate from `cantidadML` so I can independently change one parameter, like in line 23, it reads `int cantidadML;` rather than `int cantidadML = 500`

Clase &rarr; Perro / instancia &rarr; Copito

En la misma clase puede haber más de un constructor con los mismos parámetros

`while (true)` is basically Arduino's `void loop()`

`} else {` &rarr; "E.O.C" (En Otro Caso)

`%.1f` % &rarr; placeholder, f &rarr; float, .1 &rarr; return one (1) decimal

(random reminder to myself: it is BACKSLASH N `\n`, **NOT** SLASH N `/n`)

`double` has more memory than `float`, but it's not accurate regardless

`sleep_ms(1000);` is like `delay(1000);` in Arduino

```cpp
Class Boton {
    // atributos
    bool presionado = false;
    bool normalAbierto = true;
    uint duracionPresionado = 0;
    int patita;
    uint vecesPresionado = 0;
    char [] nombre;

    // constructor
    Boton(int, nuevaPatita) {
        patita = nuevaPatita;
    }

    // método
    // estos pueden conversar entre si
    // o con los atributos
    // esto es una declaración que va en los archivos .h
    void leer();
    void actualizar();
    
}
```

### Bloque 11:00 - 12:50

Continuando con "método" en el código

Tendremos dos tipos de archivo, .cpp (C++) y .h (header) por cada clase

We'll write some code on WOKWI, utilizamos el template de Pi Pico SDK

SDK &rarr; Software Development Kit

[Código escrito por Aarón en clase](https://wokwi.com/projects/476507507193136129)

![Código WOKWI con botón](./imagenes/wokwi-boton.gif)

Aarón nos dio el task de hacer que funcione con dos botones, y lo logré ::], simplemente agregué `miSegundoBoton` después de `miPrimerBoton` lol

```cpp
#include <stdio.h>
#include "pico/stdlib.h"

// incluir mis archivos
#include "Boton.h"

int main() {

  stdio_init_all();

  // crear Boton
  // que se llame miPrimerBoton
  // con el constructor
  Boton miPrimerBoton(7);
  Boton miSegundoBoton(6);


  while (true) {

    miPrimerBoton.leer();

    if (miPrimerBoton.presionado) {
       printf("bacan, estoy presionado pero igual me presiona\n");
     }
     else {
       // cuando no esté presionado
       printf("no hay nadie presionandome\n");
     }
  
    miSegundoBoton.leer();

    if (miSegundoBoton.presionado) {
       printf("ahora yo estoy presionado\n");
     }
     else {
       // cuando no esté presionado
       printf("no hay nadie presionandome tampoco\n");
     }

    sleep_ms(1000);
  }
}
```

![Simulación con dos botones](./imagenes/dos-botones.gif)

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.

Lo que decidí hacer para el segundo botón, fue agregarle un contador. Mi idea fue que al presionar el segundo botón, el botón dice algo como "me presionaron n veces"

### Boton.h

Como atributo, añadí la línea `uint8_t vecesPresionado = 0;`. Opté por usar `uint8_t` en vez de `int` porque un contador si o si es números enteros positivos, y ya que solo quise probar con una cantidad pequeña en cuanto a cuántas presiones iba a leer antes de reiniciarse, 8 bit fue suficiente

Para métodos, añadí un auto-reset. `void reiniciarContador();` para hacer que el botón reinicie el contador por cuenta propia, en lugar de algún input externo al botón

### Boton.cpp

En la sección de `void Boton::leer() {` añadí un boolean para recordar el estado anterior del botón `bool estabaPresionado = Boton::presionado;`

Luego está la línea escrita durante la clase en la que lee el estado actual del botón, después de esta añadí el contador en sí, que lea cada presión del botón como una instancia individual

```cpp
if (Boton::presionado && !estabaPresionado) {
  Boton::vecesPresionado++;
}
```

En estas líneas tuve que usar el operador NOT ( ! ) para que lo lea como "si el botón está presionado ahora y NO estaba presionado antes"

Y en los métodos, hice que el contador pueda ser reiniciado a cero

```cpp
void Boton::reiniciarContador() {
  Boton::vecesPresionado = 0;
}
```

### main.cpp

Finalmente, solo quedó incluir estos cambios en el código principal. Durante la clase, dupliqué el botón (miSegundoBoton) e hice que diera un diálogo aparte al ser presionado, así podía diferenciar entre cuando miPrimerBoton y miSegundoBoton están siendo presionados

En el `printf` del segundo botón presionado, cambié mi indicador textual de que está siendo presionado a que directamente diga cuántas veces lo han presionado

```cpp
if (miSegundoBoton.presionado) {
  printf ("me presionaron %d veces\n",
  miSegundoBoton.vecesPresionado);
}
```

Luego al final de `while(true)`, escribí que el contador se reinicie al llegar a 5 presiones, una cantidad pequeña para fácilmente asegurarme que el código esté funcionando as intended

```cpp
if (miSegundoBoton.vecesPresionado >= 5) {
  printf("me presionaron 5 veces, me reinicio\n");
  miSegundoBoton.reiniciarContador();
}
```

2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

## lectura
