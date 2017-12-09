int JoyStick_X = A0; // x
int JoyStick_Y = A1; // y
int JoyStick_Z = 2; // key
int xJoy, yJoy, zJoy;
bool indice = true;
void setup() {
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (JoyStick_Z, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  tick();
  afisare();
}
void afisare(){
  //in progress
}
void tick(){
  x = analogRead (JoyStick_X);
  y = analogRead (JoyStick_Y);
  z = digitalRead (JoyStick_Z);
  
  //Serial.println(y);
  //Serial.println(x);
  //Serial.println(z);
  
  switch(directie(x, y)){
    case 'D':
    miscaDreapta();
    break;
    case 'S':
    miscaStanga();
    break;
    case 'J':
    miscaJos();
    break;
  
}
  delay(500);
  
}
char directie(int k, int j){  
  
  if(indice==true) { 
    if(k>524) { return 'J';; indice = false; }
    if(j<502) { return 'D'; indice = false; }
    if(j>510) { return 'S'; indice = false; }
   }

}
void miscaDreapta(){
  // fa 
}
void miscaStanga(){
  //fa
}
void miscaJos(){
  //fa
}

