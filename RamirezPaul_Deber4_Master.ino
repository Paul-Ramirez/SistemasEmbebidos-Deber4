/*
 * MASTER
 * Deber #4
 * Autor: Paul Ramirez
 * Objetivo: Comunicacion serial e I2C
 * Fecha: 30/11/2020
*/
#include<LiquidCrystal.h>
#include <Wire.h>
LiquidCrystal lcd(10,9,8,7,6,5);
int cont=0;
String salida,salida2;
String dato2;

void setup() {
  Wire.begin();//indica que es el master
  Serial.begin(9600);
  lcd.begin(16,2);//lcd 16x2
  lcd.setCursor(0,0);
  Serial.println("Ingrese mensaje: ");
  Wire.onReceive(receiveEvent);//evento de recepcion

}

void loop() {
  if(Serial.available()>0){//verifica el dato en la terminal
    char dato=Serial.read();//lectura del dato en la terminal
    Wire.beginTransmission(4);//inicia trnsmison hacia la posicion 4
    Wire.write(dato);//escribe el dato
    Wire.endTransmission();//finaliza transmision
  }
  lcd.setCursor(2,1);
  delay(200);
}

void receiveEvent(int bytes){//evento de recepcion
  while(Wire.available()){//determina si hay bytes para leer
    char dato=Wire.read();//lee el dato
    switch(dato){//codificacion de las palabras
      case 'a':
      salida=salida+"@";
      break;
      case 'b':
      salida=salida+"b";
      break;
      case 'c':
      salida=salida+"c";
      break;
      case 'd':
      salida=salida+"d";
      break;
      case 'e':
      salida=salida+"#";
      break;
      case 'f':
      salida=salida+"f";
      break;
      case 'g':
      salida=salida+"g";
      break;
      case 'h':
      salida=salida+"h";
      break;
      case 'i':
      salida=salida+"!";
      break;
      case 'j':
      salida=salida+"j";
      break;
      case 'k':
      salida=salida+"k";
      break;
      case 'l':
      salida=salida+"l";
      break;
      case 'm':
      salida=salida+"m";
      break;
      case 'n':
      salida=salida+"n";
      break;
      case 'o':
      salida=salida+"*";
      break;
      case 'p':
      salida=salida+"q";
      break;
      case 'r':
      salida=salida+"r";
      break;
      case 's':
      salida=salida+"s";
      break;
      case 't':
      salida=salida+"t";
      break;
      case 'u':
      salida=salida+"$";
      break;
      case 'v':
      salida=salida+"v";
      break;
      case 'w':
      salida=salida+"w";
      break;
      case 'x':
      salida=salida+"x";
      break;
      case 'y':
      salida=salida+"y";
      break;
      case 'z':
      salida=salida+"z";
      break;
    }
    
  }
  Serial.println(salida);//se imprime la codificacion
  Wire.requestFrom(4,4);//recupera informacion desde el esclavo
  if(Serial.available()>0){//verifica el dato en la terminal
    salida2=Serial.read();//se lee el dato en la terminal
    
  }
  lcd.setCursor(0,0);
  lcd.print(salida);//imprime palabra codificada
  
}
