## Python

Python es uno de los lenguajes más usados en la actualidad en el mundo de la hardware y software abierto. Es sencillo, muy completo y rápido de aprender.

Nada más sencillo que usar Python para comunicarnos con Arduino. 

En primer lugar hay que instalar **pySerial** https://github.com/pyserial/pyserial. Lo instalamos como nos dice la documentación https://pyserial.readthedocs.org/en/latest/ ejecutando:

```sh
    pip3 install pyserial
```
Para leer datos podemos usar este sencillo programa:

```python
    import serial
    ser = serial.Serial('/dev/tty.usbserial', 9600) ; usamos el puerto adecuado (COMx en windows)
    while True:
        print (ser.readline())
```

Escribir datos a Arduino también es muy sencillo:

```python
      import serial 
      ser = serial.Serial('/dev/tty.usbserial', 9600)
      ser.write('5')
```

Para abrir las conexiones conectaremos al mismo dispositivo (con el mismo nombre) que conectamos el entorno.

En Linux se suele crear un link  entre el dispositivo que se usa y /dev/tty.usbserial para facilitar la programación:

```sh
    sudo ln -s /dev/serialDevi /dev/MYSerial  

```

La mayoría de los recursos asociados a Python y rduino los podemos encontrar en la página de playground http://playground.arduino.cc/Interfacing/Python

### Usando APIs

Una de las características más utilizadas de Python es la facilidad con la que podemos acceder a APIs de terceros (como twitter, facebook, gmail...)

Vamos a ver un ejemplo de cómo acceder a gmail desde nuestro programa de Python http://geekytheory.com/arduino-python-smtp-gmail/

La idea de este proyecto es enviar un correo cuando un sensor produzca una medida considerada peligrosa. Simularemos esta medida con un sensor de distancia, suponiendo que la cercanía de un obstáculo supone un peligro.

El programa Arduino verificará el valor de los sensores y en caso de detectar algo anómalo enviará al programa Python vía Serial y mensaje.

El programa Python en caso de recibir ese mensaje enviará el email con el asunto, mensaje y destinatario preestablecidos.

El código python del ejemplo sería el siguiente:


```python
import serial
import time
import smtplib

USUARIO_GMAIL = 'micorreo@gmail.com'
CONTRASENA_GMAIL = 'micontraseña'
DESTINATARIO = 'destinatario@dominio.com'
REMITENTE = 'micorreo@gmail.com'
ASUNTO = ' ¡ Hay un intruso en su hogar. ! '
MENSAJE = ' ¡ Su sensor de seguridad ha detectado movimiento en su casa. ! '
arduino = serial.Serial('COM4', 9600, timeout = 3.0) #El puerto se abre inmediatamente en la creación de objetos, cuando se da un puerto.
while True:
    lineaLeida = arduino.readline() #Guardo una línea leída desde el puerto serial
    print(lineaLeida) #Imprime la variable mensaje
    if lineaLeida[0] == 'H' : #Si la línea contiene a 'H' envía un correo electrónico
    enviar_correo_electronico() #Envío un correo electrónico
    time.sleep(0.5) #Suspende la ejecución por 0.5 segundos

def enviar_correo_electronico():
    print("Envíando e-mail")
    smtpserver = smtplib.SMTP("smtp.gmail.com",587) #Definimos el objeto 'smtpserver' con smptlib.SMTP, SMTP("",) Administra la conexión SMTP
    smtpserver.ehlo() #Este método prepara envíar un correo electrónico
    smtpserver.starttls() #Pone la conexión con el servidor SMTP en el modo de TLS.
    smtpserver.ehlo()
    smtpserver.login(USUARIO_GMAIL, CONTRASENA_GMAIL) #Iniciamos sesion en el SMTP server de Google
    header = 'To: ' + DESTINATARIO + '\n' #Construimos el 'HEADER' para envíar el correo electrónico
    header += 'From: ' + REMITENTE + '\n'
    header += 'Subject: ' + ASUNTO + '\n'
    print header
    msg = header + '\n' + MENSAJE + ' \n\n' #Concatenamos el'HEADER' y el 'MENSAJE' del correo electrónico
    smtpserver.sendmail(REMITENTE, DESTINATARIO, msg) #Envíamos el correo electrónico
    smtpserver.close() #Cerramos la conexión con el SMTP server de Google

```
### Gráficos

![Graficos con Python](./images/GraficosPython.png)

Instalando la librería matemática MathPlotLib podemos representar datos gráficamente en tiempo real. Más detalles en https://www.instructables.com/id/Plotting-real-time-data-from-Arduino-using-Python-/

El código https://github.com/gregpinero/ArduinoPlot/tree/master  implementa un monitor  https://github.com/gregpinero/ArduinoPlot/blob/master/Arduino_Monitor.py de Arduino que permanentemente está recibiendo datos de Arduino vía puerto serie (por defecto por el COM4 y a 9600 pero fácilmente modificable) y código https://github.com/gregpinero/ArduinoPlot/blob/master/wx_mpl_dynamic_graph.py para ir visualizando los datos a medida que estos llegan

### Guardando datos

Un ejemplo para hacerlo [en windows](https://www.instructables.com/id/Using-an-Arduino-and-Python-to-plotsave-data/) y otro [en linux](https://www.instructables.com/id/Sending-Data-From-Arduino-to-Python-Via-USB/)

### Referencias

Podéis aprender mucho más sobre cómo usar Arduino y Python en estos tutoriales [Tutorial de python y arduino](http://www.toptechboy.com/using-python-with-arduino-lessons/)

[Tutorial sobre lectura y escritura de datos en Python](https://makersportal.com/blog/2018/2/25/python-datalogger-reading-the-serial-output-from-arduino-to-analyze-data-using-pyserial)

[Curso gratuito de python by Google](https://developers.google.com/edu/python/)
