/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: LCD, KEYPAD Y SERVOMOTOR CON ARDUINO
 *  
 *  ******* [ MENU CON LCD 16X2, KEYPAD 4X4 Y SERVOMOTOR GS90 CON ARDUINO ] *******
*/

#include <LiquidCrystal.h> // Librería para el manejo del LCD
#include <Keypad.h> // Librería para el manejo del teclado matricial
#include <Servo.h> // Librería para el manejo del servomotor

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); // Pines usados para el LCD
const byte filas = 4; // número de filas
const byte columnas = 4; // número de columnas

char teclas [filas][columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  };
byte filaPines[filas]={11,10,9,8}; // Pines de conexion para el teclado matricial
byte columnaPines[columnas] = {7,6,5,4};
Keypad teclado = Keypad(makeKeymap(teclas),filaPines,columnaPines,filas, columnas);

// Caracter personalizado "°"
byte grados[8] = {
  0b01110,
  0b11011,
  0b10001,
  0b11011,
  0b01110,
  0b00000,
  0b00000,
  0b00000
  };
//Nombre asignado a nuestro servo
Servo servo1;

// Variables
char key;
String num, aux;
byte i = 0;
byte menu = 0;


void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,grados);
  servo1.attach(3,720,2350);
  
}

void loop() {
  
  // Menu principal y el submenu
  if(menu == 0) menuPrincipal();
  if(menu == 1) manual();
}

void menuPrincipal()
{
  lcd.setCursor(0,0);
  lcd.print("1>0");
  lcd.write(byte(0));
  lcd.setCursor(8,0);
  lcd.print("2>90");
  lcd.write(byte(0));
  lcd.setCursor(0,1);
  lcd.print("3>180");
  lcd.write(byte(0));
  lcd.print("*>MANUAL");
  key = teclado.getKey();

  // Realizamos condicionales para escoger varias opciones desde el teclado matricial
  if(key == '*') {menu = 1; lcd.clear();}
  if(key == '1') servo1.write(0);
  if(key == '2') servo1.write(90);
  if(key == '3') servo1.write(180);
 }
void manual()
{
  lcd.setCursor(0,1);
  lcd.print("B<-Back");
  lcd.setCursor(8,1);
  lcd.print("C<-Clear");
  delay(50);

  key = teclado.getKey();
  if(key != NO_KEY)
  {
    switch(key)
    {
      case 'A':
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("SERVO ");
        lcd.setCursor(9,0);
        lcd.print(aux);
        lcd.write(byte(0));
        if(aux.toInt()>180)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Numero No valido");
          }
        else
          servo1.write(aux.toInt());  
          num = "";
          i = 0;
      break;
      case 'B':
        lcd.clear();
        menu = 0;
      break;
      case 'C':
        lcd.clear();
        i = 0;
        num = "";
      break;
      case 'D':
        // Añadir mas funciones si se lo requiere
      break;
      case '#':
        // Añadir mas funciones si se lo requiere
      break;
      case '*':
        // Añadir mas funciones si se lo requiere
      break;
      default:
        if(i < 3)
        {
          lcd.clear();
          lcd.setCursor(6,0);
          num = num + key;
          lcd.print(num);
          aux = num;
          i++;
          if(i == 3)
          {
            i = 0;
            num = "";
            }
          }
      break;
      }
    }
  } 

 
