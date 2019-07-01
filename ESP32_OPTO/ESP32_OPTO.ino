//This Project IOT of MT740
//Theme : Alarm Monitor of system facility via IOT 
//MAINPIC : PATRADANAI
//
//CONCEPT :
//
//PROGRESS :
//
//PROBLEM :

//       Wiring Diagrams
//
//Vcc     ----------> 3.3 V
//GPIO 26 ----------> Channel 1
//GPIO 18 ----------> Channel 2
//GPIO 19 ----------> Channel 3
//GPIO 23 ----------> Channel 4
//GPIO 5  ----------> Channel 5
//GPIO 35 ----------> Channel 6
//GPIO 33 ----------> Channel 7
//GPIO 34 ----------> Channel 8

//////////////////////////////////////////////////////
////                                              ////
////            Call Library                      ////
////                                              ////
//////////////////////////////////////////////////////

#include <WiFi.h>
#include <MQTT.h>

//////////////////////////////////////////////////////
////                                              ////
////             Global Variable                  ////
////                                              ////
//////////////////////////////////////////////////////

const char *ssid = "Visitor";
const char *pass = "security";
const char *mqttname = "MTL-700-NOA55.MTL1.CO.TH";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

#define Ch_1 26   //GPIO 26 ----------> Channel 1
#define Ch_2 18   //GPIO 18 ----------> Channel 2
#define Ch_3 19   //GPIO 19 ----------> Channel 3
#define Ch_4 23   //GPIO 23 ----------> Channel 4
#define Ch_5 5    //GPIO 5  ----------> Channel 5
#define Ch_6 35   //GPIO 35 ----------> Channel 6
#define Ch_7 33   //GPIO 33 ----------> Channel 7
#define Ch_8 34   //GPIO 34 ----------> Channel 8

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "try", "try")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // Set pinMode
  pinMode(Ch_1, INPUT);
  pinMode(Ch_2, INPUT);
  pinMode(Ch_3, INPUT);
  pinMode(Ch_4, INPUT);
  pinMode(Ch_5, INPUT);
  pinMode(Ch_6, INPUT);
  pinMode(Ch_7, INPUT);
  pinMode(Ch_8, INPUT);

  // Declear WiFi Begin
  WiFi.begin(ssid, pass);
  
  // Declear MQTT Begin
  client.begin(mqttname, net);

  // Call Function WIFI
  connect();
}

void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
      lastMillis = millis();
      if ( digitalRead(Ch_1) == false ){
      Serial.println("Channel 1 ON");
      client.publish("/hello", "world");
      }
      else if ( digitalRead(Ch_2) == false ){
        Serial.println("Channel 2 ON");
        client.publish("/hello", "world");
      }
      else if ( digitalRead(Ch_3) == false ){
        Serial.println("Channel 3 ON");
        client.publish("/hello", "world");
      }
      else if ( digitalRead(Ch_4) == false ){
        Serial.println("Channel 4 ON");
        client.publish("/hello", "world");
      }
      else if ( digitalRead(Ch_5) == false ){
        Serial.println("Channel 5 ON");
        client.publish("/hello", "world");
      }
      else if ( digitalRead(Ch_6) == false ){
        Serial.println("Channel 6 ON");
        client.publish("/hello", "world");
      }
      else if ( digitalRead(Ch_7) == false ){
        Serial.println("Channel 7 ON");
        client.publish("/hello", "world");
      }
      else if ( digitalRead(Ch_8) == false ){
        Serial.println("Channel 8 ON");
        client.publish("/hello", "world");
      }
      else {
        Serial.println("Waiting State");
      }
  }
}
