/*
    CyberDisplay 0.1b

    Works well with ATOM Matrix ESP32 Development Kit
    Fonts are optimized for 5*5 RGB matrix.
    Check fonts licensing info for in CyberDisplayFont.h file

    Current version features:
    [v] WiFi connection
    [v] NightScout connection (no password)
    [v] Glucose level display, mmol/l (integer part only!)
    [v] Glucose level trend arrows display (can be disabled)
    [v] Glucose level color indication
    [v] Customizable indication delays
    [v] Error indication
    [v] Console output for debuging
    
    Planned:
    [x] Multiple WiFi spots connection
    [x] NightScout connection (protected by password) 
    [x] Last glucose level entry time excess alarm 
    [x] Vibration output
    [x] Audio output
   
    Created 09/2020 by Iskander Vafin
    Last version https://github.com/d3xr/CyberDisplay

    Waiting for feedback:
    https://t.me/Iskander_Vafin    
        

*/

/* WiFi login */                            const char*   ssid = "MY_WIFI_LOGIN";
/* WiFi password */                         const char*   password =  "MY_WIFI_PASS";
/* NightScout url */                        String        adress_NS = "https://MY_NS_ADRESS.COM";

/* If you need trend - set 1, else 0  */    const bool    needed_arrow = 1;
/* How many seconds will trend display */   const int     delay_arrow = 8;
/* How many seconds will glucose display*/  const int     timerDelay = 20000;

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>
#include "CyberDisplayFont.h"

#define PIN 27
#define mw 5
#define mh 5
#define NUMMATRIX (mw*mh)

const uint16_t colors[] = {
  matrix->Color(0, 112, 255),      //    [0] blue
  matrix->Color(11, 255, 36),      //    [1] green
  matrix->Color(179, 255, 36),     //    [2] green - yellow
  matrix->Color(255, 233, 0),      //    [3] yellow
  matrix->Color(255, 200, 0),      //    [4] orange
  matrix->Color(255, 70, 0),       //    [5] orange - red
  matrix->Color(255, 10, 10),      //    [6] red
  matrix->Color(255, 0, 50),       //    [7] ultra red
  matrix->Color(255, 255, 255),    //    [8] white
  matrix->Color(255, 0, 255)       //    [9] purple
};

unsigned long lastTime = 0;
String serverPath = adress_NS += "/api/v1/entries/current.json";

CRGB matrixleds[NUMMATRIX];

FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(matrixleds, mw, mh,
    NEO_MATRIX_TOP     + NEO_MATRIX_RIGHT +
    NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE );

void setup() {

  FastLED.addLeds<NEOPIXEL, PIN>(matrixleds, NUMMATRIX);
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->setFont(&CyberDisplayFont);
  matrix->setBrightness(40);
  matrix->setTextColor(colors[0]);
  matrix_print("-");

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("It will take ");
  Serial.print(timerDelay / 1000);
  Serial.println(" seconds before publishing the first reading");
}

void loop() {

  if ((millis() - lastTime) > timerDelay) {
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverPath.c_str());
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        StaticJsonDocument<500> doc;
        String json = http.getString();
        json.replace("[", "");
        json.replace("]", "");
        DeserializationError error = deserializeJson(doc, json);

        if (error) {
          Serial.print(F("deserializeJson() failed: "));
          Serial.println(error.c_str());
          matrix_print("N");
          return;
        }

        int sgv_mgdl = doc["sgv"];
        int sgv_mmol_single = int(sgv_mgdl * 0.0555);
        String arrow_direction = doc["direction"];

        Serial.println(sgv_mmol_single);
        Serial.println(arrow_direction);

        int input_color  = matrix_color_select(sgv_mmol_single);

        if (needed_arrow) {
          matrix_print_arrow(arrow_direction, input_color);
          delay(delay_arrow * 1000);
        }

        matrix_print_num(sgv_mmol_single, input_color);


      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        matrix_print("E");
      }

      http.end();

    }
    else {
      Serial.println("WiFi Disconnected");
      matrix_print("W");
    }
    lastTime = millis();
  }

}

void matrix_print(String matrix_text) {  
  matrix->setTextColor(colors[9]);
  matrix->setCursor(1, mh);
  matrix->fillScreen(0);
  matrix->print(matrix_text);
  matrix->show();
  delay(100);
}

void matrix_print_arrow(String matrix_text, int input_color) {

if      (matrix_text == "DoubleDown")     {matrix_text = "{";}
else if (matrix_text == "SingleDown")     {matrix_text = "<";}
else if (matrix_text == "FortyFiveDown")  {matrix_text = "\\";}
else if (matrix_text == "Flat")           {matrix_text = "|";}
else if (matrix_text == "FortyFiveUp")    {matrix_text = "/";}
else if (matrix_text == "SingleUp")       {matrix_text = ">";}
else if (matrix_text == "DoubleUp")       {matrix_text = "}";}
else                                      {matrix_text = "?";}


  matrix->setTextColor(colors[input_color]);
  matrix->setCursor(0, mh);
  matrix->fillScreen(0);
  matrix->print(matrix_text);
  matrix->show();
  delay(100);

}

int matrix_color_select(int matrix_text) {

if      (matrix_text >= 15) { return (7); } 
else if (matrix_text >= 12) { return (6); } 
else if (matrix_text >= 10) { return (5); } 
else if (matrix_text >= 9)  { return (4); } 
else if (matrix_text >= 8)  { return (3); } 
else if (matrix_text >= 7)  { return (2); } 
else if (matrix_text >= 4)  { return (1); } 
else if (matrix_text > 0)   { return (0); } 
else                        { return (9); }

}

void matrix_print_num(int matrix_text, int input_color) {

  if      (matrix_text == 1)  {
    matrix->setCursor(2, mh);
  }
  else if (matrix_text == 11) {
    matrix->setCursor(1, mh);
  }
  else if (matrix_text < 10)  {
    matrix->setCursor(1, mh);
  }
  else                        {
    matrix->setCursor(0, mh);
  }

  matrix->setTextColor(colors[input_color]);
  matrix->fillScreen(0);
  matrix->print(matrix_text);
  matrix->show();
  delay(100);

}
