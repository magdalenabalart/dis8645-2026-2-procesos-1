# sesion-07a

## apuntes sesión

## encargos

1. usar el ejemplo base visto en clases <https://wokwi.com/projects/476507507193136129>, agregar un segundo botón en la simulación de hardware, agregar una segunda instancia de la clase Boton, agregarle un atributo y un método a la clase Boton, y hacer que el segundo botón haga algo diferente al primero.

```cpp
#include <stdio.h>
#include "pico/stdlib.h"

// ---------- CLASE BOTON ----------
class Boton {
public:
  int pin;           // pin donde esta conectado
  bool presionado;   // dice si el boton esta apretado o no
  int contador;      // cuenta cuantas veces apreto el boton
  bool anterior;     // guarda si estaba apretado antes

  // esto se hace cuando creo un boton
  Boton(int numeroPin) {
    pin = numeroPin;
    presionado = false;
    contador = 0;
    anterior = false;

    gpio_init(pin);               // prepara el pin
    gpio_set_dir(pin, GPIO_IN);   // dice que el pin va a recibir info
    gpio_pull_down(pin);          // cuando no lo aprieto lee 0
  }

  // revisa si el boton esta apretado
  void leer() {
    presionado = gpio_get(pin);
  }

  // cuenta una vez cada vez que aprieto el boton
  bool contarPresion() {
    bool recienPresionado = false;

    // si ahora esta apretado pero antes no, significa que lo acabo de apretar
    if (presionado && !anterior) {
      contador = contador + 1;
      recienPresionado = true;
    }

    // guardo como estaba el boton para revisarlo en la siguiente vuelta
    anterior = presionado;

    return recienPresionado;
  }
};

// ---------- PROGRAMA PRINCIPAL ----------
int main() {

  stdio_init_all();

  Boton miPrimerBoton(7);    // creo el primer boton en el pin GP7
  Boton miSegundoBoton(8);   // creo el segundo boton en el pin GP8

  while (true) {

    // reviso los dos botones
    miPrimerBoton.leer();
    miSegundoBoton.leer();

    // si aprieto el primer boton muestra un mensaje
    if (miPrimerBoton.presionado) {
      printf("bacan estoy presionado, pero igual me presiona\n");
    }
    else {
      printf("no hay nadie presionandome\n");
    }

    // el segundo boton cuenta cuantas veces lo aprieto
    if (miSegundoBoton.contarPresion()) {
      printf("segundo boton: me han apretado %d veces\n", miSegundoBoton.contador);
    }

    // espera un poquito antes de volver a revisar
    sleep_ms(10);
  }
}
```



2. descargar todos los archivos de wokwi, descomprimir el archivo.zip y subir esa carpeta a tu repositorio en esta sesión.

## lectura

# chapter 1 — the tech model railroad club

### page 14

- "he was not the last administrator to feel the wrath of a hacker thwarted in the quest for access."
- "the computer was called the tx-0, and it was one of the first transistor-run computers in the world."

### vocabulary

- **wrath:** extreme anger.
- **thwarted:** prevented from achieving something.
- **affiliated:** officially connected with something.

---

### page 15

- "the tmrc people were awed. this machine did not use cards."
- "if something went wrong with the program, you knew immediately."

### vocabulary

- **awed:** filled with wonder or admiration.
- **chassis:** a frame that supports equipment.
- **adjoining:** next to or connected to.

---

### page 16

- "you could even modify a program while sitting at the computer. a miracle!"
- "the tmrc hackers, who soon were referring to themselves as tx-0 hackers, changed their lifestyles to accommodate the computer."

### vocabulary

- **canny:** clever and careful.
- **bureaucracy:** a system controlled by rules and officials.
- **nocturnal:** active during the night.

---

### page 17

- "the hackers recruited a network of informers to give advance notice of potential openings at the computer."
- "the interactive nature of the tx-0 was inspiring a new form of computer programming, and the hackers were its pioneers."

### vocabulary

- **benevolent:** kind and helpful.
- **uncharted:** not yet explored.
- **ventures:** risky or exciting activities.

---

### page 18

- "within weeks, he had attained a striking proficiency in programming. he was only twelve years old."
- "deutsch’s comments would turn out to be correct."

### vocabulary

- **proficiency:** a high level of skill.
- **inelegantly:** in an awkward or poorly designed way.
- **brazenly:** boldly and without shame.
- **invariably:** always or almost always.

---

### page 19

- "what hackers had in mind was getting behind the console of the tx-0 much in the same way as getting in behind the throttle of a plane."
- "computing with the tx-0 was like playing a musical instrument."

### vocabulary

- **throttle:** a control used to regulate power or speed.
- **assembler:** software that translates assembly language into machine language.
- **binary:** a number system using only 0 and 1.

---

### page 20

- "flit was a quantum leap forward, since it liberated programmers to actually do original composing on the machine."
- "sometimes, it didn’t matter much at all what they did."

### vocabulary

- **debugger:** a tool used to find and fix errors in programs.
- **liberated:** made free from restrictions.
- **feat:** an impressive achievement.

---

### page 21

- "samson set about writing programs that varied the binary numbers in that slot in different ways to produce different pitches."
- "to err is human to forgive divine."

### vocabulary

- **adeptly:** skillfully.
- **unfazed:** not surprised or worried.
- **bypassed:** avoided or went around something.

---

### page 22

- "these digits that samson had jammed into the computer were a universal language that could produce anything."
- "peter samson did it, and his colleagues appreciated it, because it was obviously a neat hack."

### vocabulary

- **feat:** an impressive achievement.
- **blissful:** extremely happy.
- **metaphorically:** in a symbolic rather than literal way.

---

### page 23

- "they were studying what they were studying, and we were studying what we were studying."
- "the hackers came out at night. it was the only way to take full advantage of the crucial 'off-hours' of the tx-0."

### vocabulary

- **immaterial:** unimportant or irrelevant.
- **annotate:** to add notes or comments.
- **curriculum:** the subjects included in a course of study.



