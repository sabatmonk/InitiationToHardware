import json
import serial
import time
import datetime as dt

ser = serial.Serial('/dev/ttyUSB0', 9600, timeout = 1)
temperature = 0
lightLevel = 0
moistureLevel = 0
readOut = 0   #chars waiting from laser range finder

print ("Starting up")
connected = False

while True:
    while True:
        try:
            time.sleep(2)
            readOut = ser.readline()
            jsonDecoded = json.loads(readOut)
            datas = jsonDecoded["data"]
            for sensorData in datas:
                if sensorData["sensor"] == "temperature":
                    temperature = sensorData["reading"]
                if sensorData["sensor"] == "light":
                    lightLevel = sensorData["reading"]
                if sensorData["sensor"] == "moisture":
                    moistureLevel = sensorData["reading"]
            print ("time: ", dt.datetime.now())
            print ("temperature: ", temperature)
            print ("light: ", lightLevel)
            print ("moisture: ", moistureLevel)
            break
        except:
            time.sleep(2)
            pass
    lightCommand = 0
    pumpCommand = 0
    #check that its dark and whithin hours where there should be light
    if(lightLevel<100 and dt.datetime.now().hour<18 and dt.datetime.now().hour>8):
        lightCommand = 1
    if(moistureLevel<50):
        #arbitrary value, DO NOT TRUST THIS TO WATER YOUR PLANTS, you should find a way to calculate how long pump should run.
        pumpCommand = int(((100-moistureLevel)/10)*1)
    commands = {
    "light":lightCommand,
    "pump":pumpCommand
    }
    ser.write(json.dumps(commands).encode())
    time.sleep(2+pumpCommand)
    ser.flush() #flush the buffer
