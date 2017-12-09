#define TFT_BLACK       0x0000
#define TFT_WHITE       0xFFFF

#include <TFT_HX8357.h>

TFT_HX8357 tft = TFT_HX8357();

short spin = 0;

short field[20][10];

short sqr[3][3] = { { 1, 1, 0},
                { 1, 1, 0},
                { 0, 0, 0} };

short line[3][3] = { { 0, 0, 0},
              { 0, 0, 0},
              { 1, 1, 1} };

short ** L[3][3] = { { 0, 0, 0 },
           { 1, 0, 0 },
           { 1, 1, 1 } };

short t[3][3] = { { 0, 1, 0 },
           { 1, 1, 1 },
           { 0, 0, 0 } };
short k[3][3] = { { 0, 0, 0 },
           { 0, 1, 1 },
           { 1, 1, 0 } };

short aux[3][3] = { 0 };

void setup(){

 tft.init();
 tft.fillScreen(0x0000);

 for(byte i = 0; i<20; i++){
  for(byte j = 0; j<10; j++){
    field[i][j] = 0;
  }
 }

 Serial.begin(9600);
 spin = Serial.read();

 reverse(&L, 2);

}

void loop(){
  if( spin == 3 ) spin = 0;
}

void dis(short x){

  for(byte y = 20; y; y++){
    draw(x, y);
    delay(100);
    del(x, y);
  }
  
}

void reverse( short **i, short spin ) {

  for(byte a = 0; a < spin; a++){
    for(byte j = 0; j < 3; j++){
      for(byte k = 0; k < 3; k++){
        i[j][k] = aux[k][j];
      }
    }
  }
   for(byte j = 0; j < 3; j++){
     for(byte k = 0; k < 3; k++){
       i[j][k] = aux[j][k];
     }
  }
  for(byte j = 0; j < 3; j++){
    for(byte k = 0; k < 3; k++){
      Serial.print(i[j][k]);
      if( k == 3 ) Serial.println();
    }
  }
  
}

void draw(short x, short y){
  tft.fillRect(x, y, 40, 40, TFT_WHITE); //
}

void del(short x, short y){
  tft.fillRect(x, y, 40, 40, !TFT_WHITE);
}
