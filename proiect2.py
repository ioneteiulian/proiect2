import time
import serial
import turtle

b = turtle.Screen()

try:
    ser = serial.Serial(
    port='COM4',
    baudrate=9600,
    timeout=1)
except:
    print('Please check the port')
low =[]
R = 0
G = 0
B = 0
nr = 0
while 1:
    RGB = str(ser.readline().decode('ascii'))
    print(RGB)
    tmp=""
    new=[]
    count = 0
    for i in RGB:
        if i==",":
            if count == 0:
                R = int(float(tmp))
                count = count + 1
            elif count == 1:
                G = int(float(tmp))
                count = count + 1
            elif count == 2:
                count = 0
            new.append(tmp)
            tmp=""
        elif i != "-":
            tmp=tmp+i
        if tmp:
            B = int(float(tmp))
    print(R)
    print(G)
    print(B)
    if R > 255:
        R = 255
    if G > 255:
        G = 255
    if B > 255:
        B = 255
    if R < 16:
        red = "0" + str(hex(R))[2:]
    else: red = str(hex(R))[2:]
    if G < 16:
        green = "0" + str(hex(G))[2:]
    else: green = str(hex(G))[2:]
    if B < 16:
        blue = "0" + str(hex(B))[2:]
    else:  blue = str(hex(B))[2:]
    
        
    color = "#" + red + green + blue
    if nr > 1:
        b.bgcolor(color)
    nr = nr + 1
        
