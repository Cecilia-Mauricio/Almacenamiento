// defines pins numbers
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Servo.h>

Servo myservo;// crea el objeto servo
Servo myservos;
int pos = 0, con = 0, c=0, d=0, gra,grad;    // posicion del servo
const int IZQ=D1;
const int DER=D2;
int val, vel, a=0,b=0,seri=0, sera=0, cont=0;
String interruptora="", interruptorb="", est="";

void setup(){
  pinMode(IZQ,INPUT);
  pinMode(DER,INPUT);
  myservo.attach(D3);  // vincula el servo al pin digital 9
  myservos.attach(D4);  // vincula el servo al pin digital 9
  Serial.begin(9600);
}

void loop(){
val=digitalRead(IZQ);
vel=digitalRead(DER);
seri = myservo.read();
sera = myservos.read();
cont = cont + 1;

if (cont == 1){
c = 0;
myservo.write(c);
interruptora = "Servo1:";
gra = seri;
myservos.write(180 - c);
interruptorb = "Servo2:";
grad = sera;
delay(500); 
}
else if (cont > 1 and cont <=180){
c = c + 1;
myservo.write(c);
interruptora = "Servo1:";
gra = seri;
myservos.write(180 - c);
interruptorb = "Servo2:";
grad = sera;
delay(500); 
}else if (cont >= 181 and cont <= 360){
c = c - 1;
myservo.write(c);
interruptora = "Servo1:";
gra = seri;
myservos.write(180-c);
interruptorb = "Servo2:";
grad = sera;
delay(500); 
if(c==360){
  c = 0;
}
}
if (val==HIGH){
  a=a+1;
  b=0;
  con = 0;
  if(a==1){
    Serial.println(interruptora);
    Serial.println(gra);
    Serial.println(interruptorb);    
    Serial.println(grad);
}
}
else if (vel==HIGH){
  b=b+1;
  a=0;
  con = 180;
  if(b==1){
    Serial.println(interruptora);
    Serial.println(gra);
    Serial.println(interruptorb);    
    Serial.println(grad);    
}
}
}
