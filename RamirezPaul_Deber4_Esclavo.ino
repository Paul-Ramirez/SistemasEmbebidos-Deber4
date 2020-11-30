/*
 *Esclavo
 *Autor: Ramirez Paul 
 *Fecha: 30/11/2020
*/
#include <Wire.h>
String salida;
String salida2;
String dato2;
void setup() {
  Wire.begin(4);//indica que es el escalvo y se le da la posicion 4
  Serial.begin(9600);//inicializa comunicacion serial
  Wire.onReceive(receiveEvent);//recibir transmision de datos
  Wire.onRequest(requestEvent);//mensaje de respuesta
  

}

void loop() {
  delay(1000);
}


void receiveEvent(int bytes){//recibir transmision de datos
  //mientras haya bytes para ser leidos
  while(Wire.available()){
    char dato=Wire.read();//dato que se lee de la transmion
    switch(dato){//codificacion de los bytes ingresados
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
  //impresion por comunicacion serial
  Serial.println(salida);
  if(Serial.available()>0){//verifica si hay dato en la terminal
    salida2=Serial.read();//lee el dato en la termianal
  }
  
}

void requestEvent(){//evento de respuesta a la comunicacion
  //si existe algun dato en la terminal virtual
  if(Serial.available()>0){//verifica la informacion en la terminal
    char dato2=Serial.read();//lee el dato requerido
    Wire.beginTransmission(4);//inicia transmision con posicion 4
    Wire.write(dato2);//escribe el dato a enviar
    Wire.endTransmission();//finalizar transmision
    
  }
}
