/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Encendido y apagado de una secuencia de Leds
 *  accionado el pulsador por 3 segundos.
*/
#include <TimerOne.h>
volatile int contadorTiempo;
unsigned int controlTiempo;
boolean control;
void setup() {
  //Iniciar las variables contadorTiempo, controlTiempo y control 
  contadorTiempo = 0;
  controlTiempo = 0;
  control=true;
  
  //configuramos nuestras salidas para los leds
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  //Configuramos el pin 2 para el boton
  pinMode(2,INPUT);
  
  //Iniciamos el timer1
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(ISR_tiempo);
}

void loop() {

  //Controlamos si el boton esta presionado
  if(digitalRead(2) && control == true) encendidoLed(HIGH);
  if(digitalRead(2) && control == false) encendidoLed(LOW);
}

void encendidoLed(int estado)
{
    //Reiniciamos el contadorTiempo a 0 
      contadorTiempo = 0;

      // Controlamos que detecte los 3 segundos presionados
      while(digitalRead(2) && contadorTiempo < 3 ){
        controlTiempo=contadorTiempo;
        }
        if(controlTiempo >= 2)
          {
            for(int i = 0; i < 4; i++)
            {
              // Encendemos en seecuencia los Leds
              digitalWrite(i+8,estado);
              delay(200);
              }
          // hacemos el control para cambiar de estado de los Leds    
          control=!control;
          }
  }
  // Nuestra función ISR
void ISR_tiempo()
{
  contadorTiempo++;
  }
