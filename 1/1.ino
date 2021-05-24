#include "DHT.h" // DTH lib
#include <SPI.h> // serial interface lib 
#include <SD.h> // sd card lib
#define DHTPIN 14 // Pin to read sensor
#define DHTTYPE DHT22 // We use a DTH11
#define SDPIN 10 // Pin to read Photoresistor
#define PHOTORESISTORPIN 9 // Pin to read Photoresistor
#define SOILMOISTUREPIN 8 // Pin to read Photoresistor

// variable for file
File myFile;
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  // start serial console
  Serial.begin(9600);
  Serial.println("Starting Program");

  // check on sd connection
  if (!SD.begin(SDPIN)) {
    Serial.println("SD initialization failed!");
  }

  // init dht
  dht.begin();
}

void loop() {
  // we read data
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float l = analogRead(PHOTORESISTORPIN);
  float m = analogRead(SOILMOISTUREPIN);

  // we check for variable missing
  if (isnan(h) || isnan(t) || isnan(l) || isnan(m)) {
    Serial.println("Failed to read from sensors!");
  }

  // we create a string containing the data to send
  String humidity = "Humidity: " + String(h) + "\n";
  String temperature = "Temperature: " + String(t) + "\n";
  String light = "Light: " + String(l) + "\n";
  String soilMoisture = "Soil Moisture: " + String(m) + "\n";
  String toSave = humidity + temperature + light + soilMoisture;

  // print to serial
  Serial.print(toSave);

  // open file
  myFile = SD.open("data.txt", FILE_WRITE);

  
  if (myFile) {
  
    // save on file
    Serial.print("Writing to test.txt...");
    myFile.println(toSave);

    // close the file:
    myFile.close();

    Serial.print("Succes writing to SD");

  } else {

    // if the file didn't open
    Serial.println("error");

  }

  // wait 10 minutes
  delay(1000 * 60 * 10);
}
