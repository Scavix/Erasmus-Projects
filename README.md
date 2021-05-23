# Erasmus Projects
 IoT Related projects, University of Macedonia, Erasmus+ 2021

## 1 - Communications systems - Crop Farming Control System

### Materials:
* Arduino based microcontroller
* Arduino based shield (Facultative)
* Dht22 humidity and temperature module
* Photoresistor module
* 16x4 lcd screen module (scl)
* Sd card module
* Sd card
* Soil moisture module
* Sim card expansion module

### Description:
Ideally the entire system is embedden into an electric cable pit.
The idea is a on-field crop monitor system (the power source cold be also even more green/based using amsolar panel).
The environment is controlled by an arduino based microcontroller, we keep track on a sd card of:
* Temperature
* Humidity
* Light
* Soil humidity
We have an in-loco lcd terminal and in case of cardinal temperatures "jump" or favorable conditions for the development of phytopathogenic diseases we send an sms to the farmer.
It is also possible to read data through a serial console in loco.

Ps: I want to remember that each plant has different cardinal temperatures/values, so I suggest to choose the correct temperature for one or a specific kind of crops.

## 2 - Mobile and wireless communications systems - Greenhouse Control System

### Materials:
* Esp8266/32 based microchip with Wi-fi and Bluetooth
* Dht11 humidity and temperature module
* Photoresistor module
* Soil moisture module

### Description:
That's a more indoor version of the previous one, in fact we use a dth11 (smaller temperature range) and we use the esp8266 Wi-fi/Bluetooth to access data!
The idea for this is a home based monitor for plants.
The environment is controlled by an esp8266 based microchip, we read (and not keep record) data of:
* Temperature
* Humidity
* Light
* Soil humidity
Commands are directly programmed into the Telegram bot and every data request is in real time!
It is also possible to read data through a serial console in loco.
