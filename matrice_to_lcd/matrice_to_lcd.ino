#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   10
#define TFT_RST  9
#define TFT_DC   8
#define TFT_SCLK 13
#define TFT_MOSI 11

#define patrat_mic 10

short field[20][10] = { 0 };

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

short sqr[3][3] = { { 1, 1, 0},
  { 1, 1, 0},
  { 0, 0, 0}
};
short line[3][3] = { { 0, 0, 0},
  { 0, 0, 0},
  { 1, 1, 1}
};
int L[3][3] = { { 0, 0, 0 },
  { 1, 0, 0 },
  { 1, 1, 1 }
};
short t[3][3] = { { 0, 1, 0 },
  { 1, 1, 1 },
  { 0, 0, 0 }
};
short k[3][3] = { { 0, 0, 0 },
  { 0, 1, 1 },
  { 1, 1, 0 }
};

void copyElem() {

  int ran = random(0, 5);

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      k[i][j] = field[i][j+ran];
    }
  }

}

void displayMatrice( short matrice[20][10]) {  //h lat

  for (int y = 0; y <= tft.height() - 1; y += 10) {
    for (int i = 0; i <= 20; i++) {
      for (int j = 0; j <= 10; j++) {
        if (matrice[i][j]) {
          tft.fillRect(j * patrat_mic, y + i * patrat_mic , 10, 10, 0xFFFF);
        }
      }
    }
    delay(200);
    if (y + 10 > 119) return;
    for (int i = 0; i <= 20; i++) {
      for (int j = 0; j <= 10; j++) {
        if (matrice[i][j]) {
          tft.fillRect(j * patrat_mic, y + i * patrat_mic , 10, 10, 0x0000);
        }
      }
    }
  }
}

void setup() {

  tft.initR(INITR_144GREENTAB);
  tft.fillScreen(0x0000);

  copyElem();
  displayMatrice(field);
  
  //displayMatrice( t , 1, 1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
