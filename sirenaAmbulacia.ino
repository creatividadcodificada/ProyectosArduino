/*  AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Sirena de policía y ambulancia con Arduino
 *  con tonos de Arduino
 *  
*/

int btn = 2;
int tiempo = 10;
int sonido = 9;

void setup() {

  pinMode(btn, INPUT); // Pulsador para accionar la alarma
  pinMode(sonido, OUTPUT); // Pin para reproducir la frecuencia del tono

}

void loop() {

  if(digitalRead(btn)==HIGH)
  {
    sirenaPolicia(1200,800,1,400,2);
    sirenaPolicia(1100,700,20,20,10);
    sirena2();
    noTone(sonido);
    }
  
}


// sirenaPolicia(frecuencia máxima, frecuencia mínima, divisor, bucle, # de repeticiones) 
void sirenaPolicia(int fMAX, int fMIN, int divisor, int numMAX, int repet)
{
  int fMIN1 = fMIN;
  int fMAX1 = fMAX;
  for(int i =0; i<repet; i++)
  {
    for(int j = 0; j<=numMAX; j++)
    {
      tone(sonido, fMIN1);
      delay(tiempo);
      fMIN1 = fMIN1 + divisor;
      }
    for(int k = numMAX/2; k>=0; k--)
    {
      tone(sonido, fMAX1);
      delay(tiempo);
      fMAX1 = fMAX1 - divisor*2;
      }
    fMIN1 = fMIN;
    fMAX1 = fMAX;  
    }
  } 

//Función para generar un simple cambio de frecuencia 
void sirena2()
{
  for(int l = 0; l<=4; l++)
  {
    tone(sonido, 1200);
    delay(500);
    tone(sonido, 800);
    delay(500);
    }
  }
