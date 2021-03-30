/*
   programa de Arduino que juega al juego del dinosaurio de Chrome
   by Francisco Prados
   curso Arduino desde Cero a Experto 2020

*/

#include <Servo.h>

Servo espacio;

// PINES
const int pinServoEspacio = 9;
const int pinLDR = 5;

// DATOS
const int AnguloPulsado = 150;
const int AnguloSinPulsar = 125;

void setup() {
    Serial.begin(9600);
   
   // Servo para pulsar el espacio
   espacio.attach(pinServoEspacio);
   
   // LDR para detectar un dinosaurio
   pinMode(pinLDR, INPUT);
}

/**
 * @brief Funcion que pulsa la barra espaciadora
 */
void pulsarEspacio(){
  
  // Pulsamos
  espacio.write(AnguloPulsado); 
  delay(100); 
  
  // Dejamos de pulsar
  espacio.write(AnguloSinPulsar); 
  delay(100); 
}

void loop(){
 /** Para comprobar lo que esta midiendo el LDR
 Serial.println(analogRead(pinLDR));
 */
 
 if(analogRead(pinLDR) > 180){
    pulsarEspacio();
 }

 delay(10);
}
