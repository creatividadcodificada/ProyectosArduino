/* AUTOR: CREATIVIDAD CODIFICADADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: JUEGO DE LUCES CON 4 LEDS
*/
// variable global volatil para cambiar el efecto de luces
volatile int efectoLed = 0;
// matriz o array para controlar todos los led 
// de mejor forma 
int led[4] = {8,9,10,11};
void setup() {
// Inicamos nuestro pines de salida y que esten apagados 
  for(int i = 0; i<=3; i++)
  {
    // Iniciamos todos los pines 8,9,10,11 como salidas
    pinMode(led[i],OUTPUT);
    //Iniciamos todos los led apagados
    digitalWrite(led[i], LOW);
    }
    //Activamos nuestra interrupcion 
    attachInterrupt(digitalPinToInterrupt(2),cambioEfecto,RISING);
  }

void loop() {
  switch(efectoLed)
  {
    //Primer efecto - Secuencia de Led
    case 0:     
          for(int j=0;j<=3; j++)
          {
            //Encendemos los led
            digitalWrite(led[j],HIGH);
            delay(200);  
            }
           for(int j=3;j>=0; j--)
          {
            //Apagamos lo led
            digitalWrite(led[j],LOW);  
            delay(200);
            }
            break;
      //Segundo Efecto - Enciende y apaga todos los led
      case 1:
            for(int j=0;j<=3; j++)digitalWrite(led[j],HIGH);
            delay(200);
            for(int j=0;j<=3;j++)digitalWrite(led[j],LOW);
            delay(200);
            break;
        //Tercer efecto - Auto fantastico
        case 2:
              for(int i=0;i<=3;i++)
              {
                // Enciende un led
                digitalWrite(led[i],HIGH);
                if(i>0)
                {
                  //Apaga el Led anterior
                  digitalWrite(led[i-1],LOW);
                  }
                delay(200);
                }
              for(int i=3;i>=0;i--)
              {
                digitalWrite(led[i],HIGH);
                if(i<3)
                {
                  digitalWrite(led[i+1],LOW);
                  }
                delay(200);
                }
               break; 
      default: 
              for(int k = 0; k<=3; k++)digitalWrite(led[k], LOW);
              break; 
    }
}
// Nuestra Funcion ISR
void cambioEfecto()
{
  efectoLed++;
  if(efectoLed >2) efectoLed=0;
  }
