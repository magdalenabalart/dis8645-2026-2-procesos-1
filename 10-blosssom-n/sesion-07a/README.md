# sesion-07a

## apuntes sesión

Llegamos (aunque de nuevo llegue tarde im so sorry) retomando el código de Wokwi y empezamos a meternos más con las clases, instancias y cómo se organiza todo esto en distintos archivos.

Primero vimos que una clase puede tener datos internos, que serían los atributos, y acciones que puede realizar, que serían los métodos.

Por ejemplo, una clase podría ser Perro y una instancia podría ser Copito. Si hacemos varias instancias de la misma clase, cada una sigue teniendo la misma estructura, pero puede guardar datos diferentes.

```cpp
class Nombre {

public:

  int numero;
  bool pregunta;
  char caracter;

};
```

Por ahora estamos trabajando todo como public, así podemos acceder a los atributos y métodos desde fuera de la clase.

### constructor

Después nos metimos con el constructor, que es el que se encarga de recibir información cuando creamos una instancia.

Tiene el mismo nombre de la clase:

```cpp
Boton(int nuevaPatita) {
  patita = nuevaPatita;
}
```

Entonces si hacemos:

```cpp
Boton pausa(A0);
```

Boton es la clase, pausa es la instancia y A0 es el valor que le estamos pasando al constructor.

También pueden existir varios constructores dentro de una misma clase, dependiendo de los parámetros que necesitemos.

Algo importante es que el nombre del parámetro del constructor puede ser distinto al nombre del atributo, porque es como el dato temporal que estamos recibiendo para después guardarlo.

### métodos

Los métodos son las cosas que puede hacer la clase.

Por ejemplo:

```cpp
void abrir();
void cerrar();
void enfriar();
```

En el caso de Boton vimos:

```cpp
void leer();
void actualizar();
```

Los métodos pueden utilizar y modificar los atributos de la misma clase.

También vimos que void significa que ese método hace algo, pero no devuelve un valor.

### Boton

Después empezamos a usar todo esto para crear nuestra propia clase Boton.

La idea es que cada botón pueda tener sus propios datos, en vez de tener todas las variables separadas por fuera.

```cpp
class Boton {

public:

  bool presionado = false;
  bool normalAbierto = true;
  uint duracionPresionado = 0;
  int patita;
  uint vecesPresionado = 0;
  char nombre[20];

  Boton(int nuevaPatita);

  void leer();
  void actualizar();

};
```

Acá, por ejemplo, patita guarda en qué pin está conectado el botón y presionado guarda si está presionado o no.

uint lo usamos para datos que no deberían ser negativos, como la cantidad de veces que se ha presionado un botón.

### cómo se separa el código

Para trabajar con una clase tenemos el archivo .h y el .cpp.

El .h es el header y ahí dejamos declarada la estructura de la clase, sus atributos y métodos.

El .cpp es donde escribimos cómo funcionan realmente esos métodos.

Entonces:

```text
Boton.h: qué tiene la clase
Boton.cpp: cómo funciona
main.cpp: usamos la clase y creamos las instancias
```

### algunas cosas que seguimos usando

while (true) es parecido al loop() de Arduino:

```cpp
while (true) {

}
```

Como siempre es true, lo que está dentro se repite constantemente.

También seguimos usando printf.

```cpp
printf("Hola mundo\n");
```

El \n sirve para hacer un salto de línea.

Y cuando queremos insertar un número usamos un placeholder, por ejemplo:

```cpp
printf("entre 6 y 7, el mayor es: %d\n", cualEsMayor(6, 7));
```

%d deja el espacio para que aparezca el número que entrega la función.

Para los decimales:

```cpp
printf("%.1f grados\n", temperatura);
```

.1 significa que queremos mostrar un decimal y f corresponde al float.

### int, float y sleep

int sirve para números enteros y float para números con decimales.

Los float son una aproximación, así que no todos los decimales se pueden representar de manera completamente exacta.

También vimos sleep y delay, que sirven para hacer pausas. El problema es que mientras el programa está esperando puede dejar de atender otras cosas, así que no conviene depender demasiado de ellos.


## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.



## ¿Qué hice?

El primer botón ya venía hecho en el ejemplo que vimos con el profe, así que partí desde ese código y trabajé sobre él.

El encargo era agregar un segundo botón en la simulación, crear una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase, y hacer que este segundo botón hiciera algo diferente al primero.



### Segundo botón

Primero agregué una segunda instancia:

```cpp
Boton miSegundoBoton(8);
```

El miPrimerBoton(7) ya estaba en el código del profe, así que yo solamente agregué el segundo y lo conecté a otra patita.

Después hice que los dos botones se leyeran dentro del while:

```cpp
miPrimerBoton.leer();
miSegundoBoton.leer();
```

Así cada uno puede saber si está presionado.



### Atributo nuevo

En Boton.h agregué:

```cpp
int cantidadPresiones = 0;
```

Esto sirve para guardar la cantidad de presiones que ha contado el segundo botón.

Al principio parte en 0 y después va aumentando.



### Método nuevo

También agregué:

```cpp
void contarPresion();
```

Y en Boton.cpp hice que ese método sumara uno:

```cpp
void Boton::contarPresion() {

  Boton::cantidadPresiones = Boton::cantidadPresiones + 1;

}
```

O sea, cada vez que se llama a contarPresion(), cantidadPresiones aumenta en 1.

### ¿Qué hace diferente el segundo botón?

El primer botón mantiene lo que ya hacía el ejemplo del profe: cuando está presionado, muestra un mensaje.

El segundo botón, en cambio, cuenta sus presiones y muestra ese número en el monitor serial:

```cpp
if (miSegundoBoton.presionado) {

  miSegundoBoton.contarPresion();

  printf("soy el segundo boton\n");

  printf(
    "me han contado %d presiones\n",
    miSegundoBoton.cantidadPresiones
  );

}
```

Entonces si lo presiono, aparece algo como:

```text
soy el segundo boton
me han contado 1 presiones
```

Y si sigue detectando que está presionado, el número continúa aumentando.

El segundo botón funciona de una manera distinta al primero. Como el programa revisa el estado del botón cada 500 ms, tenemos que mantenerlo presionado para que lo vaya detectando. Mientras sigue presionado, el método contarPresion() aumenta cantidadPresiones.

### Simulación

En diagram.json agregué el segundo botón y otro resistor.

Quedó:

```text
primer botón → GP7
segundo botón → GP8
```

También dejé el segundo botón de otro color para poder distinguirlo en la simulación.



## lectura

### (PAG 60-75)

En estas páginas siguen apareciendo ejemplos de poesía hecha con computadores, pero ahora se habla harto de programas que toman palabras o fragmentos y los van mezclando para crear textos nuevos.
Me llamó la atención que algunos programas funcionan con reglas súper específicas. Por ejemplo, pueden elegir palabras de distintas categorías y después combinarlas para formar poemas. También aparecen obras que usan el azar, donde el resultado depende de las combinaciones que haga el programa.
Después aparece John Cage, que usa el azar como parte del proceso creativo, incluso usando métodos como el I Ching. También se habla de otros autores que trabajan con programas para cortar, ordenar o cambiar textos que ya existían.
Otra cosa que aparece es que algunos programas permiten que el usuario modifique las palabras o las bases de datos, entonces no siempre el resultado es exactamente el mismo. Hay varios ejemplos donde los textos terminan siendo medio raros o difíciles de entender, pero justamente esa es parte de la idea.

#### citas

“its pieces become more abstract and challenging to read in any conventional sense” (p. 69)


“words, phrases, sentences, and other linguistic elements are treated like the tones or intervals of scales” (p. 71)
