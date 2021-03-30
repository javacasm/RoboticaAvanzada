

## Protocolos de comunicaciones

En el [siguiente vídeo](https://www.youtube.com/embed/DePCak9WNPM) hablaremos sobre algunos de los protocolos de comunicaciones más usados, como son I2C y SPI.

La presentación está disponible en el fichero "Tema 10 - Protocolos de comunicaciones.pdf"

### Pines SPI


¿Dónde están los pines SPI en las distintas placas?

![Pines SPI](./images/SPI_pines.png)

Uno de los protocolos de comunicaciones más usados en Arduino es el SPI. Se utiliza para comunicarse con multitud de dispositivos. Cómo norma general, la manera más sencilla de encontrar los pines SPI es en el conector ICSP. Algunas placas los duplican entre los pines digitales, pero otras no.

|Placa| SCK|MOSI|MISO
|---|---|---|---
|Arduino UNO|D13|D11|D12
|Arduino Leonardo|D3|D4|D1
|Arduino Mega|D52|D51|D50

## Ethernet

Si de verdad queremos comunicar nuestro proyecto con internet necesitamos un shield ethernet.

Existen básicamente dos tipos de shields, los basados en el chip Wiznet W5100.

![Arduino Ethernet con W5100](./images/Ethernet_5100.png)

Que usan la librería Ethernet de Arduino’s IDE (cuya documentación podemos encontrar http://arduino.cc/en/Reference/Ethernet) y los basados en el chip [enc28J60](http://www.microchip.com/wwwproducts/Devices.aspx?dDocName=en022889)   

![Módulo Ethernet enc28j60](./images/c28j60.png)

Estos últimos utilizan la librería [ethercard](https://github.com/jcw/ethercard) de JeeLabs.

Las dos admiten esencialmente la misma funcionalidad y se conectan a Arduino por SPI. Sin embargo la diferencia de coste es sorprendente. ¿A qué se debe?:

A que el Wiznet W5100 incluye el stack TCP-IP completamente en hardware mientras que en el enc28J60 es necesario que nuestro microcontrolador realice todas las operaciones por software. Es decir el W5100 libera a nuestro micro de la mayor parte del trabajo duro del acceso a internet, mientras que con el enc28J60, tiene que sufrirlo entero.

Por tanto si tenemos que realizar un proyecto donde se usará mucho acceso a internet claramente necesitaremos la solución hardware.

En [este vídeo](https://youtu.be/s8D1DZWbubg) vamos a ver los detalles de como usar cada uno de ellos.


En el [siguiente vídeo](https://youtu.be/6W_2I--XwrY) comentamos el hardware necesario para comunicarnos por internet.
