# Erasmus Projects
 IoT Related projects, University of Macedonia, Erasmus+ 2021

## 1 - Communications systems - Crop Farming Control System

### Materials:
* Arduino based microcontroller (Nano here)
* Arduino based shield (Facultative)
* Dht22 humidity and temperature module
* Photoresistor module
* Screen OLED 128x64 I2C
* Sd card module I2C
* Sd card
* Soil moisture module (Hygrometer)
* Sim card expansion module SIM800L
* Sim Card

### Description:
Ideally the entire system is embedden into an electric cable pit.
The idea is a on-field crop monitor system (the power source cold be also even more green/based using a solar panel).
The environment is controlled by an arduino based microcontroller, we keep track on a sd card of:

* Temperature
* Humidity
* Light
* Soil humidity

In case of detection of cardinal temperatures or favorable conditions for the development of phytopathogenic diseases, we send an sms to the farmer!
It is possible to take the data from the sd card in order to do data analysis!
It is possible to read data through a local Oled terminal in loco!
It is possible to read data through a serial console connecting the pc in loco!

Ps: I want to remember that each plant has different cardinal temperatures/values, so I suggest to choose the correct temperature for one or a specific kind of crops.

## 2 - Mobile and wireless communications systems - Greenhouse Control System

### Materials:
* Esp32 based microchip with Wi-fi and Bluetooth
* Dht11 humidity and temperature module
* Photoresistor module
* Soil moisture module (Hygrometer)
* Telegram
* Android Bluetooth device
* Relay Module
* Lights/pumps (everything that can be turned on/off)
* Water level sensor

### Description:
That's a more indoor version of the previous one, in fact we use a dth11 (smaller temperature range) and we use the esp8266 Wi-fi/Bluetooth to access data!
The idea for this is a home based monitor for plants.
The environment is controlled by an esp32 based microchip, we read (and not keep record) data of:

* Temperature
* Humidity
* Light
* Soil humidity

Every data request is in real time!
Telegram Commands are directly written into the Telegram Bot!
It is possible to connect through bluetooth to read the data!
It is possible to read data connecting pc through a serial console in-loco!
It is possible to use telegram as a remote controller to turno off and on things!
