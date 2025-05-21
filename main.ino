#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 4
#define DHTTYPE DHT11
#define soilPin 34
#define pumpPin 26
#define lightPin 35

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin();
  lcd.backlight();
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soil = analogRead(soilPin);
  int light = analogRead(lightPin);

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C H:");
  lcd.print(hum);

  lcd.setCursor(0, 1);
  lcd.print("Soil:");
  lcd.print(soil);

  if (soil < 500) {
    digitalWrite(pumpPin, HIGH);
  } else {
    digitalWrite(pumpPin, LOW);
  }

  delay(2000);
}
