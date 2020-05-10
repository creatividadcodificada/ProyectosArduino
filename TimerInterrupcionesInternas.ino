/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Encendido de Leds con Timers
*/
volatile unsigned int contador = 8;
void setup()
{
//configuramos nuestro pines de salida para los leds
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
   
  //deshabilitamos las interrupciones
  noInterrupts();

// configuracion de del Timer1 de 16 bits en modo CTC y prescales de 1024
  TCCR1A = 0;                 
  TCCR1B = 0; 
  TCCR1B |= (1 << WGM12)|(1<<CS10)|(1 << CS12);

//Inicializamos el contador               
  TCNT1  = 0;

// configuramos nuestro registro de comparacion para 1 segundo
  OCR1A = 15624;

//configuramos el desbordamiento             
  TIMSK1 |= (1 << OCIE1A);  

  interrupts();
}
  void loop()
  {
  //.....
  }
  void encenderLed(byte led)
  {
    digitalWrite(led, !digitalRead(led));
    }
  ISR(TIMER1_COMPA_vect)          
  {
    encenderLed(contador);
    contador++;
    if(contador>11)contador = 8;
  }
