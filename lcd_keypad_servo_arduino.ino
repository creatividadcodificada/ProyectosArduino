/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: LCD, KEYPAD Y SERVO CON ARDUINO 
 *      
 *  ******* [CONTROL DE SERVO MEDIANTE UN MENU ] *******
*/ 
#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); // varible LCD y pines
const byte filas = 4; // número de filas '4'
const byte columnas = 4; // número de columans '4'

char teclado [filas][columnas]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
}; //variable teclado

byte filaPines[filas]={11,10,9,8}; //configuración de filas
byte columnaPines[columnas]={7,6,5,4}; // configuración de columnas

Keypad calcu = Keypad (makeKeymap(teclado),filaPines, columnaPines, filas, columnas);

Servo servo1, servo2;
int gradosBoton = 90;
int pinPoten = 0;
int leerPoten;
int gradosPoten;

boolean inicio = false; 
boolean final = false; // variables de control

String num1, num2;
int ans;
char op;

void setup() {
 //attachInterrupt(digitalPinToInterrupt(2),sumarGrados,RISING);
 //attachInterrupt(digitalPinToInterrupt(3),restarGrados,RISING); 
 //Serial.begin(9600);

 
 //  Enviamos las señales a los servomotores por los pines 9 y 10
 // y los calibramos 
 servo1.attach(3,720,2250);

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Creatividad"); //Prendido de pantalla
  lcd.setCursor(5,1);
  lcd.print("Codificada"); //Prendido de pantalla
  delay(2500);
  lcd.clear();
}

void loop() {

 char key = calcu.getKey();
 if (key != NO_KEY && (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0')) 
 {
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15-numLength,0);
      lcd.print(num1); 
  }  

  if (key !=NO_KEY && key == '#')
{
    
    int x = num1.toInt();
    servo1.write(x);
    
    lcd.clear();
    lcd.setCursor(15,0);
    lcd.autoscroll();
    lcd.print(num1.toInt());
    lcd.noAutoscroll();    
     lcd.setCursor(15,1);
     lcd.print(x);
}
}

 
