## Comunicaciones serie

El protocolo de comunicaciones más sencillo es que ya hemos usado: el protocolo serie.

La forma natural de comunicarse con Arduino es utilizando el puerto serie, siendo este el método de depuración más usado.

En el [siguiente vídeo](https://youtu.be/A6BH4cfqS4k) veremos detalles sobre este protocolo, cómo usarlo en Arduino y cómo leer datos desde Arduino.

Actualización: en el vídeo no aparecen los métodos [**readString**](https://www.arduino.cc/en/Reference.StreamReadString) y [**readStringUntil**](https://www.arduino.cc/en/Reference.StreamReadStringUntil), muy útiles de la librería Serial. Nos facilitan enormemente el recuperar cadena desde el puerto serie.

Os dejo una presentación donde se trata en más detalle "Tema 10 - Comunicaciones serie.pdf"

### Ejemplos de comunicación serie

Control de un led RGB vía serie. Por el monitor serie enviaremos 3 números separados por comas o espacios correspondientes a los niveles de rojo, verde y azul. Al pulsar 'Enter' y enviar el led cambiará de color.

```C++

const int redPin = 3, greenPin = 5, bluePin = 6;

void setup() {
    Serial.begin(9600);
    pinMode(redPin, OUTPUT);pinMode(greenPin, OUTPUT);pinMode(bluePin, OUTPUT); 
}
void loop() {

    while (Serial.available() > 0) {
        // Si hay datos leemos 3 enteros
        int red=Serial.parseInt(), green=Serial.parseInt(), blue=Serial.parseInt();
        if (Serial.read() == '\n') { // si hay fin de linea hemos terminado
            red = 255 - constrain(red, 0, 255); // Ajustamos al rango 0-255
            green = 255 - constrain(green, 0, 255);
            blue = 255 - constrain(blue, 0, 255);
            analogWrite(redPin, red);
            // Ajustamos el brillo de los 3 niveles
            analogWrite(greenPin, green);
            analogWrite(bluePin, blue);
            // Mostramos los datos en hexadecimal en pantalla
            Serial.print(red, HEX);Serial.print(green, HEX);Serial.println(blue, HEX);
        } // fin del if
    } // fin del while
} // fin del loop


```

