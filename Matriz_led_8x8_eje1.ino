/*  AUTOR: CREATIVIDAD CODIFICADA
 *  www.creatividadcodificada.com
 *  NOMBRE DEL PROYECTO: Impresión de la letra "C" en una matriz led 8x8 con Arduino
*/
const int mensaje[] = {0x7E, 0xFF, 0xE7, 0xC3, 0xC3, 0xC3, 0xE7, 0x66}; // Letra "C" en hexadecimal

const int row[8] = { // Filas
  9,8,7,6,5,4,3,2
  };
const int col[8] = { // Columnas
  10,11,12,13,A2,A3,A4,A5
  };  
  
void setup() {
  for(int i = 0; i<8; i++){ // Designamos las filas y columnas como salidas
    pinMode(row[i],OUTPUT);
    pinMode(col[i],OUTPUT);
    }
}

void loop() {

  for(int k=0; k<8; k++)
  {
    for(int i = 0; i < 8; i++)
    {
      digitalWrite(row[i],HIGH);
      for(int j = 0; j < 8; j++)
      {
        int x0 = bitRead(mensaje[i],j); // Usamos la función bitRead() para descomponer nuestros números hexadecimales
        digitalWrite(col[j],!x0);
        }
      int pot = analogRead(A0);
      int retardo = map(pot, 0, 1023, 2, 500);
      delay(retardo); // Velocidad del barrido
      digitalWrite(row[i],LOW);
      digitalWrite(col[i],LOW);
      }
    }
}
