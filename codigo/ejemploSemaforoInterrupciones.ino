// Curso de Arduino completo

// https://github.com/javacasm/ArduinoCompletoDE2018
//
// Licencia Creative Commons 
// by @javacasm 2018



// Esto es un semáforo hecho con 3 Leds conectados a las patillas 7, 8 y 9
//
// Para hacer el cambio entre estados se usan interrupciones por tiempo

#include <TimerOne.h>

#define ROJO        7
#define AMARILLO    8
#define VERDE       9

#define BASE_TIEMPO 100000
#define DURACION_ROJO     50*BASE_TIEMPO
#define DURACION_VERDE    10*BASE_TIEMPO
#define DURACION_AMARILLO 5*BASE_TIEMPO


void setup() {
  pinMode(ROJO,OUTPUT);
  pinMode(VERDE,OUTPUT);
  pinMode(AMARILLO,OUTPUT);
  

  Timer1.initialize(DURACION_ROJO);
  Timer1.attachInterrupt(semaforo);
  
  digitalWrite(ROJO,HIGH);      // encendemos el rojo
  digitalWrite(VERDE,LOW);      // apagamos el verde
  digitalWrite(AMARILLO,LOW);   // apagamos el amarillo
}

int estado = 0; // Se usa 0 para rojo, 1 para verde y 2 para ámbar
void semaforo() {
  switch (estado) {
    case 0: // Estaba en rojo, cambia a verde, que dura menos tiempo
      digitalWrite(ROJO,LOW);      // apagamos el rojo
      digitalWrite(VERDE,HIGH);      // encendemos el verde
      digitalWrite(AMARILLO,LOW);   // apagamos el amarillo
      Timer1.setPeriod(DURACION_VERDE);
      break;
    case 1: // Estaba en verde, cambia a ámbar, que dura todavía menos
      digitalWrite(ROJO,LOW);      // apagamos el rojo
      digitalWrite(VERDE,LOW);      // apagamos el verde
      digitalWrite(AMARILLO,HIGH);   // encendemos el amarillo
      Timer1.setPeriod(DURACION_AMARILLO);
      break;
    case 2: // Estaba en ámbar, cambia a rojo y restablece el periodo original
      digitalWrite(ROJO,HIGH);      // encendemos el rojo
      digitalWrite(VERDE,LOW);      // apagamos el verde
      digitalWrite(AMARILLO,LOW);   // apagamos el amarillo
      Timer1.setPeriod(DURACION_ROJO);
      break;
  }
  estado = (estado + 1) % 3;   // Pasamos de un estado a otro pasando del 2 al 0
}

void loop() {

}
