#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
  
#define WIFI_SSID "R2DLan"
#define WIFI_PASSWD "Dodo9346"
#define UDP_PORT 4210
const char ip[]="192.168.178.49";
 

WiFiUDP UDP;
  
void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWD);
  
  // Connecting to WiFi...
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  
  Serial.print("\nConnected! IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(D0,INPUT_PULLDOWN_16);
}
 
void loop() {

 if(digitalRead(D0))
 {
    UDP.beginPacket(ip,4210);
    UDP.write("Es hat geklingelt");
    Serial.print("Sent to ");
    Serial.println(ip);
    UDP.endPacket();
 }

 delay(50);
 }
 
