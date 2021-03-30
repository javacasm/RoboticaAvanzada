### Introducción a la programación con Bitbloq

Bitbloq es un entorno de programación visual por bloques que nos permite programar nuestra placa Arduino o compatible de forma sencilla, evitando la complejidad de las sentencias C++.

Podemos acceder directamente desde su web <http://BitBloq.bq.com/>

Como verás cuando entres a su página, funciona con Chrome en todos los sistemas operativos, y el se encarga de avisarte si necesitas drivers o cambiar algo en tu sistema.

A lo largo de estos vídeos veremos algunas de sus características más importantes. Puedes encontrar más tutoriales en la página [oficial de BitBloq](http://diwo.bq.com/tag/bitbloq/)

Veamos un ejemplo sencillo:

![parpadeo](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/1%20parpadeo.png)

[Vídeo de ejemplo básico](https://youtu.be/rOdMRhhQTUs)



[Vídeo "Cómo ver código C++ de un programa BitBloq"](https://youtu.be/cg1YNVSprdo)

Desde BitBloq siempre podemos ver el código Arduino generado. De momento no podemos modificar este código pero si copiarlo y llevarlo al IDE de Arduino

[Vídeo "Transfiriendo el programa BitBloq a Arduino"](https://youtu.be/gMe2YDgUUQE)

Bitbloq nos permite programar nuestro Arduino sin instalar (prácticamente) nada en nuestro ordenador. Sólo tenemos que pulsar sobre el botón cargar lo que hace que se compile el código, se detecte la placa y se envíe el programa a nuestro Arduino

## Sentencias de control

[![Vídeo sobre sentencias de control ](https://img.youtube.com/vi/dakh7MTxpBg/0.jpg)](https://youtu.be/dakh7MTxpBg)

[Vídeo sobre sentencias de control ](https://youtu.be/dakh7MTxpBg)


Las sentencias de control son aquellas que nos permite modificar el orden o el modo en el que se ejecutan los bloques de nuestro programa.

##### Variables

Para utilizar las sentencias de control necesitaremos el concepto de variables: que no es otra cosa que un lugar donde almacenar un valor que puede se modificar si así lo queremos

[![Video: Vídeo sobre variables](https://img.youtube.com/vi/Os-8oHBKsQU/0.jpg)](https://youtu.be/Os-8oHBKsQU)

[Video: Vídeo sobre variables](https://youtu.be/Os-8oHBKsQU)


Con las variables podemos realizar operaciones matemáticas

[Vídeo sobre operaciones con variables](https://youtu.be/nvRUCZERScE) 


![ejemplo](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/operaciones%20variables.png)

### Sentencias de control

Vamos a ver las sentencias de control que nos van a permitir decidir cómo se van ejecutando las órdenes de nuestro programa, si se repiten, si se ejecutan en función de una u otra razón

[![Vídeo sobre sentencias de control](https://img.youtube.com/vi/0Af8VdF6h24/0.jpg)](http://youtu.be/0Af8VdF6h24)

[Vídeo sobre sentencias de control](http://youtu.be/0Af8VdF6h24)

### Bucle **for**

Empezamos por la sentencias **for** que nos va a permitir decir que una parte de nuestro programa se repita un número determinado de veces.

[![Vídeo sobre bucle for](https://img.youtube.com/vi/mIAgTdc4oC8/0.jpg)](https://youtu.be/mIAgTdc4oC8)

[Vídeo sobre bucle for](https://youtu.be/mIAgTdc4oC8)


![bucle for](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/bucle%20for.png)

Necesitamos declarar una variables que actuará como contador y definir el valor inicial que tendrá la variable y el final, realizándose tantos como pasos como valores enteros haya entre ambas.

### Bucle **while**

También podemos decidir que se repitan unas sentencias en función de una determinada condición usando la sentencia **while**

[![Vídeo bucloe While](https://img.youtube.com/vi/RVcaaz1NYjk/0.jpg)](https://youtu.be/RVcaaz1NYjk)

[Vídeo bucle While](https://youtu.be/RVcaaz1NYjk)


![bucle while](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/bucle%20mientras.png)

Usaremos la sentencia de control **while** para los bucles donde el número de veces que se repite no está definido desde el principio

### Bloque **if** : sentencias condicionales

Una sentencia condicional permite decidir si se ejecutan o no determinadas órdenes

[Vídeo sobre sentencias condicionales](http://youtu.be/dXpDCOzsO2U)

[vídeo sentencias if](https://youtu.be/RTtn_77pZY4)

![condicional](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/condicionales.png)

Las sentencias condicionales permiten ejecutar un código y otro según se cumpla o no una determinada condición. Esta condición será una validación que definiremos con operandos.

Podemos hacer que en caso de que se cumpla se ejecute un código (es el bloque if) y en caso de que no se cumpla la condición se ejecute otro (bloque else). Veamos un ejemplo

[vídeo: condicionales](https://youtu.be/-f_htl5TQN8)


![ejemplo](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/concional%20compleja.png)

### Condicionales-complejas

[vídeo: condiciones complejas](http://youtu.be/en_Y-_wVyO0) 

![Condiciones\_lógicas](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/concional%20compleja.png)

La condición que determina si se ejecuta un bloque u otro o si salimos de un bloque while puede contener varias comprobaciones.

Entre estas condiciones utilizaremos operadores lógicos que pueden ser AND o OR.

-   Estas condiciones se tendrán que cumplir todas en el caso del operador AND.

-   Con que se cumpla una de ellas se dará por válida toda la condición.

### Envío de datos al pc

En el siguiente Vídeo vamos a ver cómo enviar información entre Arduino y el PC usando Bitbloq

[Vídeo: comunicacion serie](http://youtu.be/uAy_reYl8_Y) 


[Vídeo enviando datos al PC](https://youtu.be/hy9t76RLeBU)

![serial](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/comunicacion%20serie.png)

Podemos enviar contenidos entre nuestra placa y el PC usando las sentencias de comunicaciones. Usaremos print para enviar algo (puede ser el valor de una variable o un texto) al PC o println para enviar y pasar a la siguiente línea.

### Variables locales vs variables globales

En el siguiente vídeo hablamos sobre los diferentes tipos de variables dentro de un programa

[Vídeo: tipos de variables](https://youtu.be/U3ulo7rAE58) 


![ejemplo](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/variables%20globales.png)

Podemos definir variables locales o globales. Una variable global estará definida y por tanto mantendrá su valor en todo el programa, mientras que una variable local solo se definirá donde se haya declarado.

Las variables globales mantienen su valor entre las distintas iteraciones que se realizan del programa.

#### Creando bucles sin sentencias de control

Podemos usar la forma cíclica (y unas variables globales) en la que se ejecutan los programas en Arduino para hacer un bucle sin más estructuras de control que una simple variable global

![ejemplo](https://raw.githubusercontent.com/javacasm/ArduinoBasico/master/bitbloq/ejemplo%20bucle%20arduino.png)


