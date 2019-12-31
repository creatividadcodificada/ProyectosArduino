/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Lcd 16x2 con Arduino
 *  
 *  ******* [ARDUINO LCD 16 x 2 ==> Hitachi HD44780 ] *******
*/ 

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

byte chardino1[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B10000,
  B11000,
  B11100
};

byte chardino2[8] = {
  B00000,
  B00001,
  B00001,
  B00001,
  B00001,
  B00011,
  B01111,
  B11111
};
byte chardino3[8] = {
  B11111,
  B10111,
  B11111,
  B11111,
  B11100,
  B11111,
  B11100,
  B11100
};
byte chardino4[8] = {
  B10000,
  B11000,
  B11000,
  B11000,
  B00000,
  B10000,
  B00000,
  B00000
};
byte chardino5[8] = {
  B11111,
  B11111,
  B01111,
  B00111,
  B00011,
  B00011,
  B00010,
  B00011
};
byte chardino6[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B10110,
  B00010,
  B00010,
  B00011
};

byte chardino7[8] = {
  B11111,
  B11001,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};


byte charcabeza1[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11100,
  B11111,
  B11100,
  B11100
};

byte charpieder1[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B10110,
  B00011,
  B00000,
  B00000
};

byte charpieder2[8] = {
  B11111,
  B11001,
  B10000,
  B00000,
  B00000,
  B10000,
  B00000,
  B00000
};

byte charpieiz1[8] = {
  B11111,
  B11111,
  B01111,
  B00111,
  B00011,
  B00011,
  B00000,
  B00000
};

byte charpieiz2[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00110,
  B10010,
  B00010,
  B00011
};

///////////// pre-load //////////////////
///////////// Reloj de Arena ////////////

byte load1[8] = {
  B01111,
  B01101,
  B00100,
  B00100,
  B00110,
  B00011,
  B00001,
  B00000
};
byte load2[8] = {
  B11111,
  B01010,
  B10101,
  B01010,
  B00100,
  B00000,
  B10101,
  B11011
};
byte load3[8] = {
  B11110,
  B10110,
  B00100,
  B00100,
  B01100,
  B11000,
  B10000,
  B00000
};
byte load4[8] = {
  B00000,
  B00001,
  B00011,
  B00110,
  B00100,
  B00100,
  B01100,
  B01111
};
byte load5[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};
byte load6[8] = {
  B00000,
  B10000,
  B11000,
  B01100,
  B00100,
  B00100,
  B00110,
  B11110
};
//////////// fin  pre-load //////////////

///////// animacion 1 ////////////////
byte load1a[8] = {
  B01111,
  B01100,
  B00100,
  B00100,
  B00110,
  B00011,
  B00001,
  B00000
};
byte load2a[8] = {
  B11111,
  B01010,
  B10101,
  B01010,
  B00100,
  B00000,
  B10001,
  B11011
};
byte load5a[8] = {
  B11011,
  B10101,
  B00000,
  B00000,
  B00000,
  B00000,
  B01000,
  B11111
};
/////////////////ani2/////////

byte load2b[8] = {
  B11111,
  B01000,
  B10101,
  B01010,
  B00100,
  B00000,
  B10101,
  B11011
};
byte load5b[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00000,
  B00000,
  B01010,
  B11111
};
///////////ani3//////////////
// load1a
byte load2c[8] = {
  B11111,
  B01000,
  B10101,
  B01010,
  B00100,
  B00000,
  B10001,
  B11011
};
byte load3c[8] = {
  B11110,
  B00110,
  B00100,
  B00100,
  B01100,
  B11000,
  B10000,
  B00000
};
byte load5c[8] = {
  B11011,
  B10101,
  B00000,
  B00000,
  B00000,
  B00100,
  B01010,
  B11111
};
////////// ani4////////////

byte load2d[] = {
  B11111,
  B00000,
  B10101,
  B01010,
  B00100,
  B00000,
  B10101,
  B11011
};

byte load5d[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00000,
  B00100,
  B01010,
  B11111
};
byte load6d[8] = {
  B00000,
  B10000,
  B11000,
  B01100,
  B00100,
  B00100,
  B10110,
  B11110
};
////////ani 5 ////////

byte load2e[8] = {
  B11111,
  B00000,
  B10001,
  B01010,
  B00100,
  B00000,
  B10001,
  B11011
 };

byte load5e[8] = {
  B11011,
  B10101,
  B00000,
  B00000,
  B00000,
  B10100,
  B01010,
  B11111
};

//////// ani6 ///////
byte load2f[8] = {
  B11111,
  B00000,
  B00001,
  B01010,
  B00100,
  B00000,
  B10101,
  B11011
};
byte load4f[8] = {
  B00000,
  B00001,
  B00011,
  B00110,
  B00100,
  B00100,
  B01101,
  B01111
};
byte load5f[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00000,
  B10100,
  B01010,
  B11111
};
/////// ani7 /////////
byte load2g[8] = {
  B11111,
  B00000,
  B00000,
  B01010,
  B00100,
  B00000,
  B10001,
  B11011
};
byte load5g[8] = {
  B11011,
  B10101,
  B00000,
  B00000,
  B00000,
  B10101,
  B01010,
  B11111
};
///////ani8//////////

byte load2h[8] = {
  B11111,
  B00000,
  B00000,
  B01000,
  B00100,
  B00000,
  B10101,
  B11011
};
byte load5h[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B00010,
  B10101,
  B01010,
  B11111
};
///////// ani 9 //////
byte load2i[8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00100,
  B00000,
  B10101,
  B11011
};
byte load5i[8] = {
  B11011,
  B10001,
  B00100,
  B00000,
  B01010,
  B10101,
  B01010,
  B11111
};
////////ani10/////////

byte load2j[8] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B10001,
  B11011
};
byte load5j[8] = {
  B11011,
  B10101,
  B00000,
  B00100,
  B01010,
  B10101,
  B01010,
  B11111
};
///////giro1////
byte giro1[8] = {
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte giro2[8] = {
  B10000,
  B01000,
  B00100,
  B00100,
  B00100,
  B00100,
  B00110,
  B00011
};
byte giro3[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11110
};
byte giro4[8] = {
  B01111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte giro5[8] = {
  B10000,
  B11000,
  B01000,
  B01010,
  B01001,
  B01010,
  B00101,
  B00010
};
byte giro6[8] = {
  B00001,
  B00000,
  B00000,
  B10101,
  B01010,
  B00100,
  B01001,
  B10010
};
/// giro2///
byte giro1a[8] = {
  B00000,
  B00000,
  B11000,
  B11110,
  B10011,
  B10000,
  B10000,
  B10000
};
byte giro2a[8] = {
  B00000,
  B00000,
  B00000,
  B00001,
  B10011,
  B11110,
  B01100,
  B00000
};
byte giro3a[8] = {
  B00000,
  B00011,
  B01111,
  B11001,
  B10011,
  B00001,
  B00011,
  B00001
};
byte giro4a[8] = {
  B10000,
  B10000,
  B10001,
  B10011,
  B11110,
  B11000,
  B00000,
  B00000
};
byte giro5a[8] = {
  B01100,
  B11110,
  B10011,
  B00001,
  B00000,
  B00000,
  B00000,
  B00000
};
byte giro6a[8] = {
  B01011,
  B00101,
  B10011,
  B11101,
  B01011,
  B00111,
  B00000,
  B00000
};
///// giro3///
byte giro1b[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B01111
};
byte giro2b[8] = {
  B00001,
  B00010,
  B00100,
  B00100,
  B00100,
  B00100,
  B01100,
  B11000
};
byte giro3b[8] = {
  B00011,
  B00001,
  B00000,
  B00101,
  B01010,
  B10101,
  B01010,
  B10101
};
byte giro4b[8] = {
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00001,
  B10011
};
byte giro5b[8] = {
  B00011,
  B00110,
  B00100,
  B00100,
  B00100,
  B00100,
  B01000,
  B10000
};
byte giro6b[8] = {
  B11110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

int tiempo = 250;
int t = 100;
void setup() {
 lcd.begin(16,2); // configuramos el LCD de 16x2
 for(int i = 0; i<4; i++){
   preLoad(); 
    }}
void loop() {
   letras();
   desplazar_dino();
   dinoAnimacion();
}
 // Creamos los caracteres de nuestra animación 
//  del dinosaurio para que camine
void dinoAnimacion() 
{
  for(int i = 0 ; i <= 8; i++ ){
  lcd.createChar(1,chardino1);
  lcd.createChar(2,chardino2);
  lcd.createChar(3,chardino3);
  lcd.createChar(4,chardino4);
  lcd.createChar(5,chardino5);
  lcd.createChar(6,chardino6);
  lcd.createChar(7,chardino7);
  
  lcd.setCursor(0,0);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);

  lcd.setCursor(0,1);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
  delay(tiempo);

  lcd.createChar(6,charpieder1);
  lcd.createChar(7,charpieder2);
  lcd.setCursor(0,1);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
  delay(tiempo);

  lcd.createChar(5,charpieiz1);
  lcd.createChar(6,charpieiz2);
  lcd.setCursor(0,1);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
  delay(tiempo);
  
  }
}

// Realizamos un bucle para desplazar el dinosaurio cuatro pasos
void desplazar_dino()
 {
  for (int a=0; a<=3; a++)
  {
  lcd.createChar(1,chardino1);
  lcd.createChar(2,chardino2);
  lcd.createChar(3,chardino3);
  lcd.createChar(4,chardino4);
  lcd.createChar(5,chardino5);
  lcd.createChar(6,chardino6);
  lcd.createChar(7,chardino7);

  if(a>=3){
  lcd.setCursor(a-3,0);
  lcd.write(1);}
  if(a>=2)
  {lcd.setCursor(a-2,0);
  lcd.write(2);}
  if(a>=1)
  {lcd.setCursor(a-1,0);
  lcd.write(3);}
  lcd.setCursor(a,0);
  lcd.write(4);
  
  if(a>=3){
  lcd.setCursor(a-3,1);
  lcd.write(5);}
  if(a>=2){
  lcd.setCursor(a-2,1);
  lcd.write(6);}
  if(a>=1){
  lcd.setCursor(a-1,1);
  lcd.write(7);}
  
  delay(tiempo);
 }
}
// Código para desplazar las letras de derecha a izquierda 
 void letras()
  {
   for (int a=15; a>=4;a--)
    {
      lcd.clear();
      lcd.setCursor(a,0);
      lcd.print("Creatividad");
      lcd.setCursor(a,1);
      lcd.print("Codificada");
      delay(100);
    }
    
  }
// Animación del reloj de arena que actua como un pre-load
// Se van sobrescribiendo los caracteres creados en cada fotograma.
void preLoad()
{
  lcd.clear();
  lcd.createChar(0,load1);
  lcd.createChar(1,load2);
  lcd.createChar(2,load3);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5);
  lcd.createChar(5,load6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2a);
  lcd.createChar(2,load3);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5a);
  lcd.createChar(5,load6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);
  
  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2b);
  lcd.createChar(2,load3);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5b);
  lcd.createChar(5,load6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2c);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5c);
  lcd.createChar(5,load6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2d);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5d);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);
  
  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2e);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4);
  lcd.createChar(4,load5e);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2f);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5f);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2g);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5g);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2h);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5h);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);
  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2i);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5i);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,load1a);
  lcd.createChar(1,load2j);
  lcd.createChar(2,load3c);
  lcd.createChar(3,load4f);
  lcd.createChar(4,load5j);
  lcd.createChar(5,load6d);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,giro1);
  lcd.createChar(1,giro2);
  lcd.createChar(2,giro3);
  lcd.createChar(3,giro4);
  lcd.createChar(4,giro5);
  lcd.createChar(5,giro6);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);
  
  lcd.clear();
  lcd.createChar(0,giro1a);
  lcd.createChar(1,giro2a);
  lcd.createChar(2,giro3a);
  lcd.createChar(3,giro4a);
  lcd.createChar(4,giro5a);
  lcd.createChar(5,giro6a);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);

  lcd.clear();
  lcd.createChar(0,giro1b);
  lcd.createChar(1,giro2b);
  lcd.createChar(2,giro3b);
  lcd.createChar(3,giro4b);
  lcd.createChar(4,giro5b);
  lcd.createChar(5,giro6b);
  lcd.setCursor(6,0);
  lcd.write(byte(0));
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  delay(t);
  }
