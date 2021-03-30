#!/bin/python

import serial
ser = serial.Serial('/dev/ttyACM0', 9600)
with open('tarjeta.txt', 'w') as f:
    while 1:
        print(ser.readline(), file=f)
