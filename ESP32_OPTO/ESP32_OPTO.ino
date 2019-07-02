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

unsigned long lastMillis_1 = 0;
unsigned long lastMillis_2 = 0;
unsigned long lastMillis_3 = 0;
unsigned long lastMillis_4 = 0;
unsigned long lastMillis_5 = 0;
unsigned long lastMillis_6 = 0;
unsigned long lastMillis_7 = 0;
unsigned long lastMillis_8 = 0;

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
  // MQTT Loop
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
      if ( digitalRead(Ch_1) == false ){
        if (millis() - lastMillis_1 > 1000) {
          lastMillis_1 = millis();
          Serial.println("Channel 1 ON");
          client.publish("/Opto", "Opto1,CH1,ON");
        }
      }
      if ( digitalRead(Ch_2) == false ){
        if (millis() - lastMillis_2 > 1000) {
          lastMillis_2 = millis();
          Serial.println("Channel 2 ON");
          client.publish("/Opto", "Opto1,CH2,ON");
        }
      }
      if ( digitalRead(Ch_3) == false ){
        if (millis() - lastMillis_3 > 1000) {
          lastMillis_3 = millis();
          Serial.println("Channel 3 ON");
          client.publish("/Opto", "Opto1,CH3,ON");
        }
      }
      if ( digitalRead(Ch_4) == false ){
        if (millis() - lastMillis_4 > 60000) {
          lastMillis_4 = millis();
          Serial.println("Channel 4 ON");
          client.publish("/Opto", "Opto1,CH4,ON");
        }
      }
      if ( digitalRead(Ch_5) == false ){
        if (millis() - lastMillis_5 > 60000) {
          lastMillis_5 = millis();
          Serial.println("Channel 5 ON");
          client.publish("/Opto", "Opto1,CH5,ON");
        }
      }
      if ( digitalRead(Ch_6) == false ){
        if (millis() - lastMillis_6 > 60000) {
          lastMillis_6 = millis();
          Serial.println("Channel 6 ON");
          client.publish("/Opto", "Opto1,CH6,ON");
        }
      }
      if ( digitalRead(Ch_7) == false ){
        if (millis() - lastMillis_7 > 60000) {
          lastMillis_7 = millis();
          Serial.println("Channel 7 ON");
          client.publish("/Opto", "Opto1,CH7,ON");
        }
      }
      if ( digitalRead(Ch_8) == false ){
        if (millis() - lastMillis_8 > 60000) {
          lastMillis_8 = millis();
          Serial.println("Channel 8 ON");
          client.publish("/Opto", "Opto1,CH8,ON");
        }
      }
      //Serial.println("Waiting State");
}
