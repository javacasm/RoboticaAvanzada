// Curso de Arduino completo

// https://github.com/javacasm/ArduinoCompletoDE2018
// 
// Licencia Creative Commons
// by @javacasm 2018



// Ejemplo de scroll de 5 leds al estilo cylon o kit (coche fantastico)

unsigned char upDown=1;  // Indica si vamos hacia arriba o hacia abajo

unsigned char cylon=0; // será el led que encendemos de 0 a 4

void setup() {
    DDRB = B00011111; // Arduino port B pines 0 to 4 como salida
}

void loop() {
  if ( upDown == 1 ) { // Vamos hacia arriba
    cylon++;  // Pasamos al siguiente
    if(cylon>=4) {  // Si llegamos a 4 tenemos que empezar a ir hacia abajo
        upDown=0;
    }
  } else {
    cylon--;  // Vamos hacia abajo
    if ( cylon == 0 ) {  // Si llevamos abajo (0) empezamos a subir
      upDown=1;
    }

  }
  PORTB = 1 << cylon; // Rotamos a la derecha determinado numero de veces el led
  delay(150); // Esperamos un poquito

}
