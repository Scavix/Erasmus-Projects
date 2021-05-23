#include "DHT.h" // DTH lib
#include "CTBot.h" // Telegram bot library
#define DHTPIN 14 // Pin to read sensor
#define DHTTYPE DHT11 // We use a DTH11
#define PHOTORESISTORPIN 9 // Pin to read Photoresistor
#define SOILMOISTUREPIN 8 // Pin to read Photoresistor


CTBot myBot;
String tmp = "dht";
DHT dht(DHTPIN, DHTTYPE);

String ssid  = ""    ; // Wifi name
String pass  = ""; // WIfi pass
String token = ""   ; // Telegran token

void setup() {

  // start serial console
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

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
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float l = analogRead(PHOTORESISTORPIN);
  float m = analogRead(SOILMOISTUREPIN);

  // We check for variable missing
  if (isnan(h) || isnan(t) || isnan(l) || isnan(m)) {
    Serial.println("Failed to read from sensors!");
  }

  // Print to serial
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\n");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C\n");
  Serial.print("Light:");
  Serial.print(l);
  Serial.print("\n");
  Serial.print("Soil Moisture:");
  Serial.print(m);
  Serial.print("\n");

  // We create a string containing Temperature and Humidity
  String humidity = "Humidity: " + String(h) + "\n";
  String temperature = "Temperature: " + String(t) + "\n";
  String light = "Light: " + String(l) + "\n";
  String soilMoisture = "Soil Moisture: " + String(m) + "\n";
  String toSend = humidity + temperature + light + soilMoisture;
  
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
