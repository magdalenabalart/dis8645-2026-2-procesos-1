# sesion-07a

## apuntes sesión

%d (d es número (int) ) place holder 

\n salto de línea 

para programar un botón 

nos interesa cuando pasa de 0 a 1

presionar o soltar 

filtrar las funciones para darle sentido 

si amamos los pingüinos, redactamos bien los prompt (orden y diagramas de flujo)

estructura macro 

class 

nombre 

murciélago

public:
+ (int, bool, char) - variables, atributos 
+ método constructor 
+ métodos - es como decir función dentro de una class 

```cpp
// declaracion de clase Termo
class Termo {
  // palabra clave public
  // la usaremos este semestre
  public:
    // atributos de la clase
    // (variables internas)
    bool existencia = true;
    bool abierto = false;
    int posicion = 0;
    int cantidadML;
    float temperatura = 100.0;
    int rodamientos = 5;


    // metodo constructor
    // con un parametro cuantosML
    Termo(int cuantosML) {
      cantidadML = cuantosML;
    }
   
    // metodos para abrir y cerrar
    void abrir() {
      abierto = true;
    }
    void cerrar() {
      abierto = false;
    }


    // metodo para enfriar
    void enfriar () {
      temperatura = temperatura - 0.7;
    }


};
```

while true: mientras esto sea verdad, hazlo. es una decisión de diseño

else e.o.c en otro caso 

.%: place holder 

f: float - mentira - aproximación rara - ruido 

int: verdad 

double: mayor resolución, existe el doble de lo que hay en un float

### clase de botones 

## Class Boton {

### atributos

(todos tienen el atributo llamado presionado)

bool presionado = 0;

bool normalAbierto = true;

Uint duraciónPresionado = 0;

int patita; (agregarlo al constructor ya que se hace una vez)

Uint vecesPresionado = 0;

char [ ] nombre; 

### constructor 

Boton (int patita) { 

patita=patita;

mejor cambiar el nombre en el constructor para evitar confusiones 

Boton (int nuevaPatita) { 

patita=nuevaPatita;
 
### métodos 

conversar entre ellos o con los atributos 

__|---|__ presionar 

los métodos son un envoltorio 

void leer (); 

actualizar (); 

main.cpp
+ en main está la estructura general 

Boton.h
+ h: header
+ 
una clase implica dos archivos 

archivos h y archivos cpp, por cada clase 

en el h hay un resumen de todo, una declaración

es más pequeño 

en cpp un archivo grande, donde explica como se hace 


boton.h 
+ declaraciones de la clase boton 

boton.cpp
+ implementaciones de la clase 

ifndef: significa "si no está definido" (if not defined) y se usa para la compilación condicional. 

```cpp
#ifndef BOTON_H
#define BOTON_H 
```
no pueden dos cosas llamarse igual 

:: para indicar que está dentro de la clase
 
```cpp
// constructor
Boton::Boton() {
}


// metodos
void Boton::presionar() {
}
```
si el constructor no tiene parámetros, no van los paréntesis, sólo en este caso

error que se cometió 

Boton miPrimerBoton();

positivo es 3V3 en este caso 

ejemplo botón 

ejemplo-2029-09-29-clases - Wokwi ESP32, STM32, Arduino Simulator 

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.

mi ejemplo: <https://wokwi.com/projects/477154643509297153>

2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.
+ los subí en la carpeta imágenes

## lectura

> en estas páginas del libro se habla de cómo la tecnología de hoy intenta ocultar las pantallas y las interfaces para que ni nos demos cuenta de que están ahí. pero los artistas y escritores digitales hacen todo lo contrario, si no que usan el hackeo, los errores y la incomodidad para romper esa ilusión y hacernos conscientes del código y del aparato que estamos usando. esto lo muestran con ejemplos súper interesantes, como poemas que reaccionan cuando tocas la pantalla del ipad, programas de hipertexto modificados para esconder historias secretas, y hasta obras que se autodestruyen, hechas con disquetes y libros que se van borrando solos.

**cita 1**

"Tanto los ejemplos antiguos como los contemporáneos de literatura digital basada en código desatan los mecanismos de la computadora, no solo al hacer visible el código o la parte posterior normalmente invisible de nuestros dispositivos digitales, sino al convertir el propio código en la obra de literatura." (Emerson, p. 31)

**cita 2**

"[...] en total oposición al intento de la industria informática por naturalizar la interfaz hasta el punto de la invisibilidad, Jodi hace que la interfaz sea confusa, no familiar, incómoda y disfuncional."  (Emerson, p. 36)


