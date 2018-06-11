#include "DHT.h"

#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const byte HeatPin = 6;
const byte HumidifyPin = 7;

const float lowTemperature = 37.0;
const float lowHumidity = 50.0;

void setup() {
    Serial.begin(9600);
    dht.begin();    
    pinMode(HeatPin, OUTPUT);
    pinMode(HumidifyPin, OUTPUT);
    delay(1000);
}

void loop() {
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    if (temperature <= lowTemperature) {
        digitalWrite(HeatPin, HIGH);
    }
    else {
        digitalWrite(HeatPin, LOW);
    }
    if (humidity <= lowHumidity) {
       digitalWrite(HumidifyPin, HIGH);
    }
    else {
       digitalWrite(HumidifyPin, LOW);
    }
    delay(5000);
    Serial.print(temperature);
    Serial.print("*C, ");
    Serial.print(humidity);
    Serial.print("%");
    Serial.println("");
}
