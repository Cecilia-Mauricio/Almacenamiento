/*
    This sketch establishes a TCP connection to a "quote of the day" service.
    It sends a "hello" message, and then prints received data.
*/

#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const int IZQ=D1;
const int DER=D2;
int val, vel, a=0,b=0;
String interruptor="", est="";

String server = "";

const char *ssid = "Mon";
const char *password = "12345678i";

void setup()
{
  //////////////////////////
  pinMode(IZQ,INPUT);
  pinMode(DER,INPUT);
  ////////////////////////////
  Serial.begin(9600);

  Serial.println("WiFi connected");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{

  if (WiFi.status() == WL_CONNECTED)
  { //Check WiFi connection status

    HTTPClient http;                                                                                  
    http.begin("http://192.168.43.90:3300/interruptores/5fa0af118508b2199b1ccf36");


val=digitalRead(IZQ);
vel=digitalRead(DER);
if (val==HIGH){
  a=a+1;
  b=0;
  if(a==1){
Serial.println("izquierdo");
interruptor = "int2";
est = "izquierdo"; 
post("5fa0af118508b2199b1ccf36", interruptor, est);
}
}
else if (vel==HIGH){
  b=b+1;
  a=0;
  if(b==1){
interruptor = "int2";
Serial.println("derecho");
est = "derecho";
post("5fa0af118508b2199b1ccf36", interruptor, est);
}
}
  }
}

void post(String id, String interruptor, String est) {
  Serial.println("Inicio post");
  HTTPClient http;
  String json;
  server = "http://192.168.43.90:3300/interruptores/5fa0af118508b2199b1ccf36";

  StaticJsonDocument<256> doc;
  doc["interruptor"] = String(interruptor);
  doc["est"] = String(est);
  serializeJson(doc, json);
  
  http.begin(server);
  http.addHeader("Content-Type", "application/json");
  http.POST(json);
  http.writeToStream(&Serial);
  http.end();
  Serial.println("Termino post");
}
