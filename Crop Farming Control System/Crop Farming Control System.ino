#include "DHT.h" // DTH lib
#include <SPI.h> // serial interface lib 
#include <SD.h> // sd card lib
#include <SoftwareSerial.h> // serial soft lib
#include <Adafruit_GFX.h>  // Include core graphics library for the display
#include <Adafruit_SSD1306.h>  // Include Adafruit_SSD1306 library to drive the display
//#include <Fonts/FreeMono9pt7b.h>  // Add a custom font
#define DHTPIN 14 // Pin to read sensor
#define DHTTYPE DHT22 // We use a DTH11
#define SDPIN 10 // Pin to read Photoresistor
#define PHOTORESISTORPIN 9 // Pin to read Photoresistor
#define SOILMOISTUREPIN 8 // Pin to read Photoresistor
#define Tx 3 // Pin Tx for SIM800L
#define Rx 2 // Pin Rx for SIM800L 
void updateSerial();

// important variables
File myFile;
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial simSerial(Tx, Rx);
Adafruit_SSD1306 display(128, 64);  // Create display

// initialing variable here improve dynamic memory management
float h, t, m, l;
int sentinel = 2, condition = 0;
String humidity, temperature, light, soilMoisture, toSave;

void setup() {
  
  // used as a max sms
  sentinel = 1;
  
  // start serial
  Serial.begin(9600);
  Serial.println("Initializing");
  simSerial.begin(9600);

  // start display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C

  display.clearDisplay();  // Clear the buffer

  display.setTextColor(WHITE);  // Set color of the text

  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3

  display.setTextWrap(false);  // By default, long lines of text are set to automatically “wrap” back to the leftmost column.

  display.dim(0);  //Set brightness to max

  // check on sd connection
  if (!SD.begin(SDPIN)) {
    Serial.println("SD initialization failed!");
  }

  simSerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  simSerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  simSerial.println("AT+CMGS=\"+ZZxxxxxxxxxx\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();

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
  humidity = "Humidity: " + String(h) + "\n";
  temperature = "Temperature: " + String(t) + "\n";
  light = "Light: " + String(l) + "\n";
  soilMoisture = "Soil Moisture: " + String(m) + "\n";
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

    Serial.print("Success writing to SD");

  } else {

    // if the file didn't open
    Serial.println("error");

  }
  
  if(t<15){
    condition = 1;
  }
  else{
    condition = 0;
  }
  
  // check for max sms and conditions
  if(condition&&(sentinel>0)){
    simSerial.print(""); //text content
    updateSerial();sentinel--;
    simSerial.write(26); // 26 = Ctrl + z in ASCII}

  display.clearDisplay();  // Clear the display so we can refresh

  //display.setFont(&FreeMono9pt7b);  // Set a custom font
  //display.setTextSize(0);  // Set text size

  // Print text:
  display.setCursor(0, 10);  // (x,y)
  display.println("Hello");
   
  // print everythin
  display.display();
  
  // wait 10 minutes
  delay(1000 * 60 * 10);
}


void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    simSerial.write(Serial.read());
  }
  while(simSerial.available()) 
  {
    Serial.write(simSerial.read());
  }
}
