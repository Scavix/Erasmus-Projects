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

Ps: I want to remember, also because I have an agricultural background, that each plant has different cardinal temperatures/values, so choosing I suggest to choose the correct temperature for one or a specific kind of crops.

## 2 - Mobile and wireless communications systems - Greenhouse Control System

### Materials:
* Esp8266 based microcontroller with Wi-fi and Bluetooth
* Dht11 humidity and temperature module
* Photoresistor module
* Soil moisture module

### Description:
That's a more indoor version of the previous one, in fact we use a dth11 (smaller temperature range) and we use the esp8266 Wi-fi/Bluetooth to access data!
Commands are directly programmed into the Telegram bot we use here and every data request is in real time!
