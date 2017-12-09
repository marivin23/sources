#include <iostream>
#include<windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define lungime 20
#define latime 20
bool gameOver = 0;
bool colided = 0;
char key = '\0';
short ecran[lungime][latime];/*{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};*/
short xFig, yFig  ;
short forma1[4][4]={
   {2,2,2,2},
   {2,2,2,2},
   {2,2,2,2},
   {2,2,2,2} };
short forma2[4][4]= {
      {2,2,0,0},
      {2,2,0,0},
      {0,0,0,0},
      {0,0,0,0} };
    short forma3[4][4]= {
         {2,2,2,2},
         {0,0,0,0},
         {0,0,0,0},
         {0,0,0,0} };
    short forma4[4][4]= {
            {0,2,0,0},
            {2,2,0,0},
            {2,0,0,0},
            {0,0,0,0} };
            short forma5[4][4]= {
               {2,2,2,2},
               {2,0,0,0},
               {0,0,0,0},
               {0,0,0,0} };
            short forma6[4][4]= {
                  {0,2,0,0},
                  {2,2,2,0},
                  {0,0,0,0},
                  {0,0,0,0} };
                short forma7[4][4]= {
                        {2,0,0,0},
                        {2,2,0,0},
                        {0,2,0,0},
                        {0,0,0,0} };
void init(){
  for(int k = 0;k<latime;k++){
    ::ecran[lungime][k] = -1; // definim fundul
  }
  xFig = 1;
  yFig = 1;
}
void moveFigure(int x, int y, char directie){ // spawneaza o forma de 4 pe 4 la pozitia (x,y)
//deletarea pe pozitia anterioara
switch(directie){
case 'J': //JOS
for(int i=y-1; i<=y+2; i++){
  for(int j=x; j<=x+3; j++){
    if( ::ecran[i][j] == 2 && (forma1[i-y+1][j-x] == 2) ){
      ::ecran[i][j] = 0;
    }
}//endfor
}//endfor
break;
case 'D': //DREAPTA
for(int i=y; i<=y+3; i++){
  for(int j=x-1; j<=x+2; j++){
    if( ::ecran[i][j]== 2 && (forma1[i-y][j-x+1] == 2) ){
      ::ecran[i][j] = 0;
    }
}//endfor
}//endfor
break;
case 'S': //STANGA
for(int i=y; i<=y+3; i++){
  for(int j=x+1; j<=x+4; j++){
    if( ::ecran[i][j] == 2 && (forma1[i-y][j-x+1] == 2) ){
      ::ecran[i][j] = 0;
    }
}//endfor
}//endfor
break;
}//endswitch
/* marius
 for(int i=y; i<=y+3; i++){
    for(int j=x; j<=x+4; j++){
    ::ecran[i-1][j] = 0;
    }
  }*/
//rescrierea pe pozitia noua
  for(int i=y; i<=y+3; i++){
    for(int j=x; j<=x+3; j++){

  }
}
}

void afiseaza(){
  for(int i=0;i<lungime;i++){
    for(int j=0;j<latime;j++){
      cout<< ::ecran[i][j]<<" ";
    }
    cout<<endl;
  }
}

void stergere(int x, int y){

  for(int i=y; i<=y+3; i++){
    for(int j=x+1; j<=x+4; j++){
      if( ::ecran[i][j] == 2 && (forma1[i-y][j-x+1] == 2) ){
        ::ecran[i][j] = 0;
      }
  }//endfor
}//efor

}

void keyboardListener(){
  if(kbhit()){
    ::key = getch();
  }
}
void rescrieFigura(){
    if(::key != '\0'){// daca a fost apasat ceva
      //aici se executa ceva
      switch(::key){
        case 'd':
          if(xFig<latime - 1){
          moveFigure(++xFig, yFig, 'D');
          }
        break;
        case 'a':
          if(xFig>=1){
          moveFigure(--xFig, ++yFig, 'S');
          }
        break;
      }
    ::key = '\0';   // resetam cheia
    }
    //figura cade in jos, cu verificari si stergerea pe pozitia anterioara

    moveFigure(xFig, ++yFig, 'J');
}

int main(){
  init();
 //spawn(0,0); --> e moveFigure acum
  for(int plm =1;plm<=50;plm++){
      keyboardListener();
      rescrieFigura();
       afiseaza();
         Sleep(100) ;
        system("cls");
  }

  return 0;
}
