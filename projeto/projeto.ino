//  Guilherme Maioli
//  Gabriel Oliveira Santos
//  Kit 1
// DHT na D4
// MOTOR na D1
#define BLYNK_PRINT Serial
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>

char auth[] = "token do seu projeto";
char ssid[] = "nome da sua rede wifi";
char pass[] = "senha da sua rede";

#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;


void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  Blynk.virtualWrite(V4, f);
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
