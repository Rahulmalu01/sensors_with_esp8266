#include <dht11.h>
#define DHT11PIN 4

dht11 DHT11;

void  setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);

  if((float)DHT11.temperature > 30){
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }

  delay(2000);

}