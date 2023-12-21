#include <ESP8266WiFi.h>
#include <FastLED.h>
#include <TZ.h>
#include <time.h>
#include <sys/time.h>

#include "led_flat10x10.h"
#include "config.h"

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  //initialize LED_BUILTIN
  pinMode(LED_BUILTIN, OUTPUT); // Lights up during Web setting function
  digitalWrite(LED_BUILTIN, LOW);  

  // initialize NeoPixel 
  initializeLEDs();

  // Connect wifi 
  setMask(word_WIFI); applyMask(); // WIFI
  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  configTime(_TIMEZONE, _NTP_SERVER);

  Serial.println("WORDCLOCK");
  // startup sequence...
  rainbowCycle(); // Welcome illumination

}

void loop() {
  time(&current);                       // read the current time
  Serial.print("year:");
  Serial.print(localtime(&current)->tm_year + 1900);  // years since 1900
  Serial.print("\tmonth:");
  Serial.print(localtime(&current)->tm_mon + 1);      // January = 0 (!)
  Serial.print("\tday:");
  Serial.print(localtime(&current)->tm_mday);         // day of month
  Serial.print("\thour:");
  Serial.print(localtime(&current)->tm_hour);         // hours since midnight  0-23
  Serial.print("\tmin:");
  Serial.print(localtime(&current)->tm_min);          // minutes after the hour  0-59
  Serial.print("\tsec:");
  Serial.print(localtime(&current)->tm_sec);          // seconds after the minute  0-61*
  Serial.print("\twday");
  Serial.print(localtime(&current)->tm_wday);         // days since Sunday 0-6
  if (localtime(&current)->tm_isdst == 1)             // Daylight Saving Time flag
    Serial.print("\tDST");
  else
    Serial.print("\tstandard");
  Serial.println();
  
  displayTime(localtime(&current)->tm_hour, localtime(&current)->tm_min, localtime(&current)->tm_sec);
}