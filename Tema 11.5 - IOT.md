
## [¿Qué es IOT?](https://es.wikipedia.org/wiki/Internet_de_las_cosas)

![IOT](https://upload.wikimedia.org/wikipedia/commons/f/f2/Internet_de_las_Cosas.jpg)

(De Drawed by Wilgengebroed on Flickr - Translated by Prades97, CC BY-SA 3.0, https://commons.wikimedia.org/w/index.php?curid=32745149)

# IOT (Internet de las cosas)

¿Qué dispositivos te gustaría controlar remotamente?

* Calefacción.
* Aire acondicionado.
* Encender la cocina para calentar la comida antes de que lleguemos a casa.
* ¿Estás seguro que se han apagado todas las luces de la casa al salir?.
* Una alarma que nos avise de si hay algún problema cuando no estamos en casa.
* Poder ver el estado de un familiar remotamente.
* Controlar el ejercicio que hace durante un día para así motivarte a hacer más.
* Todas las aplicaciones que si tu curro de la domótica de una casa.

## Características de los dispositivos IOT

* Bajo consumo o mejor autosuficiente (un panel solar y una batería). Si tiene una pulsera de actividad sabrá que es necesario cargarla una vez al mes.
* Conectividad con otros dispositivos como puede ser un teléfono móvil ya sea por medio de Bluetooth y /o WiFi.
* Medir algo: actividad, temperatura, consumo.
* Almacenar los datos, que se guardan hasta que se vuelve a sincronizar.
* Estos datos se suelen subir a páginas web (thingspeak, blynk, adafruit, Cayenne, etc) Dónde se almacenan, y dónde posteriormente podemos construir nuestros graficos e informes.

## Proyectos

Veamos algunos de los proyectos en los que podríamos trabajar:

* Estación meteorológica meditemos las magnitudes Atmosférica, mostrando los datos, guardando los y publicándolos en internet parado su posterior análisis.

* Medida de consumo y fomento de la eficiencia energética: mediremos el consumo de nuestro propio equipo y veremos como a medida que vamos incluyendo más componentes el consumo se hace mayor. Podríamos podríamos adaptar este sistema aún uso real dentro de la casa y viendo el consumo de los electrodomésticos.

* Control remoto de componentes mediante el uso de un relé vamos a poder encender y apagar dispositivo remotamente con nuestro sistema bien por el cambio de alguna tela sistemas que medimos o bien por accionamiento externo.

* Medida de calidad del aire. Usaremos sensores de medida de partículas para determinar la calidad del aire al mismo tiempo también mediremos en el contenido en gases y los parámetros atmosféricos. Publicaremos todos estos datos en una página web para poder comparar la medida en diferentes lugares.

## Algunos ejemplos:

* Pulsera para medir la actividad física.
  * Su batería dura unos ¡¡¡30 días!!!
  * Almacena sus datos (en local) y cuando puede se sincroniza (guardando datos en la nube).
  * Sólo proporciona información que luego vemos en otros dispositivos.
* Sistema de riego inteligente.
  * Un Arduino que mide la humedad y decide si activar o no una bomba de agua es una prueba de concepto.
  * Sistema de riego para una instalación de gran tamaño:
    * Cientos/miles de sensores de humedad.
    * Multitud de puntos de riego (válvulas/bombas).
    * Hacemos un datamining sobre los datos de humedad y se activan los puntos de riego.

### Qué le pedimos al IOT

* Inteligencia:
    * [Niveles](http://www.domodesk.com/a-fondo-que-es-el-internet-de-las-cosas): identidad, ubicación, estado, contexto, criterio. Ejemplo: los cientos de sensores de humedad de una gran explotación. Un nivel más de Inteligencia sería incluir predicción (por ejemplo la atmosférica: si sabemos a que va llover, esperamos antes de regar).
* Arquitectura
  * [Protocolos](http://www.domodesk.com/a-fondo-que-es-el-internet-de-las-cosas): Cable, Wifi, Zigbee, bluetooth, GSM (y todas sus Gs), ...
  * M2M: Comunicación Machine To Machine.
    * Un drone recoge datos del nivel de suciedad de los paneles solares.
    * Envía los datos  a la central.
    * Cuando el nivel es el adecuado se activa el robot de limpieza en determinada zona.


## ¿Cómo hacerse un IOT?

¿Qué necesito?

## [Arquitectura de un sistema completo IOT](https://polaridad.es/grafica-sensor-internet-de-las-cosas-iot/)

![iot](https://polaridad.es/wp-content/uploads/2016/04/Esquema-presentaci%C3%B3n-datos-internet-de-las-cosas-IoT-con-JavaScript-en-una-p%C3%A1gina-web-HTML-con-JavaScript.png)



## Ejemplos sencillos

[Sensores de temperatura online](https://randomnerdtutorials.com/esp8266-ds18b20-temperature-sensor-web-server-with-arduino-ide/)


https://github.com/wemos/D1_mini_Examples/tree/master/examples/01.Basics

https://www.wemos.cc/product/relay-shield.html


## Modelos

### Familia del ESP [Variedades](https://frightanic.com/iot/comparison-of-esp8266-nodemcu-development-boards/)

* ESP8266

  ![esp8266](https://camo.githubusercontent.com/81389b8a0f9eaabf7fe5555f2cf3c0f970498841/687474703a2f2f727562656e736d2e636f6d2f77702d636f6e74656e742f75706c6f6164732f323031352f30312f657370383236362d333030783232352e6a7067)
* NodeMCU

  ![nodeMCU](https://github.com/javacasm/NodeMCU-tutorial/raw/master/images/MiNodeMCU_pcb.jpg)

* ESP32

Mi elección a día de hoy: [Wemos](https://github.com/javacasm/WeMos_ESP8266)

![wemos](https://github.com/javacasm/WeMos_ESP8266/raw/master/images/pcb.jpg)


### ¿Puedo usar arduino? [SI](https://programarfacil.com/esp8266/como-programar-nodemcu-ide-arduino/)

[¿Cómo se hace?](https://github.com/javacasm/ESP-Tutorial)

[Ejemplos](https://github.com/javacasm/ESP-Tutorial/blob/master/Referencias.md)

En este enlace puedes ver algunos [royectos con ESP8266](https://programarfacil.com/esp8266/proyectos-con-esp8266-iot/?utm_content=buffer619c6&utm_medium=social&utm_source=twitter.com&utm_campaign=buffer).

[Usando ESP8266](https://github.com/javacasm/ESP8266_Tutorial)

[Usando NodeMCU](https://github.com/javacasm/NodeMCU-tutorial)

### Configurar tu ESP8266

![conf](https://pbs.twimg.com/media/C3fobewWEAAzsV3.jpg:large)

[Estacion meteo](https://www.instructables.com/id/ESP8266-Weather-Widget/)


[IOT Cloud video](https://www.youtube.com/watch?v=Ymi7DNY4vNg&t=2s)

[Serie de vídeos sobre tu propio IOT](https://www.youtube.com/watch?v=g1j-Pta2QAs)


## IOT Con cable

[Controla tu casa desde internet con arduino](https://randomnerdtutorials.com/arduino-ethernet-web-server-with-relay/) Coste: 10+5+2€

