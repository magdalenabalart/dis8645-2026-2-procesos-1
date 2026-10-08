# sesion-07a → 29/09/26

## apuntes sesión

Revisar link mandado el día sabado 

<https://wokwi.com/projects/476140065507309569>

Atributos:
Class nombre{

public:

Variable de atributos → int, bool, char

Construcción:

Nombre(...)
}

Métodos:

abrir (...)

cerrar(...)

---

Ejemplo en clase new: planificar para programar

Class boton {

una clase contiene dos atributos:

Boton.h (resuemn de todo)  → header ( archivo mas pequeño que declara lo que hace) → estructuras

Boton mein.cpp (archivo mas grande que explica como se hace) → implementación 


atributos:

bool presionado = 0 o 1;

boll  normalAbierto = true;

Uint duracionPresionado = 0;

int patita; (acción del constructor)

Uint vecesPresionado = 0;

char [] nombre;

---

Metodo constructor:

Boton (int nuevaPtita) {

patita = nuevaPatita;


Métodos:

void leer ();

void actualizar();

--- 

Proximamente:

//Boton pausa (GP1);

//Boton reproducir(GP3);

//Boton apagar(GP30);

Luego pasamos a programarlo en vivo :)

<https://wokwi.com/projects/476507507193136129>

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.


### Segundo botón (azul)

Seguire el mismo patrón que el botón verde: el botón y GP2 comparten un punto, y desde ese punto una resistencia baja a GND. Con el botón suelto, GP2 lee 0 V. Al presionar, lee 3.3 V.


Conexiones botones: 

Botón verde (GP7)

- Pata de un lado → 3V3 (pin 36) → cable rojo
- Pata del lado opuesto → cable rosado a GP7, y desde ese mismo punto una resistencia → GND (cable negro)


Botón azul (GP2)

- Pata de un lado → 3V3 (pin 36), el mismo pin que usa el verde (cable rojo)
- Pata del lado opuesto → cable amarillo a GP2, y desde ese mismo punto una resistencia → GND (cable negro).

En ambos botones la resistencia actúa como pull-down: botón suelto = 0 V, botón presionado = 3.3 V.

- Para agregar el botón hay que hacerlo desde el main.cpp
- Boton.h y Boton.cpp quedaron igual.


Cosas en las que me equivoque tratando de agregar el botón nuevo 

-Faltaba el ; al final del printf("Hola soy el nuevo boton\n") → linea 33
- El if del botón nuevo quedó fuera del while, por la sangría → linea 18 y 21
- El archivo se llamaba main.c y debía ser main.cpp. C no entiende class, y por eso fallaba toda la compilación, me paso porque hice un archivo nuevo
- Cambios sin guardar hicieron que la simulación corra una versión vieja.


Código final agregado

```cpp
Boton miNuevoBoton(2);
// cree el botón nuevo en GP2

miNuevoBoton.leer();
// dentro del while: lee su estado

if (miNuevoBoton.presionado) {
// dentro del while: imprime el mensaje
  printf("Hola soy el nuevo boton\n");
// al presionar el boton se ve el mensaje
}
```

lo nuevo lo agregue desde la linea 15 hasta el final del código en la linia 39


Eso fue posible gracias a la clase Boton: cada objeto tiene su propio pin y su propio estado, así que agregar otro botón fue crear otro objeto, sin modificar la clase.



## lectura

Libro: A New Program for Graphic Design

Autor: David Reinfurt

El libro está dividido en 3 grandes capítulos.

I. T--Y-P-O-G-R-A-P-H-Y

II. G-E-S-T-A-L-T

III. I-N-T-E-R-F-A-C-E

El autor plantea las bases de lo que significa enseñar diseño gráfico hoy. Introduce la idea de que el diseño no se trata de "estilo" o decoración, sino de sistemas, reglas y tecnología aplicadas a la comunicación.
