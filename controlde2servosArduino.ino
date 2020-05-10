/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Manejo de dos servomotres SG90 
 *  con Arduino
 *    
*/ 
#include <Servo.h>
Servo servo1, servo2;
int gradosBoton = 90;
int pinPoten = 0;
int leerPoten;
int gradosPoten;

void setup() {
 //  Enviamos las señales a los servomotores por los pines 9 y 10
 // y los calibramos 
 servo1.attach(9,720,2250);
 servo2.attach(10,720,2250);
 // Configuramos los pines 4 y 5 como entradas 
 pinMode(4,INPUT);
 pinMode(5,INPUT);
}

void loop() {
  // Hacemos dos controles para saber cuando se acciona el pulsador 
  // y aumentar o reducir los grados del eje del servomotor  
 if(digitalRead(4) == HIGH)
  {
    gradosBoton++;
    if(gradosBoton>=180) gradosBoton = 180;
    servo1.write(gradosBoton);
    
  }
   
  if(digitalRead(5) == HIGH)
  {
    gradosBoton--;
    if(gradosBoton<=0) gradosBoton = 0;
    servo1.write(gradosBoton);
    
  }

  // Leemos la señal analogica del potenciometro 
  // y hacemos un mapeo para tener datos de 0 a 180  
  leerPoten = analogRead(pinPoten);
  gradosPoten = map(leerPoten, 0, 1023, 0, 180);
  servo2.write(gradosPoten);
  delay(60); 

  }
void sumarGrados()
{
  gradosBoton++;
  if(gradosBoton>=180)
  {
    gradosBoton=180;
    }
  }
void restarGrados()
{
  gradosBoton--;
  if(gradosBoton<=0)
  {
    gradosBoton=0;
    }
  }
