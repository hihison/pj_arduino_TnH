import serial
import datetime
from time import sleep
import atexit
import os
import time
from time import ctime
import datetime

arduino_serial = serial.Serial(port='COM4', baudrate=115200, parity='N', stopbits=1, timeout=1)


def getdata():
    with open("log.txt","a") as file :
        arduino_serial.flushInput()
        arduino_serial.flushOutput()
        line = arduino_serial.readline()
        print("[ "+ctime()+" ] "+line.decode('utf-8'))
        file.write("[ "+ctime()+" ] "+line.decode('utf-8'))
           # send = input("SEND TO ARDUINO: ")
           # arduino_serial.write(send.encode())
       

def _main_():
    print("Wait for Arduino...")
    time.sleep(1)
       # if arduino_serial.is_open:
    line = arduino_serial.readline()
    print(line)
    
    inp = str(input("INPUT HERE: "))
    while (inp!= "exit"):
        if (inp == "get"):
            arduino_serial.write(inp.encode())
            time.sleep(1)
            getdata()
        inp = str(input("INPUT HERE: "))
    if (inp == "exit"):      
            arduino_serial.write(inp.encode())
            with open("log.txt","a") as file :
                
                print("[ "+ctime()+" ] "+"exit !!\n")
                file.write("[ "+ctime()+" ] "+"exit !!\n")
                exit()

_main_()
