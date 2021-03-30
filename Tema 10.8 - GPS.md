## Uso del GPS

Un GPS no es más que un dispositivo que recibe señales de los satélites GPS, las procesa para obtener información sobre la posición y las envía (tramas NMEA) por un puerto de comunicaciones, normalmente vía puerto serie.

En mi caso voy a usar un módulo ATGM336H GPS BDS GNSS de ICStation
![Módulo GPS](http://www.icstation.com/images/big/products/12420_0152.JPG)

Su consumo es muy bajo (25mA) lo que lo hace ideal para sistemas desatendidos.

Su conexión es muy sencilla pues basta con alimentarlo y conectar sus pines Tx y Rx a Arduino y hacer un programa que lea las tramas.

![Conexión GPS](https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/01/NEO_6M_Arduino.png?resize=1024%2C551&ssl=1)

En el programa usaremos la librería SoftwareSerie para poder usar otros pines de Arduino, en concreto vamos a usar los pines 3 y 4

```C++
/*
  * Basado en el codigo de
  * Rui Santos
  * Complete Project Details http://randomnerdtutorials.com
  *
  * modificado por JAVacasM
  */

#include <SoftwareSerial.h>

// leeremos la senial PPS (Pulso Por Segundo) con el pin 12
// Encenderemos el led 13 con esa frecuencia

#define PIN_PPS 12
#define PIN_PULSO 13

// The serial connection to the GPS module
SoftwareSerial ss(4, 3);

void setup(){
  pinMode(PIN_PPS,INPUT);
  pinMode(PIN_PULSO,OUTPUT);

  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){
  while (ss.available() > 0){
    // get the byte data from the GPS
    byte gpsData = ss.read();
    Serial.write(gpsData);

    if(digitalRead(PIN_PPS) == LOW)      // ha cambiado el pulso
      digitalWrite(PIN_PULSO,!digitalRead(PIN_PULSO)); // Invertimos el pin 13
  }

}
```

Hay que recordar que los receptores GPS (y sobre todo los baratos) tardan un tiempo en conseguir suficientes señales de los satélites y necesitan de un espacio abierto para que estas lleguen.

Cuando empiecen a recibirse tramas serán algo así:


      $GPGGA,140817.00,4105.2344,N,00831.54761,W,1,05,2.68,129.0,M,50.1,M,,*42
      $GPGSA,A,3,06,09,30,07,23,,,,,,,,4.43,2.68,3.53*02
      $GPGSV,3,1,11,02,48,298,24,03,05,101,24,05,17,292,20,06,71,227,30*7C


Que nos informa de la posición, altura, etc... Por ejemplo la primera línea nos dice

* Hora de la señal 14:08:17
* Latitud 4105.2344,N
* Longitud 831.54761,W

Podemos procesar estos datos usando librerías por ejemplo [TinyGPSPlus](https://github.com/mikalhart/TinyGPSPlus) que después de descargarla e instalarla podemos usar en el siguiente código

```C++
/*
  * Basado en el codigo de
  * Rui Santos
  * Complete Project Details http://randomnerdtutorials.com
  *
  * modificado por JAVacasM
  */

#include <TinyGPS++.h>
#include <SoftwareSerial.h>


// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(4, 3);

void setup(){
  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){

  while (ss.available() > 0){ // si hay datos serie los procesamos
    gps.encode(ss.read());  
    if (gps.location.isUpdated()){ // Esta actualizado
      Serial.print("Latitude= ");
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= ");
      Serial.println(gps.location.lng(), 6);
    } else {  // Mostramos los satelites y la fecha
      Serial.print("Number os satellites in use = ");
      Serial.println(gps.satellites.value());

      Serial.print("Raw date DDMMYY = ");
      Serial.println(gps.date.value());

    }
  }
}
```

### Referencias


Para aprender más sobre GPS os recomiendo [el artículo de Rui Santos](https://randomnerdtutorials.com/guide-to-neo-6m-gps-module-with-arduino/) del que saqué la información.

Más detalles sobre el módulo GPS en el su [datasheet](http://www.icofchina.com/d/file/xiazai/2016-12-05/b5c57074f4b1fcc62ba8c7868548d18a.pdf).
