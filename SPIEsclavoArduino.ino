/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Comunicación entre dos Arduinos Uno 
 *  con el bus SPI 
 *  
 *  ******* [ARDUINO ESCLAVO] *******
*/  
#include <SPI.h>

volatile byte posicion;
volatile boolean control;
int led = 2;
char mensaje [40];

void setup ()
{
  // Configuramos como salida el pin para el LED
  pinMode(led,OUTPUT);

  // Configura el pin MISO 
  pinMode (MISO, OUTPUT);
  
  // Configuramos el Arduino Uno como esclavo
  SPCR |= bit (SPE);
 
  //Colocamos en la posicion '0' de nuestro registro  
  posicion = 0;
 
  // Variable para controlar si recibimos el mensaje
  control = false;
 
  // Activamos la interrupcion para usar la funcion ISR
  SPI.attachInterrupt();
 
}
 
ISR (SPI_STC_vect)
{
  // Guardamos el byte recibido en una variable auxiliar
  byte aux = SPDR;
 
  // Controlamos el que no sobrepase la dimesion del mensaje 
  if (posicion < sizeof mensaje)
  {
    mensaje[posicion++] = aux;
 
    // controla el ultimo caracter
    if (aux == '\n')
      control = true;
  }
}
 
void loop ()
{
  if(control)
  {
    mensaje[posicion] = 0;
    String mensajeRecibido = mensaje;
    posicion = 0;
    control = false;
    if(mensajeRecibido == "on\n"){
      // Encendemos el led en el Arduino esclavo
      digitalWrite(2,HIGH);
      }
     if(mensajeRecibido == "off\n"){
      // Apagamos el led en el Arduino esclavo
      digitalWrite(2,LOW);
      }
  }
}
