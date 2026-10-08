//Bibliotecas que vamos a usar, es principalmente importante ya que con esta hacemos el llamado a la pantalla oled
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pantalla OLED aquí declaramos la pantalla y sus características
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// Tipo de objeto
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Componentes, importante revisar que los pin estén correctos
const int potenciometro = A0; // potenciómetro
const int buttonPin = 12;     // pushbutton pin
const int ledPin = 9;         // LED pin


// 4. DATOS VISUALES
// Aquí estamos llamando al código donde tenemos los cuadros de la animación
#include "Cuadros.h"


// TEXTOS DEL PROYECTO

const char* partesVersos[] = {

  // Verso 1
  "No tienes\nque ser buena.",

  // Verso 2 - parte 1
  "No tienes que\nrecorrer el\ndesierto de",

  // Verso 2 - parte 2
  "rodillas,\narrepintiendote.",

  // Verso 3 - parte 1
  "Solo deja que\nel suave animal",

  // Verso 3 - parte 2
  "de tu cuerpo\name lo que ama.",

  // Verso 4
  "Hablame del dolor,\ndel tuyo,\nyo te hablare del mio.",

  // Verso 5
  "Mientras tanto,\nel mundo sigue."
};


const char autora[] = "Mary Oliver";
const char titulo[] = "Gansos salvajes";
const char instruccionPot[] = "Gira potenciometro";


const char* mensajeBoton[] = {
  "Presiona boton",
  "para leer"
};


// 4. VARIABLES DE CONTROL

int etapa = 0; // Guarda en qué etapa general del programa estamos

int buttonState = 0;
int lastButtonState = 0;

int parteActual = 0;

int valorPot = 0;
int letrasMostrar = 0;


// Doble click
unsigned long tiempoUltimoClick = 0;
const unsigned long intervaloDobleClick = 400;


// Antirrebote del boton
unsigned long tiempoUltimaPresion = 0;
const unsigned long intervaloBoton = 180;


// 5. DECLARACION DE FUNCIONES

void mostrarAnimacion();
void mostrarMensajeBoton();
void mostrarTitulo();
void mostrarVerso();
void mostrarAutora();
void revisarBoton();
void revisarDobleClick();
void reiniciarProyecto();


// 6. SETUP

void setup() {

  // Preparar componentes
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // LED comienza apagado
  digitalWrite(ledPin, LOW);


  // Iniciar pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;);
  }


  // Limpiar pantalla
  display.clearDisplay();
  display.display();


  // Leer estado inicial del boton
  // Esto ayuda a evitar una falsa presion al comenzar
  buttonState = digitalRead(buttonPin);
  lastButtonState = buttonState;


  // Comenzar desde el inicio
  etapa = 0;


  // Mostrar mensaje inicial
  mostrarMensajeBoton();
}


// 7. VOID LOOP

void loop() {

  // ETAPAS 0, 2 y 3:
  // esperar presiones normales del boton
  if (etapa == 0 || etapa == 2 || etapa == 3) {

    revisarBoton();
  }


  // ETAPA 4:
  // potenciometro + doble clic para reiniciar
  else if (etapa == 4) {

    mostrarAutora();
    revisarDobleClick();
  }
}


// 8. FUNCIONES


void mostrarAnimacion() {

  // Repetir la animacion 2 veces
  for (int repeticion = 0; repeticion < 3; repeticion++) {

    // Recorrer todos los cuadros
    for (int i = 0; i < epd_bitmap_allArray_LEN; i++) {

      display.clearDisplay();

      display.drawBitmap(
        0,
        0,
        epd_bitmap_allArray[i],
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SSD1306_WHITE
      );

      display.display();

      delay(150);
    }
  }
}



void mostrarMensajeBoton() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);


  display.setCursor(10, 8);
  display.println(mensajeBoton[0]);


  display.setCursor(25, 18);
  display.println(mensajeBoton[1]);


  display.display();
}



void mostrarTitulo() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);


  display.setCursor(20, 10);
  display.println(titulo);


  display.display();
}



void mostrarVerso() {

  // LED segun el verso real


  // Verso 1
  if (parteActual == 0) {

    digitalWrite(ledPin, HIGH);
  }


  // Verso 2 - partes 1 y 2
  else if (parteActual == 1 || parteActual == 2) {

    digitalWrite(ledPin, LOW);
  }


  // Verso 3 - partes 1 y 2
  else if (parteActual == 3 || parteActual == 4) {

    digitalWrite(ledPin, HIGH);
  }


  // Verso 4
  else if (parteActual == 5) {

    digitalWrite(ledPin, LOW);
  }


  // Verso 5
  else if (parteActual == 6) {

    digitalWrite(ledPin, HIGH);
  }



  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);



  // Partes de 3 lineas
  if (parteActual == 1 || parteActual == 5) {

    display.setCursor(0, 0);
  }


  // Partes de 2 lineas
  else {

    display.setCursor(0, 6);
  }



  // Mostrar solamente la parte actual
  display.println(partesVersos[parteActual]);


  display.display();
}



void mostrarAutora() {

  // Leer potenciometro
  valorPot = analogRead(potenciometro);


  // Transformar el valor del potenciometro
  // en cantidad de letras visibles
  letrasMostrar = map(
    valorPot,
    0,
    1023,
    0,
    strlen(autora)
  );


  // Evitar que el numero de letras
  // pase del largo del nombre
  if (letrasMostrar > strlen(autora)) {

    letrasMostrar = strlen(autora);
  }


  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);


  // Nombre de autora
  display.setCursor(0, 0);


  for (int i = 0; i < letrasMostrar; i++) {

    display.print(autora[i]);
  }


  // Instruccion abajo
  display.setCursor(0, 22);
  display.println(instruccionPot);


  display.display();
}



void revisarBoton() {

  // Leer boton
  buttonState = digitalRead(buttonPin);


  // Detectar una nueva presion
  if (
    buttonState == HIGH &&
    lastButtonState == LOW &&
    millis() - tiempoUltimaPresion > intervaloBoton
  ) {

    // Guardar momento de esta presion
    tiempoUltimaPresion = millis();



    // MENSAJE INICIAL → ANIMACION → TITULO
    if (etapa == 0) {

      mostrarAnimacion();

      mostrarTitulo();

      etapa = 2;
    }



    // TITULO → PRIMERA PARTE DEL POEMA
    else if (etapa == 2) {

      parteActual = 0;

      mostrarVerso();

      etapa = 3;
    }



    // AVANZAR ENTRE LAS PARTES DEL POEMA
    else if (etapa == 3) {

      if (parteActual < 6) {

        parteActual++;

        mostrarVerso();
      }

      else {

        // Apagar LED al terminar el poema
        digitalWrite(ledPin, LOW);

        // Pasar al potenciometro
        etapa = 4;
      }
    }
  }


  // Guardar estado anterior del boton
  lastButtonState = buttonState;
}



void revisarDobleClick() {

  // Leer boton
  buttonState = digitalRead(buttonPin);


  // Detectar nueva presion
  if (
    buttonState == HIGH &&
    lastButtonState == LOW
  ) {

    unsigned long tiempoActual = millis();


    // Segundo clic dentro del intervalo
    if (
      tiempoUltimoClick > 0 &&
      tiempoActual - tiempoUltimoClick <= intervaloDobleClick
    ) {

      reiniciarProyecto();

      tiempoUltimoClick = 0;
    }


    // Primer clic
    else {

      tiempoUltimoClick = tiempoActual;
    }
  }


  // Guardar estado anterior del boton
  lastButtonState = buttonState;
}



void reiniciarProyecto() {

  // Volver al inicio
  etapa = 0;


  // Volver a la primera parte
  parteActual = 0;


  // Apagar LED
  digitalWrite(ledPin, LOW);


  // Reiniciar potenciometro y autora
  valorPot = 0;
  letrasMostrar = 0;


  // Reiniciar tiempos
  tiempoUltimoClick = 0;
  tiempoUltimaPresion = 0;


  // Actualizar estado del boton
  buttonState = digitalRead(buttonPin);
  lastButtonState = buttonState;


  // Volver a mostrar el mensaje inicial
  mostrarMensajeBoton();
}