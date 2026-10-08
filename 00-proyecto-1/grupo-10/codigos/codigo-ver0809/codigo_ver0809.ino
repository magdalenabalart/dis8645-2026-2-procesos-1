//primero lo primero
//llamar a la biblioteca de las
//cosas que queremos usar
//para que esto funcione
//incluir librerias
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
//librería de la fuente Sans Serif
#include <Fonts/FreeSerifItalic9pt7b.h>

//carpeta animación pluma
#include "Animacion.h"

//carpeta animación pollo
#include "Pollo.h"

//definir el tipo de pantalla que estamos usando
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

//definir conexión del botón 
int patitaBoton = 3;
int lecturaBoton = 0;

//definir conexión del pote
int patitaPot = A0;
int lecturaPot = 0;

//crear variable pollo
int pollo = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//Versos en inglés
//Los versos estan ordenados
//a conveniencia 
//por el tamaño de la tipografía
const char *versos[] = {

  "Hope is the thing",
  "with feathers",
  "That perches in",
  "the soul",
  "and sings the tune",
  "without the words",
  "and never stops",
  "at all...",
  "And sweetest in", 
  "the gale is heard;",
  "And sore must",
  "be the storm",
  "That could abash",
  "the little bird",
  "That kept",
  "so many warm",
  "I've heard in the",
  "chillest land",
  "And on the",
  "strangest sea;",
  "Yet, never,",
  "in extremity,",
  "It asked a crumb of me",
  " ",
  "-Emily Dickinson"

};


//Versos en español
//estos versos también están
//ordenados a conveniencia
const char *versosEspanol[] = {

  "La esperanza", 
  "es algo",
  "Con plumas",
  "Que se posa en",
  "el alma",
  "que canta su", 
  "cancion", 
  "sin palabras",
  "y jamas",
  "se calla",
  "Y se oye mas",
  "dulcemente",
  "en la tempestad,",
  "Y muy fuerte",
  "debe ser",
  "la tormenta",
  "Que pudiera",
  "acobardar al",
  "pajarito",
  "Que a tantos",
  "le dio calor",
  "La he oido en la",
  "tierra mas fria",
  "Y en el mar",
  "mas extrano",
  "Pero nunca,",
  "en la adversidad,",
  "Me pidio una",
  "migaja",
  "-Emily Dickinson"

};

//solo se inicia una vez
void setup() {

  Serial.begin(9600);

//patitaBoton recibe información
  pinMode(patitaBoton, INPUT);

//Llamando a pantalla
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {

    Serial.println("SSD1306 allocation failed");

    for (;;);

  }

  display.clearDisplay();

//cosas tipograficas
  display.setTextSize(1);

  display.setTextColor(SSD1306_WHITE);

  display.setFont(&FreeSerifItalic9pt7b);

}


void loop() {

//Leer boton
  lecturaBoton = digitalRead(patitaBoton);

//Leer potenciometro
  lecturaPot = analogRead(patitaPot);

//El potenciómetro cumplirá la función de
//desplazar el poema hacia arriba o hacia abajo 
  int y = map(lecturaPot, 0, 1023, 20, -900);


//Aparece un frame del pollo
//luego +1 aparece el otro 
//y así sucesivamente
  pollo++;
//La animación empieza en el 0 y cuando pasa el décimo frame 
//se reinicia
  if (pollo >= pollo_allArray_LEN) {
    pollo = 0;
  }


  display.clearDisplay();

//Poema en español
//si el botón está presionado
//se muestra el poema en español
  if (lecturaBoton == 1) {

//posición del poema en y variable
    int posicionY = y;

//Ordenamos en una formula 
//el avance del poema
//i será la variable que cambia mientras corre el poema 
    for (int i = 0; i < 30; i++) {

      display.setCursor(0, posicionY);
      display.println(versosEspanol[i]);

//el poema se mueve en y con una separación de 22px entre versos
      posicionY = posicionY + 22;


//si el poema pasa el segundo verso
//se muestran los frames de plumas cayendo
      if (i == 2) {

        display.drawBitmap(
          0,
          posicionY,
          epd_bitmap_frame1,
          128,
          32,
          SSD1306_WHITE
        );

        display.drawBitmap(
          0,
          posicionY + 32,
          epd_bitmap_frame2,
          128,
          32,
          SSD1306_WHITE
        );

        display.drawBitmap(
          0,
          posicionY + 64,
          epd_bitmap_frame3,
          128,
          32,
          SSD1306_WHITE
        );

        display.drawBitmap(
          0,
          posicionY + 96,
          epd_bitmap_frame4,
          128,
          32,
          SSD1306_WHITE
        );

        display.drawBitmap(
          0,
          posicionY + 128,
          epd_bitmap_frame5,
          128,
          32,
          SSD1306_WHITE
        );

        posicionY = posicionY + 170;
      }


//Si pasa el verso 15
//se muestra la animación del pollo
      if (i == 15) {

        display.drawBitmap(
          0,
          posicionY,
          pollo_allArray[pollo],
          128,
          32,
          SSD1306_WHITE
        );

        posicionY = posicionY + 50;
      }

    }

  }

//Poema en ingles
//si el botón no está presionado
//se muestra la versión original
  else {

//posición del poema en y variable
    int posicionY = y;

//Ordenamos en una formula 
//el avance del poema
//i será la variable que cambia mientras corre el poema
    for (int i = 0; i < 25; i++) {

      display.setCursor(0, posicionY);
      display.println(versos[i]);

//el poema se mueve en y con una separación de 22px entre versos
      posicionY = posicionY + 25;

//si el poema pasa el segundo verso
//se muestran los frames de plumas cayendo
      if (i == 1) {

        display.drawBitmap(
          0,
          posicionY,
          epd_bitmap_frame1,
          128,
          32,
          SSD1306_WHITE
        );

        display.drawBitmap(
          0,
          posicionY + 32,
          epd_bitmap_frame2,
          128,
          32,
          SSD1306_WHITE
        );

        display.drawBitmap(
          0,
          posicionY + 64,
          epd_bitmap_frame3,
          128,
          32,
          SSD1306_WHITE
        );

        display.drawBitmap(
          0,
          posicionY + 96,
          epd_bitmap_frame4,
          128,
          32,
          SSD1306_WHITE
        );

        display.drawBitmap(
          0,
          posicionY + 128,
          epd_bitmap_frame5,
          128,
          32,
          SSD1306_WHITE
        );

        posicionY = posicionY + 170;
      }


//Si pasa el verso 11
//se muestra la animación del pollo
      if (i == 11) {

        display.drawBitmap(
          0,
          posicionY,
          pollo_allArray[pollo],
          128,
          32,
          SSD1306_WHITE
        );

        posicionY = posicionY + 50;
      }

    }

  }


  display.display();

  // velocidad de cambio de frames del pollo
  delay(80);
}