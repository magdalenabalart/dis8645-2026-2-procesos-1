# sesion-07a

## apuntes sesión


### antes de programar

- primero se hace la interfaz.
- después se arma un diagrama de flujo, con las cosas bien definidas y en orden. recién ahí se escribe el código.


- **clase:** el molde general. ejemplo: `perro`.
- **instancia:** un objeto concreto hecho con ese molde. ejemplo: `copito`.
- se pueden crear varias instancias de la misma clase, cada una con sus valores internos distintos. por ejemplo, dos termos: uno con 500 ml y otro con 350 ml, cada uno con su propia temperatura.

### estructura macro de una clase

la regla general es esta:

```cpp
class Nombre {
  public:
    // atributos  (int, bool, float...)

    // constructor
    Nombre(...) {
    }

    //
    void abrir(...);
    void cerrar(...);
};   //la clase termina con punto y coma
```

- el nombre de la clase empieza con mayúscula.
- `public:` es una palabra clave que vamos a usar todo el semestre.
- los **atributos** son las variables de la clase.
- los **métodos** son sus funciones.


1. `class` + nombre de la clase
2. atributos / variables de la clase
3. método constructor
4. métodos

### ejemplo: clase `Termo`

```cpp
// declaración de la clase Termo
class Termo {
  public:
    // atributos 
    bool existencia = true;
    bool abierto = false;
    int posicion = 0;
    int cantidadML;
    float temperatura = 100.0;
    int rodamientos = 5;

    // método constructor
    Termo(int cuantosML) {
      cantidadML = cuantosML;
    }

    // método 
    void enfriar() {
      while (true) {
        temperatura = temperatura - 0.7;
        sleep_ms(1000);   // pausa: se actualiza cada un segundo
      }
    }
};
```

### sobre el constructor

- se ejecuta al crear la instancia y deja los valores iniciales.
- una misma clase puede tener **más de un constructor** (con distintos parámetros).

### sobre `enfriar()` y el `while (true)`

- `while (true)` significa "mientras esto sea verdad, hazlo". como `true` siempre es verdadero, el ciclo no termina nunca.
- eso congela el programa en esa tarea: no pasa a ninguna otra, porque algo ocurre para siempre. es una decisión de diseño.
- en cada vuelta toma la temperatura y le resta 0.7.

### `if` / `else`

`else` es "en cualquier otro caso". sirve para decidir entre dos opciones:

```cpp
if (elDeCata.abierto) {
  printf("el termo de cata está abierto\n");
} else {
  printf("el termo de cata está cerrado\n");
}
```

así el programa imprime que el termo de cata está abierto o cerrado, según el valor de su atributo.

### imprimir con `printf`

revisando el código de ejemplo de la semana pasada, aparece esto:

```cpp
printf("hola mundo\n");
```

antes de cerrar las comillas está `\n`, que corresponde a un salto de línea. cumple una función parecida a `Serial.println()` en arduino ide, que también baja a la línea siguiente después de imprimir.

#### `%d`

 `%d` es un número entero

 `%.xf`: añadir decimales


### `float` vs `double`

- `float`: aproximación, de menor resolución.
- `double`: mayor rango y precisión.



### el constructor


```cpp
Boton(int nuevaPatita) {
  patita = nuevaPatita;
}
```

### instancias

```cpp
Boton pausa(GP1);
Boton reproducir(GP3);
Boton aparecer(GP30);
```

cada botón es una instancia distinta.

## archivos

- `.ino` (arduino) vs `.cpp` (c++): en c++ se separa en dos archivos, uno corto y uno largo.
- `main.cpp`: el programa principal.
- `Boton.h` (header, encabezado): es el resumen de la clase. muestra todo lo que se puede leer y usar de los botones:


## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.
2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

### segundo botón en wokwi (pseudocódigo)

proyecto base: `ejemplo-2026-09-29-clases` (raspberry pi pico, pico sdk).

### qué hace el botón nuevo

el botón azul **cuenta cuántas veces lo presionan** y lo muestra en pantalla. el botón verde solo avisa si está presionado o no.

### atributo nuevo (`Boton.h`)

```
clase Boton:
    atributos que ya tenía:
        presionado, duracionPresionado, patita

    atributos nuevos:
        vecesPresionado = 0        // el contador de clics
        estabaPresionado = falso   // cómo estaba el botón en la lectura anterior
```

### método nuevo (`Boton.h` y `Boton.cpp`)

```
método contar():
    nuevaPresion = (presionado ahora) Y (NO estaba presionado antes)

    si nuevaPresion:
        vecesPresionado = vecesPresionado + 1

    estabaPresionado = presionado      // recordar para la próxima lectura
    devolver nuevaPresion              // verdadero solo en el instante del clic
```

la condición "ahora sí y antes no" hace que cada clic cuente una sola vez. sin ella, como el programa lee cada 10 ms, un solo clic sumaría decenas de veces.

### segunda instancia (`main.cpp`)

```
crear miPrimerBoton  con patita 7    // el verde, como estaba
crear miSegundoBoton con patita 8    // el azul, nueva instancia
```

### comportamiento distinto (`main.cpp`)

```
repetir para siempre:
    miPrimerBoton.leer()
    miSegundoBoton.leer()

    // botón verde: hace lo mismo de antes
    si miPrimerBoton.presionado:
        imprimir "bacan estoy presionado..."
    si no:
        imprimir "no hay nadie presionandome"

    // botón azul: algo diferente, contar
    si miSegundoBoton.contar() es verdadero:
        imprimir "me han presionado N veces"

    esperar 10 ms
```
para esta parte me basé en el primer ejemplo de clase. lo más difícil fueron las conexiones del hardware

## lectura


