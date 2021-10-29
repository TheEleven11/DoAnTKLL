#include <DHT.h>
#include <LiquidCrystal_I2C.h>

//#include "timer.h"

const int DHTPIN = 4;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2); 

byte degree[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
};

void setup() {
  lcd.init();  
  lcd.backlight();
  lcd.print("Nhiet do: ");
  lcd.setCursor(0,1);
  lcd.print("Do am: ");
  lcd.createChar(1, degree);
  dht.begin();  
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) {
  } 
  else {
    lcd.setCursor(10,0);
    lcd.print(round(t));
    lcd.print(" ");
    lcd.write(1);
    lcd.print("C");

    lcd.setCursor(10,1);
    lcd.print(round(h));
    lcd.print(" %");    
  }
}


////YWROBOT
////Compatible with the Arduino IDE 1.0
//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
//
//void setup()
//{
//  lcd.init();                    
//  lcd.backlight();
//  lcd.setCursor(0, 0);
//  lcd.print("Hello World!");
//  lcd.setCursor(0,1);
//  lcd.print("Hello NDC!");
//}
//
//void loop()
//{
//}
