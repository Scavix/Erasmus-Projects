#include "DHT.h" // DTH lib
#include "CTBot.h" // Telegram bot library
#include "BluetoothSerial.h" // Bluetooth library
#define DHTPIN 14 // Pin to read sensor
#define DHTTYPE DHT11 // We use a DTH11
#define PHOTORESISTORPIN 9 // Pin to read Photoresistor
#define SOILMOISTUREPIN 8 // Pin to read Photoresistor

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

CTBot myBot;
DHT dht(DHTPIN, DHTTYPE);
BluetoothSerial SerialBT;

String ssid  = ""    ; // Wifi name
String pass  = ""; // WIfi pass
String token = ""   ; // Telegran token

float h, t, l, m;
String humidity, temperature, light, soilMoisture, toSend;

void setup() {

  // start serial console and bluetooth
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");
  SerialBT.begin("ESP32");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);
 
  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");

  // init dht
  dht.begin();
}

void loop() {
  // we read data
  h = dht.readHumidity();
  t = dht.readTemperature();
  l = analogRead(PHOTORESISTORPIN);
  m = analogRead(SOILMOISTUREPIN);

  // we check for variable missing
  if (isnan(h) || isnan(t) || isnan(l) || isnan(m)) {
    Serial.println("Failed to read from sensors!");
  }

  // we create a string containing the data to send
  humidity = "Humidity: " + String(h) + "\n";
  temperature = "Temperature: " + String(t) + "\n";
  light = "Light: " + String(l) + "\n";
  soilMoisture = "Soil Moisture: " + String(m) + "\n";
  toSend = humidity + temperature + light + soilMoisture;

  // print to serial
  Serial.print(toSend);

  // print to bluetooth
  SerialBT.print(toSend);

  // a variable to store telegram message data
  TBMessage msg;

  // if there is an incoming message...
  if (myBot.getNewMessage(msg)){
    // ...forward it to the sender
    if(msg.text.equalsIgnoreCase("/DHT")){
      myBot.sendMessage(msg.sender.id, toSend);
    }
    else{
      myBot.sendMessage(msg.sender.id, msg.text);
    }
  }
  
  // wait 2000 milliseconds
  delay(2000);
}
