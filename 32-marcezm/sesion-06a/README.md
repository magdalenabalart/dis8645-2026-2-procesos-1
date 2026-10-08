# sesion-06a
Martes 22 de septiembre

## apuntes sesión

### Array
Un array es un arreglo que permite guardar varios datos dentro de una misma estructura

```cpp
int edades[5];
````
Los `[]` indican que estamos trabajando con un arreglo

### Tipos de datos
Antes de crear una estructura es importante categorizar los datos, porque cada tipo de dato sirve para almacenar cosas diferentes.
- `bool` → bolsillo pequeño, guarda true o false
- `int` → guarda números enteros
- `float` → guarda números con decimales y sirve para ciertos cálculos
- `uint` → unsigned integer, es decir, un entero sin signo

Por ejemplo:
```cpp
bool estado = true;
int duracionPresionado = 5;
float altura = 1.75;
uint cantidad = 10;
```

**Recordatorio:**
- `int`: tiene escalones completos
- `float`: puede tener valores decimales

### Clases
Una clase ayuda a generar jerarquías y estructuras en el código, evitando tener que hacer todo manualmente, dato por dato

Ejemplo:
```cpp
class Estudiante {
    
};
```
La palabra `class` indica que estamos creando una clase

**Importante:** el nombre de la clase comienza con mayúscula.
Ejemplo: `Estudiante`, `Perrite`, `Poodle`

## Atributos y métodos
Dentro de una clase podemos tener **atributos** y **métodos**

### Atributos
Los **atributos son las variables**

Representan características o datos de aquello que estamos describiendo

Por ejemplo, en una clase `Perrite`:

```cpp
bool hambre = true;
bool durmiendo = true;
pelaje = #000000;
```
Estos datos describen al objeto

### Métodos
Los métodos son las funciones y representan acciones que puede realizar el objeto

```cpp
ladrar();
comer();
jugar();
portarseMal();
```
*Recordatorio*

| Programación | En humano                           |
| ------------ | ----------------------------------- |
| Variable     | Dato                                |
| Atributo     | Característica                      |
| Función      | Acción                              |
| Método       | Acción que puede realizar el objeto |

#### Relación entre atributos y métodos
Los atributos y métodos **no tienen que estar relacionados uno a uno**

Pueden existir atributos sin un método específico asociado y métodos que utilicen varios atributos

Son relaciones **bidireccionales y dependientes de la estructura de la clase**

### Parámetros en los métodos
Dentro de los métodos podemos agregar información entre paréntesis y esto se llama parámetro

Por ejemplo:

```cpp
ladrar(int volumen, int frecuencia);
```
En este caso, el método `ladrar()` recibe dos parámetros:
- `volumen`
- `frecuencia`

Los parámetros permiten especificar cómo queremos que se realice una acción

#### Ejemplo: clase Perrite
Podemos representar un perro mediante una clase:

```cpp
class Perrite {

    // atributos
    bool hambre = true;
    bool durmiendo = true;
    pelaje = #000000;

    // métodos
    ladrar();
    comer();
    jugar();
    portarseMal();

};
```
La clase funciona como una estructura que define qué características y acciones puede tener un objeto.

#### Herencia
Permite que una clase pueda heredar características y métodos de otra clase

Por ejemplo:

```cpp
class Poodle : Perrite {

    bool molestando = true;

};
```
En este caso, `Poodle` puede heredar lo que tiene `Perrite`

La idea es que una clase más específica puede partir de una clase más general

### Ejemplo

```text
Perrite
   ↓
Poodle
```
`Perrite` sería la clase general y `Poodle` una clase que hereda de ella

### Clase e instancia
Una clase funciona como un molde, mientras que una instancia es un objeto creado a partir de esa clase.

Por ejemplo:

| Clase    | Instancia |
| -------- | --------- |
| `Poodle` | `Copito`  |
| `Poodle` | `Pelusa`  |

```cpp
Poodle copito;
Poodle pelusa;
```
Los dos objetos pertenecen a la clase `Poodle`, pero son instancias diferentes

Podemos tener varios objetos de una misma clase:

```
Perrites =
{
    copito,
    pelusa
}
```
Y luego utilizar sus métodos:

```cpp
perrito.ladrar();
```
*También podemos utilizar una clase para representar características y acciones de una persona*

- Atributos:

```cpp
bool descansada = false;
bool hidratada = true;
char[] miPerrita = 'pelusa';
```

- Métodos:

```cpp
tomarTe();
dormir(calidad);
```
En este ejemplo:

- `descansada` e `hidratada` son atributos.
- `tomarTe()` y `dormir()` son métodos.
- `calidad` es un parámetro del método `dormir()`.

## encargos

### Categorías de Arisóteles
- **Sustancia:** Lo que existe por sí mismo (ejemplo: un humano, un perro). Es la base de todo lo demás.
- **Cantidad:** El tamaño, número o medida (ejemplo: dos metros, tres kilos).
- **Cualidad:** Las propiedades o características (ejemplo: rojo, caliente, inteligente).
- **Relación:** La comparación o referencia a otra cosa (ejemplo: mayor que, padre de).
- **Lugar:** El sitio o espacio donde se está (ejemplo: en la casa, en Madrid).
- **Tiempo:** El momento o duración (ejemplo: ayer, a las tres).
- **Posición:** La postura o disposición del cuerpo (ejemplo: sentado, de pie).
- **Posesión (o Hábito):** Lo que se tiene o porta (ejemplo: calzado, armado).
- **Acción:** El acto que se ejerce sobre algo (ejemplo: cortar, calentar).
- **Pasión:** El acto sufrido o recibido (ejemplo: ser calentado, ser visto).

### Encargo objeto celular
- sustancia: iPhone marce
- cantidad: 1
- cualidad: blanco, 6,1 pulgadas, capacidad de 64 GB
- relación: herramienta para uso general
- lugar: conmigo
- tiempo: siempre
- posición: con la pantalla hacia el frente
- posesión: tiene una funda gris
- acción: encendido
- pasión: esta siendo sostenido

## lectura
