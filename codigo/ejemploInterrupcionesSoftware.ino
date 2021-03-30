// Curso de Arduino completo

// https://github.com/javacasm/ArduinoCompletoDE2018
// 
// Licencia Creative Commons
// by @javacasm 2018

// Ejemplo de uso de interrupciones software (por tiempo) que hace parpadear un led

#include <TimerOne.h>

  #define PIN_LED 13

  void setup() {

    pinMode(PIN_LED , OUTPUT);

    Timer1.initialize(1000000);   // 500000 microseconds o 0.5 segundo  
    Timer1.attachInterrupt( funcionDisparo ); // establecemos la funcion de disparo
    Timer1.start();  // Arancamos la interrupción

  void loop()   {
     // Mientras podemos hacer en el loop otras cosas...
  }

  void funcionDisparo()  {

    if(digitalRead(PIN_LED) == HIGH ){  // Invertimos el estado del led
        digitalWrite( PIN_LED, LOW);
    } else {
      digitalWrite( PIN_LED, HIGH );
    }
  }
