# sesion-06b

## apuntes sesión
# Comenzamos revisando el encargo

### Ejemplo visto en clase

**Sustancia:** mi termo  
**Cantidad:** 800 ml  
**Cualidad:** blanco, metálico, térmico  
**Relación:** contenedor de té Ceylan  
**Lugar:** favorito conmigo, a la izquierda de mi mano izquierda  
**Tiempo:** ahora, siempre, pronto  
**Posición:**  
**Posesión:** líquido  
**Acción:** mantener el líquido caliente  
**Pasión:** ser llenado y transportado. No tiene una acción propia porque es inerte.

Primero lidiamos con **el qué es** y después con **el cómo se hace**.


# Primeros conceptos de C

`\n` significa **Enter o salto de línea**.

No es lo mismo que trabajar con `chars`.

Costó bastante entender esta parte, principalmente por cómo se relacionan los archivos, las librerías y la forma en que se incluyen dentro del código.

```c
#include <stdio.h>
```

Este archivo está entre `< >`.

Cuando utilizamos los símbolos `< >`, estamos llamando a un archivo que está en otro lugar dentro de las librerías del sistema.

Tiene relación directa con C porque estamos incorporando funciones que necesitamos para poder programar.

En cambio:

```c
#include "pico/stdlib.h"
```

está escrito entre `" "`.

En este caso se indica de manera más directa el lugar donde está el archivo. Cerca de nuestro proyecto existe una carpeta llamada `pico/` y dentro de ella se encuentra `stdlib.h`.

---

# Crear nuestra propia función

Podemos crear funciones propias.

La estructura básica sería:

**tipo + nombre + paréntesis + murciélagos**

Ejemplo:

```c
int prueba() {

    int x = 3;
    int y = 6;

    int resultado = x * y;

    return resultado;
}
```

Esto forma parte de la lógica de diseño **top-down**, donde dividimos un problema en partes más pequeñas.

La función se llama:

```c
prueba()
```

y es de tipo:

```c
int
```

Eso significa que al ejecutarse va a retornar un número entero.

Dentro de la función tenemos dos variables:

```c
int x = 3;
int y = 6;
```

Luego se realiza la multiplicación:

```c
int resultado = x * y;
```

y finalmente:

```c
return resultado;
```

devuelve el resultado.

---

# Función main()

La función principal del programa es:

```c
int main()
```

También es de tipo `int`.

Cuando una función `int` termina, retorna un número entero.

Dentro de `main()` podemos inicializar el Raspberry Pi Pico utilizando:

```c
stdio_init_all();
```

Después podemos crear un ciclo:

```c
while (true) {
```

Esto permite que todo lo que esté dentro de los murciélagos se ejecute continuamente.

Ejemplo completo:

```c
int main() {

    stdio_init_all();

    while (true) {

        printf("%d\n", prueba());

        sleep_ms(250);
    }
}
```

Antes podríamos haber utilizado:

```c
printf("Hello, Wokwi!\n");
```

pero en este caso queremos mostrar el resultado de nuestra función.

Para imprimir un número entero utilizamos:

```c
%d
```

Por eso escribimos:

```c
printf("%d\n", prueba());
```

Aquí estamos tomando el resultado entero de `prueba()` y mostrándolo en pantalla.

Finalmente:

```c
sleep_ms(250);
```

genera una pausa de 250 milisegundos antes de que el ciclo vuelva a comenzar.

---


Nos visita **Rodrigo Toro**.

Muy buena charla :).



# Mini clase

## C++ Classes / Objects

C++ es un lenguaje de programación orientado a objetos.

En C++ muchas cosas están asociadas a **clases y objetos**, junto con sus atributos y métodos.

Por ejemplo, en la vida real un coche puede ser considerado un objeto.

El coche puede tener atributos como:

- peso;
- color.

Y puede tener métodos como:

- conducir;
- frenar.

Los atributos y métodos son básicamente variables y funciones que pertenecen a una clase.

También se les puede llamar **miembros de la clase**.



# ¿Qué es una clase?

Una clase es un tipo de dato definido por el usuario que podemos utilizar dentro del programa.

Funciona como una especie de constructor, molde o **plan maestro para crear objetos**.

Los espacios al escribir el código no siempre son obligatorios, pero utilizarlos correctamente es una buena práctica y hace que el código sea más fácil de leer.

Durante este semestre vamos a trabajar principalmente con:

```cpp
public
```

aunque en programación real no todo funciona de esa forma.

Si algo es `public`, podemos acceder a él y modificarlo.

Si algo es `private`, no podemos modificarlo directamente desde cualquier parte del programa.

Un ejemplo podría ser el RUT: podemos necesitar verlo, pero no necesariamente permitir que cualquiera lo modifique.

---

# Detalle importante de las clases

Cuando terminamos de escribir una clase, después del murciélago de cierre tenemos que agregar un punto y coma:

```cpp
};
```



# Poblar valores de un objeto

Para acceder a los atributos de un objeto usamos un punto.

Por ejemplo:

```cpp
elDeMatias.cantidadML = 800;
```

El punto permite ingresar al objeto `elDeMatias` y asignarle un valor a su atributo `cantidadML`.

También podemos dejar algunos valores inicialmente en `0` o definir valores por defecto.


# C++ Constructors

## Bob el constructor

El constructor es uno de los métodos más importantes dentro de una clase.

Un constructor es un método especial que se llama automáticamente cuando se crea un objeto de una clase.

Para crear un constructor se utiliza **el mismo nombre que tiene la clase**, seguido de paréntesis:

```cpp
Termo()
```

Por ejemplo:

```cpp
class Termo {

public:

    int cantidadML;

    Termo() {
        cantidadML = 800;
    }
};
```

En este caso:

```cpp
Termo()
```

es el constructor.

La gracia del constructor es que podemos agregar una configuración una sola vez dentro de la clase y esa información se puede propagar hacia los distintos objetos o “termos” que creemos después.

Por ejemplo, si todos los termos tienen inicialmente:

```cpp
cantidadML = 800;
```

no necesitamos escribir esa misma línea manualmente cada vez que creamos uno.

Esta misma lógica también puede aplicarse a otras características, por ejemplo rodamientos u otros atributos que queramos definir por defecto dentro de la clase.
## encargo
>bajar una red social e investigar que piensa esa red de mi, cuál es mi algoritmo
(listar 10 categorías que deciden qué y quién eres)"

Mi algoritmo

1. Education
2. Pets
3. Apps
4. Home Improvement
5. Apparel & Accessories
6. News & Entertainment
7. Business Services
8. Video Games
9. Life Services
10. Food & Beverage

Estas son las categorías que tiktok relaciona conmigo según el contenido que veo e interactúo. Algunas sí representan cosas que realmente me gustan, pero no creo que todas estas categorías me definan ni representen completamente quién soy. 
