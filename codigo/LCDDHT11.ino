// Mezcla de los ejemplos DHT11Default de la librería SimpleDHT y del HelloWorld de LCD I2C 

// Curso Arduino: Experto desde 0
// CC by sa @javacasm


// Includes del DHT
#include <SimpleDHT.h>

// Includes del LCD
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Variables globales del DHT
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);


// Variables globales del LCD
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup() {
// Setup del DHT
  Serial.begin(115200);
// Setup del LCD  
  lcd.init(); 
  lcd.backlight();
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  lcd.setCursor(0,0);  // Para mostrar en el LCD
  lcd.print((int)temperature);
  Serial.print((int)humidity); Serial.println(" H");
  lcd.setCursor(0,1);  // Para mostrar en el LCD
  lcd.print((int)humidity);  
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}