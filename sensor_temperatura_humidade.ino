// Name: sensor_temperatura_humidade
// Authors:
//          - Gustavo de Almeida Silva
//          - Nicolas Renan de Andrade Sanches
// Description: Based on DHT11 sensor:
//                                    - Print humidity to send data to NodeRed;
//                                    - Moves servo motor based on temperature level.

#include "DHT.h"
#include <Servo.h>

#define DHTPIN 5

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
Servo servo;
float pos = 0;

void setup()
{
  Serial.begin(9600);
  servo.attach(6);

  dht.begin();
}

void loop()
{
  delay(2000);

  float h = dht.readHumidity();

  float t = dht.readTemperature();

  float f = dht.readTemperature(true);

  float hif = dht.computeHeatIndex(f, h);

  float hic = dht.computeHeatIndex(t, h, false);

  pos = t * 3.6;
  servo.write(pos);

  Serial.println(h);
}
