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

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
#define patrat_mic 10
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
void displayMatrice( short matrice[3][3], int x, int y){   // h lat
 // tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, 0xFFFF); 10
//  tft.fillRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color1);
  for(int i = 0; i<=2;i++){
    for(int j = 0;j<=2;j++){
      if(matrice[i][j]){
        tft.fillRect(x + j*patrat_mic,y + i*patrat_mic , 10,10,0xFFFF);
      }
    }
  }
}



void setup() {
  // put your setup code here, to run once:
tft.initR(INITR_144GREENTAB);
  tft.fillScreen(0x0000);
  displayMatrice(A,1,1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
