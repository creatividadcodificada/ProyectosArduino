/**** AUTOR: Creatividad Codificada ****/
  
  int contador = 0;
  byte leds[5] = {13,12,11,10,9}; 
void setup() {
  //Declaramos salidas y entradas
  pinMode(13,OUTPUT);  
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  pinMode(7,INPUT);
}
void loop() {
  // Lee el boton encender led
  if(digitalRead(8)==HIGH)
  {
    contador++;
    if(contador>5)contador = 0; // control del contador
    cantidad_led(contador);
    }
  // Lee el boton apagar led  
  if(digitalRead(7)==HIGH)
  {
    contador--;
    if(contador<=0)contador = 0; // control del contador
    cantidad_led(contador);
    }
}
// Funcion para encender o apagar los leds
void cantidad_led(byte cont) 
{
    for(byte j=0; j<5;j++)
    {
      digitalWrite(leds[j],LOW);
      }
    for(byte i=0; i<cont;i++)
     {
      digitalWrite(leds[i],HIGH);
      }
    delay(200);
} 
