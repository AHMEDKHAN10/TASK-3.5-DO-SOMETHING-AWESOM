
int motion = 2;
int fan =3;
#include <DHT.h>

#define DHTPIN 6
#define DHTTYPE DHT22
DHT dht (DHTPIN, DHTTYPE);

float hum;
float temp;

void setup() 
{
  Serial.begin(9600);
  pinMode(motion, INPUT);
  pinMode(fan, OUTPUT);
  dht.begin();
}

void loop() 
{
   hum = dht.readHumidity();
   temp= dht.readTemperature();

    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    
  
  long sensor = digitalRead(motion);
  
  if (sensor == HIGH && temp > 26) 
    {
    digitalWrite (fan, HIGH);
    }
  
    else
    {
    digitalWrite(fan,LOW);
    }
  
  

  
  
  if (digitalRead(2)== HIGH)
  {
    Serial.println("Active");

  }
  else 
  {
    Serial.println("Inactive");

  }
  delay(500);


