/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
*/
#define LED_PIN 10 // pin del led 
int intensidad = 0; 
void setup()
{
 pinMode(LED_PIN, OUTPUT);
 Serial.begin(9600); // velocidad en baudios 
}
void loop()
{
 while (Serial.available()) { // comprueba si existe algún dato para leer
  char dato = Serial.read(); // Lee el puerto serie 
  switch(dato)
  {
    case 'w': intensidad=intensidad+25; break; // aumenta la intensidad
    case 's': intensidad=intensidad-25; break; // reduce la intensidad
    case 'a': intensidad=0; break; // intensidad al mínimo
    case 'd': intensidad=255; break; // intensidad al máximo
    default: break;
  }
  if(intensidad<=0 || intensidad >255) intensidad = 0; // control para no salirse de los limites
    analogWrite(LED_PIN, intensidad); // Usamos PWM para controlar la intensidad del led
    Serial.println(intensidad); // imprimimos el valor de la intensidad  
 }
}
