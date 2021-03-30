import serial #Importa la información del Serial de Arduino
import matplotlib.pyplot as plt #Importa la libreria Matplotlib para hacer gráficos
from drawnow import * #Uso de gráficos en tiempo real importando cualquier valor
import numpy as np #Importa la libreria Numpy
import csv #Importa la libreria (para guardar archivos)
from datetime import datetime
valores = [] #Matriz de los valores de Arduino
plt.ion() #Decir a matplotlib que desea que el modo interactivo grafique datos en vivo
serialArduino = serial.Serial('com3', 9600) #Creando nuestro objeto serial llamado serialArduino
def plotValues(): #Crear una función a nuestro estilo
 plt.title('Modulación del potenciometro en Arduino') #Imprime el titulo de la grafica
 plt.grid(True) #Imprime un grid en el grafico
 plt.ylabel('Valores') #Imprime los valores en el eje y
 plt.plot(valores, 'r*-', label='Valores potenciometro') #Grafica los valores en una linea roja con puntos, y crea un recuadro
 plt.legend(loc='upper right') #Coloca el recuadro en la parte superior derecha

for i in range(0,50): #Leemos 50 datos
 valores.append(0) #Este método nos permite agregar nuevos elementos a una lista.

while True: #El loop while que es el loop para siempre
 while (serialArduino.inWaiting()==0): #Espera hasta que exista valores
 pass #no hace nada
 valores_leidos = serialArduino.readline() #Lee la línea de texto desde el puerto serie
 valores_enteros = int(valores_leidos) #Transforma los valores leidos en valores enteros
 Fecha = datetime.now() #Fecha actual
 fecha = Fecha.strftime('%Y/%m/%d %H:%M:%S') #Fecha sin milisegundos
 print('Fecha: ',fecha) #Imprime la fecha en Python
 print('Valor del potenciometro: ',valores_enteros) #Imprime los valores del potenciometro en Python
 valores.append(valores_enteros)
 valores.pop(0) #Esto nos permite ver los últimos 50 puntos de datos
 drawnow(plotValues) #Grafica los valores en tiempo real
 #Guardamos los datos en un archivo.csv
 archivo = open('Potenciometro.csv','a') #Abre un archivo con el nombre de "Potenciometro" añadiendo valores
 archivo.write('%s'%fecha) #Imprime la fecha en un archivo .csv
 archivo.write(';') #Separador de columna
 archivo.write('%s\n'%valores_enteros) #Imprime los valores en un archivo .csv
 archivo.close() #Cierra el archivo
