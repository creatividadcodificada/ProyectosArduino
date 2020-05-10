/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Comunicación entre dos Arduinos Uno 
 *  con el bus SPI 
 *  
 *  ******* [ARDUINO MAESTRO] *******
*/  
#include <SPI.h>

boolean control = false;
String datosLeidos = "";
char datos;
void setup()
{
  Serial.begin (115200); 
  
  // Desactivamos la conexion al esclavo
  digitalWrite(SS, HIGH);  

  // Iniciamos el bus SPI
  SPI.begin();
}

void loop()
{
  // Configuramos el bus SPI con una frecuencia de 2Mhz,
  // la lectura se hace desde el bit mas sisgnificativo
  //  y el modo 0 
  SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
  
  // Activamos el Arduino esclavo
  digitalWrite(SS, LOW);

 // Controlamos si existe algo para leer en el 
 // monitor serie del Arduino maestro y comparamos para 
 // encender o apagar el led en el Arduino esclavo
  if(control) {
    if(datosLeidos == "on\n"){
      for (const char *mensaje = "on\n" ; datos = *mensaje; mensaje++)
        SPI.transfer(datos);
      Serial.print("Arduino Esclavo -> Led encendido\n");
    }
    else if(datosLeidos == "off\n"){
      for (const char *mensaje = "off\n" ; datos = *mensaje; mensaje++)
        SPI.transfer(datos);
      Serial.print("Arduino Esclavo -> Led apagado\n");
    }
    else { 
      Serial.println("Dato no valido!!!");
    }
  datosLeidos = "";
  control = false;
  }

  // Deshabilita el esclavo
  digitalWrite(SS, HIGH);

  // Cerramos la conexion con el bus SPI
  SPI.endTransaction();
  SPI.end();
   
}

// funcion para controlar si existe algo para leer en el 
// monitor Serie del Arduino Maestro 
void serialEvent() { 
  while (Serial.available()) {
    char c = (char)Serial.read();
    datosLeidos += c;
    if (c == '\n') {
      control = true;
    }
  }
}
