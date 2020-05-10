/* AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Comunicación entre dos Arduinos Uno 
 *  con el bus I2C 
 *  
 *  ******* [ARDUINO MAESTRO] *******
*/  
#include <Wire.h>

boolean control = false;
String datosLeidos = "";
char datos;

void setup() {
  
  Serial.begin(9600);
  // Iniciamos el bus I2C 
  Wire.begin();
}

void loop() {
  if(control) {
    // Preparamos 16 bits para ser leidos desde el esclavo
    Wire.requestFrom(1, 16);    
    while(Wire.available())    
    { 
      char c = Wire.read();   
      Serial.print(c);        
    }

    //Controlamos los datos para encender o apagar el led
    //Enviamos los bit al esclavo 
    if(datosLeidos == "on\n"){
      Wire.beginTransmission(1);
      Wire.write("on");
      Serial.println(" - Led encendido");
      Wire.endTransmission();
    }
    else if(datosLeidos == "off\n"){
      Wire.beginTransmission(1);
      Wire.write("off");
      Serial.println(" - Led apagado");
      Wire.endTransmission();
    }
    else { 
      Serial.println(" - Mensaje no valido!!!");
    }
  datosLeidos = "";
  control = false;
  }
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
