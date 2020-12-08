// defines pins numbers
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Servo.h>

Servo myservo;// crea el objeto servo
Servo myservos;
int pos = 0, con = 0;    // posicion del servo
const int IZQ=D1;
const int DER=D2;
int val, vel, a=0,b=0;
String interruptor="", est="";

void setup(){
  pinMode(IZQ,INPUT);
  pinMode(DER,INPUT);
  myservo.attach(D3);  // vincula el servo al pin digital 9
  myservos.attach(D4);  // vincula el servo al pin digital 9
  Serial.begin(115200);
}

void loop(){
val=digitalRead(IZQ);
vel=digitalRead(DER);
if (val==HIGH){
  a=a+1;
  b=0;
  con = 0;
  if(a==1){
    for (pos = 180; pos >= 0; pos -= 1) 
   {
    con = con + 1;
      myservos.write(pos);
      myservo.write(con);             
      delay(15);                                       
   }
    Serial.println("Servo1:Izquierda");
    Serial.println("Servo2:Derecha");    
}
}
else if (vel==HIGH){
  b=b+1;
  a=0;
  con = 180;
  if(b==1){
   for (pos = 0; pos <= 180; pos += 1) 
   {
    con = con - 1;
      myservos.write(pos);
      myservo.write(con);    
      delay(15);                                    
   }
Serial.println("Servo1:Derecha");
Serial.println("Servo2:Izquierda");    
}
}

}
