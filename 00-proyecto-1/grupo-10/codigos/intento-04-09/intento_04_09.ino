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


// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 2640)
const int epd_bitmap_allArray_LEN = 5;
const unsigned char* epd_bitmap_allArray[5] = {
	epd_bitmap_frame1,
	epd_bitmap_frame2,
	epd_bitmap_frame3,
	epd_bitmap_frame4,
	epd_bitmap_frame5
};
//versos en inglés
const char *versos[] = {
  "Hope is the thing with",
  "feathers",
  "That perches in",
  "the soul",
  "and sings the tune without the words",
  "and never stops",
  "at all...",
  "-Emily Dickinson"
};
//versos en español
const char *versosEspanol[] = {
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
int versoActual = 0;

void mostrarPluma(const unsigned char *frame) {
  display.clearDisplay();
  display.drawBitmap(0, 0, frame, 128, 32, SSD1306_WHITE);
  display.display();
}

//se define el orden de la secuencia de la animación para ocuparla luego
void reproducirAnimacionPluma() {
  mostrarPluma(epd_bitmap_frame1);
  delay(300);

  mostrarPluma(epd_bitmap_frame2);
  delay(300);

  mostrarPluma(epd_bitmap_frame3);
  delay(300);

  mostrarPluma(epd_bitmap_frame4);
  delay(300);

  mostrarPluma(epd_bitmap_frame5);
  delay(300);

  display.clearDisplay();
  display.display();
}

bool plumaPendiente = false;


void setup() {
  //empieza el mambo
  Serial.begin(9600);

  //definir entrada para función de boton
  pinMode(patitaBoton, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("SSD1306 allocation failed");
    for (;;)  //en caso de fallos con la pantalla
      ;
  }

  // Configuración del texto del poema
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setFont(&FreeSerifItalic9pt7b);

}


void loop() {
  //lectura de datos del botón, 0 apagado -> inglés, 1 presionado -> español
  lecturaBoton = digitalRead(patitaBoton);
  Serial.println(lecturaBoton);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 20);

if (lecturaBoton == 1) {
  display.println(versosEspanol[versoActual]);
} else {
  display.println(versos[versoActual]);
}
display.display();

// Si ya se mostro "feathers", en este turno aparece la pluma.
if (versoActual == 2) {
  reproducirAnimacionPluma();
  plumaPendiente = true;
}
  //tiempo de espera
  delay(2000);

  versoActual++;
  //para que la animación total vuelva al comienzo y se repita
  if (versoActual >= totalVersos) {
    versoActual = 0;
  }
}

