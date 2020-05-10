/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Comunicación entre dos Arduinos Uno 
 *  con el bus I2C 
 *  
 *  ******* [ARDUINO ESCLAVO] *******
*/  
#include <Wire.h>

uint8_t control = 0;
String mens="";
int led = 2;
char buffer[20];

void setup() {
  
  pinMode(led,OUTPUT);
  Wire.begin(1);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
}

void loop() {
  // Controlamos el mensaje recibido desde el maestro
  // para encender o apagar el led
   if (control == 1){
      mens = buffer;
      if(mens == "on")
        digitalWrite(2,HIGH);
      else if(mens == "off")
        digitalWrite(2,LOW);  
      control = 0;  
      memset(buffer,'\0',20); // limpiamos el buffer   
  }
}
void receiveEvent (int howMany)
{
  // Llenamos el mensaje completo a buffer 
  byte* x = buffer;
  while (Wire.available()) { 
    control = 1;
    *x++ = Wire.read(); 
  }
   
}
void requestEvent()
{
  // Enviamos un mensaje en caso 
  // de que la conexion este correcta
  Wire.write("Conexion exitosa"); // Envía 10 bytes                    
}
