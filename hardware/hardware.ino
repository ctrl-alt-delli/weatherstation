//##################################################################################################################
//##                                      ELET2415 WEATHER STATION CODE                                   ##
//##                                                                                                              ##
//##################################################################################################################

// LIBRARY IMPORTS
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <rom/rtc.h> 
#include <math.h>  // https://www.tutorialspoint.com/c_standard_library/math_h.htm 
#include <ctype.h>

// ADD YOUR IMPORTS HERE
#include "uwi.h"


#ifndef _WIFI_H 
#include <WiFi.h>
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef ARDUINO_H
#include <Arduino.h>
#endif 
 
#ifndef ARDUINOJSON_H
#include <ArduinoJson.h>
#endif

#include <DHT.h>
 

// DEFINE VARIABLES
#define ARDUINOJSON_USE_DOUBLE      1 

#define DHTTYPE DHT22
#define BMP280_ADDRESS 0x76
Adafruit_BMP280 bmp;
#define DHTPIN 32
#define SOILPIN 35

#define TFT_DC    17
#define TFT_CS    5
#define TFT_RST   16
#define TFT_CLK   18
#define TFT_MOSI  23
#define TFT_MISO  19
#define BTN_1 12
#define BTN_2 13
#define BTN_3 14

// DEFINE THE CONTROL PINS FOR THE DHT22 

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

// IMPORT FONTS FOR TFT DISPLAY
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h> 
#include <Fonts/FreeSerifBoldItalic9pt7b.h> 


// MQTT CLIENT CONFIG  
static const char* pubtopic      = "620157584";                    // Add your ID number here
static const char* subtopic[]    = {"620157584_sub","/elet2415"};  // Array of Topics(Strings) to subscribe to
static const char* mqtt_server   = "broker.emqx.io";         // Broker IP address or Domain name as a String 
static uint16_t mqtt_port        = 1883;

// WIFI CREDENTIALS
const char* ssid       = "Digicel_WiFi_eSEb";     // Add your Wi-Fi ssid
const char* password   = "WYPx3kCk"; // Add your Wi-Fi password 
//const char*  ssid        "MonaConnect"      // "REPLACE WITH YOUR WIFI's SSID"   
//const char* password    ""  // "REPLACE WITH YOUR WiFi's PASSWORD" 




// TASK HANDLES 
TaskHandle_t xMQTT_Connect          = NULL; 
TaskHandle_t xNTPHandle             = NULL;  
TaskHandle_t xLOOPHandle            = NULL;  
TaskHandle_t xUpdateHandle          = NULL;
TaskHandle_t xButtonCheckeHandle    = NULL;  

// FUNCTION DECLARATION   
void checkHEAP(const char* Name);   // RETURN REMAINING HEAP SIZE FOR A TASK
void initMQTT(void);                // CONFIG AND INITIALIZE MQTT PROTOCOL
unsigned long getTimeStamp(void);   // GET 10 DIGIT TIMESTAMP FOR CURRENT TIME
void callback(char* topic, byte* payload, unsigned int length);
void initialize(void);
bool publish(const char *topic, const char *payload); // PUBLISH MQTT MESSAGE(PAYLOAD) TO A TOPIC
void vButtonCheck( void * pvParameters );
void vUpdate( void * pvParameters );  
bool isNumber(double number);
void tempandhumidity(void);
void soilmoisture(void);
void altitudeandpressure(void);

/* Declare your functions below */ 
double convert_Celsius_to_fahrenheit(double c);
double convert_fahrenheit_to_Celsius(double f);
double calcHeatIndex(double Temp, double Humid);


/* Init class Instances for the DHT22 etcc */
 DHT dht(DHTPIN, DHTTYPE);
  
/* global variables */
double h;
double t;
double sm;
double a;
double p;

//############### IMPORT HEADER FILES ##################
#ifndef NTP_H
#include "NTP.h"
#endif

#ifndef MQTT_H
#include "mqtt.h"
#endif

// Temporary Variables 


void setup() {
  Serial.begin(115200);  // INIT SERIAL  
  Serial.println(F("test"));
  while ( !Serial ) delay(100);   // wait for native usb
  Serial.println(F("BMP280 test"));
  unsigned status;
  status = bmp.begin(BMP280_ADDRESS);
  if (!status) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) delay(10);
  }
  // Configure BMP280 settings
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                  Adafruit_BMP280::SAMPLING_X2,  // Temperature oversampling
                  Adafruit_BMP280::SAMPLING_X16, // Pressure oversampling
                  Adafruit_BMP280::FILTER_X16,   // Filtering
                  Adafruit_BMP280::STANDBY_MS_500);

  pinMode(BTN_1,INPUT_PULLUP);
  pinMode(BTN_2,INPUT_PULLUP);
  pinMode(BTN_3,INPUT_PULLUP);

  tft.begin();
  tft.setFont(&FreeSerifBoldItalic9pt7b);
  tft.print("\u00B0");


  // Display the welcome message
  tft.fillScreen(ILI9341_WHITE);
  tft.setTextColor(ILI9341_BLACK);
  tft.drawRoundRect(2, 2, tft.width() - 4, tft.height() - 4, 8, ILI9341_BLACK);
  tft.drawRoundRect(6, 6, tft.width() - 12, tft.height() - 12, 6, ILI9341_BLACK);
  tft.setTextSize(2.5);
  tft.setCursor(50, 40);
    tft.print("Booting");
  tft.setCursor(50, 90);
    tft.print("Weather");
    tft.setCursor(50, 140);
    tft.print("Station...");
    for (int i = 0; i <= 100; i += 10) {
        drawProgressBar(20, 210, tft.width() - 40, 15, i);
        delay(500); 
    }
    tft.fillScreen(ILI9341_WHITE);
    tft.setCursor(10, 40);
    tft.print("Welcome");
    tft.setCursor(5, 80);
    tft.setTextSize(1.5);
    tft.print("Choose one of the following");
    tft.setCursor(5, 100);
    tft.print("options:");

    tft.setCursor(5, 130);
    tft.print("- Press button 1 for tempera-");
    tft.setCursor(5, 150);
    tft.print("ture and humidity");
    //tft.setCursor(5, 170);
    //tft.print("dity.");

    tft.setCursor(5, 200);
    tft.print("- Press button 2 for altitude");
    tft.setCursor(5, 220);
    tft.print("and air pressure");

    tft.setCursor(5, 270);
    tft.print("- Press button 3 for");
    tft.setCursor(5, 290);
    tft.print("soil moisture.");

  // INITIALIZE ALL SENSORS AND DEVICES
  dht.begin();
  
  /* Add all other necessary sensor Initializations and Configurations here */


  initialize();     // INIT WIFI, MQTT & NTP 
  vButtonCheckFunction(); // UNCOMMENT IF USING BUTTONS INT THIS LAB, THEN ADD LOGIC FOR INTERFACING WITH BUTTONS IN THE vButtonCheck FUNCTION
 }
  


void loop() {
    // put your main code here, to run repeatedly:       
    vTaskDelay(1000 / portTICK_PERIOD_MS);    
}




  
//####################################################################
//#                          UTIL FUNCTIONS                          #       
//####################################################################
void vButtonCheck( void * pvParameters )  {
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );     
      
    for( ;; ) {
        // Add code here to check if a button(S) is pressed
        if (digitalRead(BTN_1) == LOW) {  // Button is pressed (since it's using the pull-up resistor)
        displayDataTemp(t,h,convert_fahrenheit_to_Celsius(calcHeatIndex(convert_Celsius_to_fahrenheit(t),h)));
        }
        delay(100);

        // 2. Implement button2  functionality
        if (digitalRead(BTN_2) == LOW) {  // Button is pressed (since it's using the pull-up resistor)
        displayDataSoil(sm);
        }
        delay(100);

        // 3. Implement button3  functionality
        if (digitalRead(BTN_3) == LOW) {  // Button is pressed (since it's using the pull-up resistor)
        displayDataAlt(a,p);
        }
        delay(100);
        // then execute appropriate function if a button is pressed  

        vTaskDelay(200 / portTICK_PERIOD_MS);  
    }
}

void vUpdate( void * pvParameters )  {
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );    
           
    for( ;; ) {
          // #######################################################
          // ## This function must PUBLISH to topic every second. ##
          // #######################################################
   
          // 1. Read Humidity and save in variable below
          h = dht.readHumidity();
           
          // 2. Read temperature as Celsius   and save in variable below
          t = dht.readTemperature();    

          sm = mapVWC(analogRead(SOILPIN),1000,4000);

          p = bmp.readPressure() / 100.0F;  
          
          a = bmp.readAltitude(1013.25);

          Serial.print(F("Humidity: "));
          Serial.print(h);
          Serial.print(F("%\r\n Temperature: "));
          Serial.print(t);
          Serial.print(F("°C\r\n"));
          Serial.print(F(" Heat Index: "));
          Serial.print(convert_fahrenheit_to_Celsius(calcHeatIndex(convert_Celsius_to_fahrenheit(t),h)));
          Serial.print(F("°C\r\n "));
          Serial.print(F("Soil Moisture: "));
          Serial.print(sm);
          Serial.print(F("%\r\n "));
          Serial.print(F("Altitude: "));
          Serial.print(a);
          Serial.print(F("m\r\n "));
          Serial.print(F("Air pressure: "));
          Serial.print(p);
          Serial.print(F("mb\r\n "));



 

          if(isNumber(t)){

          JsonDocument doc; // Create JSon object
          char message[1100]  = {0};

          // Add key:value pairs to JSon object
          doc["id"] = "620157584";
          doc["timestamp"]  = getTimeStamp();
          doc["humidity"]  = h;
          doc["temperature"]  = t;
          doc["heat_index"]  = convert_fahrenheit_to_Celsius(calcHeatIndex(convert_Celsius_to_fahrenheit(t),h));
          doc["soil_moisture"]  = sm;
          doc["altitude"]  = a;
          doc["pressure"]  = p;

          serializeJson(doc, message);  // Seralize / Covert JSon object to JSon string and store in char* array

          if(mqtt.connected() ){
            publish(pubtopic, message);
          }
            
              // ##Publish update according to ‘{"id": "student_id", "timestamp": 1702212234, "temperature": 30, "humidity":90, "heatindex": 30}’

              // 1. Create JSon object
              
              // 2. Create message buffer/array to store serialized JSON object
              
              // 3. Add key:value pairs to JSon object based on above schema

              // 4. Seralize / Covert JSon object to JSon string and store in message array
               
              // 5. Publish message to a topic sobscribed to by both backend and frontend                

          }

          
            
        vTaskDelay(1000 / portTICK_PERIOD_MS);  
    }
}

 

unsigned long getTimeStamp(void) {
          // RETURNS 10 DIGIT TIMESTAMP REPRESENTING CURRENT TIME
          time_t now;         
          time(&now); // Retrieve time[Timestamp] from system and save to &now variable
          return now;
}


void callback(char* topic, byte* payload, unsigned int length) {
  // ############## MQTT CALLBACK  ######################################
  // RUNS WHENEVER A MESSAGE IS RECEIVED ON A TOPIC SUBSCRIBED TO
  
  Serial.printf("\nMessage received : ( topic: %s ) \n",topic ); 
  char *received = new char[length + 1] {0}; 
  
  for (int i = 0; i < length; i++) { 
    received[i] = (char)payload[i];    
  }

  // PRINT RECEIVED MESSAGE
  Serial.printf("Payload : %s \n",received);

 
  // CONVERT MESSAGE TO JSON
  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, received);  

  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

}


bool publish(const char *topic, const char *payload){   
     bool res = false;
     try{
        res = mqtt.publish(topic,payload);
        // Serial.printf("\nres : %d\n",res);
        if(!res){
          res = false;
          throw false;
        }
     }
     catch(...){
      Serial.printf("\nError (%d) >> Unable to publish message\n", res);
     }
  return res;
}



//***** Complete the util functions below ******

double convert_Celsius_to_fahrenheit(double c){    
  return (c*(9/5))+32;
    // CONVERTS INPUT FROM °C TO °F. RETURN RESULTS     
}

double convert_fahrenheit_to_Celsius(double f){    
  return (f-32)*0.56;
    // CONVERTS INPUT FROM °F TO °C. RETURN RESULT    
}

double calcHeatIndex(double Temp, double Humid){;
  return -42.379 + 
               (2.04901523 * Temp) + (10.14333127 * Humid) + 
               (-0.22475541 * Temp * Humid) + 
               (-0.00683783 * Temp * Temp) + (-0.05481717 * Humid * Humid) + 
               (0.00122874 * Temp * Temp * Humid) + (0.00085282 * Temp * Humid * Humid) + 
               (-0.00000199 * Temp * Temp * Humid * Humid);
    // CALCULATE AND RETURN HEAT INDEX USING EQUATION FOUND AT https://byjus.com/heat-index-formula/#:~:text=The%20heat%20index%20formula%20is,an%20implied%20humidity%20of%2020%25
  
}
 
bool isNumber(double number){       
        char item[20];
        snprintf(item, sizeof(item), "%f\n", number);
        if( isdigit(item[0]) )
          return true;
        return false; 
} 


void displayDataTemp(float temp, float hum, float heatIndex) {

    tft.drawRGBBitmap(0,0, sunny, 240, 320); // DRAW IMAGE ON SCREEN
    tft.setTextColor(ILI9341_WHITE);
    tft.setFont(&FreeSansBold9pt7b);
    tft.setTextSize(3);
    delay(100);

    // Display temperature
    tft.setCursor(50, 130);
    tft.print(temp, 1);
    tft.write(0x00B0);
    tft.print("C");

    // Display humidity
    tft.setCursor(90, 165);
    tft.setTextSize(1);
    tft.print("H: ");
    tft.print(hum, 1);
    tft.print("%");

    // Display heat index
    tft.setCursor(50, 200);
    tft.print("Feels like: ");
    tft.print(heatIndex, 1);
    tft.print((char)247);
    tft.print("C");

}

void displayDataSoil(float soilm) {
    tft.drawRGBBitmap(0,0, soil, 240, 320); // DRAW IMAGE ON SCREEN
    tft.setTextColor(ILI9341_WHITE);
    tft.setFont(&FreeSansBold9pt7b);
    tft.setTextSize(3);

    // Display temperature
    tft.setCursor(50, 260);
    tft.print(soilm, 1);
    tft.print("%");

    tft.setTextSize(1);
    tft.setCursor(50, 280);
    if (soilm < 20){
      tft.print("Your soil is too dry!");
    }
    else if(soilm > 20 && soilm < 60){
      tft.print("Your soil is just right!");
    }
    else{
      tft.print("Your soil is too wet!");
    }
   

}

void displayDataAlt(float alt, float press) {
    tft.drawRGBBitmap(0,0, sunny, 240, 320); // DRAW IMAGE ON SCREEN
    tft.setTextColor(ILI9341_WHITE);
    tft.setFont(&FreeSansBold9pt7b);
    tft.setTextSize(1.95);
    delay(100);

    // Display temperature
    tft.setCursor(10, 130);
    tft.print("Altitude: ");
    tft.print(alt, 1);
    tft.print(" m");

    tft.setCursor(10, 165);
    tft.print("Air Pressure: ");
    tft.setCursor(10, 185);
    tft.print(press, 1);
    tft.print(" mb");

}

float mapVWC(int sensorValue, int adcDry, int adcWet) {
  return ((float)(sensorValue - adcWet) / (adcDry - adcWet)) * 100.0;
}

void drawProgressBar(int x, int y, int w, int h, int progress) {
    int filled = (progress * w) / 100; 
    tft.drawRect(x, y, w, h, ILI9341_MAGENTA);
    tft.fillRect(x + 1, y + 1, filled - 2, h - 2, ILI9341_MAGENTA);
}