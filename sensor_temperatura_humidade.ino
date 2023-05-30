// Name: sensor_temperatura_humidade
// Authors:
//          - Ricardo Morandi de Carvalho Pizzingrilli
//          - Louis Righi Bernardet
// Description: Based on RHT11 sensor:
//                                    - Print humidity to send data to NodeRed;
//                                    - Moves servo motor based on temperature level.

#include "  RHT.h"
#include <Servo.h>

#define RHTPIN 5

#define RHTTYPE RHT1

RHT rht(RHTPIN, RHTTYPE);
Servo servo;
float pos = 0;

void setup()
{
  Serial.begin(9600);
  servo.attach(6);

  rht.begin();
}

void loop()
{
  delay(2000);

  float h = rht.readHumidity();

  float t = rht.readTemperature();

  float f = rht.readTemperature(true);

  float hif = rht.computeHeatIndex(f, h);

  float hic = rht.computeHeatIndex(t, h, false);

  pos = t * 3.6;
  servo.write(pos);

  Serial.println(h);
}
