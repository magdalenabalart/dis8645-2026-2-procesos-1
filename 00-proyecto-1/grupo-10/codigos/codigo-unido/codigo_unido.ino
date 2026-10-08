#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerifItalic9pt7b.h>
#include "Animaciones.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

//digital 3 como entrada para a el boton
int patitaBoton = 3;
//lectura del boton comienza en 0, ya que está apagado
int lecturaBoton = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 2112)
const int epd_bitmap_allArray_LEN = 4;
const unsigned char* epd_bitmap_allArray[4] = {
	epd_bitmap_pluma_frame1,
	epd_bitmap_pluma_frame2,
	epd_bitmap_pluma_frame3,
	epd_bitmap_pluma_frame4
};

const char *versos[] = {
  "Hope is the thing with",
  "feathers",
  "That perches in",
  "the soul",
  "and sings the tune without the words",
  "and never stops",
  "at all...",
  "-Emily Dickinson"
	"La esperanza es algo con",
	"Plumas",
	"Que se posa en",
	"el alma",
	"que canta su canción sin palabras",
	"y jamas",
	"se calla",
  "-Emily Dickinson"
};

const int totalVersos = sizeof(versos) / sizeof(versos[0]);

unsigned long tiempoAnterior = 0;
const unsigned long intervalo = 3000;
int versoActual = 0;

void mostrarPluma(const unsigned char *frame) {
  display.clearDisplay();
  display.drawBitmap(0, 0, frame, 128, 32, SSD1306_WHITE);
  display.display();
}

void reproducirAnimacionPluma() {
  mostrarPluma(epd_bitmap_pluma_frame1);
  delay(300);

  mostrarPluma(epd_bitmap_pluma_frame2);
  delay(300);

  mostrarPluma(epd_bitmap_pluma_frame3);
  delay(300);

  mostrarPluma(epd_bitmap_pluma_frame4);
  delay(300);

  display.clearDisplay();
  display.display();
}

bool plumaPendiente = false;

void setup() {
  Serial.begin(9600);

//definir entrada para funcion de boton
pinMode(patitaBoton, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }

  // Configuracion del texto del poema
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setFont(&FreeSerifItalic9pt7b);

  // Empieza a contar desde aqui para mostrar el primer verso.
  tiempoAnterior = millis();
}


void loop() {

lecturaBoton = digitalRead(patitaBoton);+
Serial.println(lecturaBoton);

  unsigned long tiempoActual = millis();

  if (tiempoActual - tiempoAnterior >= intervalo) {
    tiempoAnterior = tiempoActual;

    // Si ya se mostro "feathers", en este turno aparece la pluma.
    if (plumaPendiente) {
      reproducirAnimacionPluma();
      plumaPendiente = false;

      // Reiniciamos la referencia para que el siguiente verso
      // espere 3 segundos despues de terminar la animacion.
      tiempoAnterior = millis();
      return;
    }

    if (versoActual < totalVersos) {
      display.clearDisplay();
      display.setCursor(5, 15);
      display.println(versos[versoActual]);
      display.display();

      // "feathers" es el verso numero 2, indice 1.
      // Dejamos marcada la animacion para el siguiente intervalo.
      if (versoActual == 1) {
        plumaPendiente = true;
      }

      versoActual++;
    }
    else {
      // Reinicia el poema al terminar.
      versoActual = 0;
    }
  }
}
