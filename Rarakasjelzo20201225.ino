
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include "dht.h"

dht DHT;

#define DHT11_PIN 7

int meres, merespuffer;


void setup() {
Serial.begin(9600);
pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(9, HIGH);
  //delay(1000);
  
  int chk = DHT.read11(DHT11_PIN);
  
  Serial.print(DHT.temperature);
  Serial.println(" "); 
  meres = DHT.temperature;

  lcd.begin(20, 4);
  
  if(meres>=merespuffer)
  {
  lcd.setCursor(0,0);
  lcd.print(meres);
  lcd.print(" Celsius fok");
  lcd.setCursor(0,1);
  lcd.print("A homerseklet no!");
  lcd.setCursor(0,2);
  lcd.print("Minden rendben van!");
  }

  if(meres<merespuffer)
  {
  lcd.setCursor(0,0);
  lcd.print(meres);
  lcd.print(" Celsius fok");
  lcd.setCursor(0,1);
  lcd.print("Homerseklet csokken");
  lcd.setCursor(0,2);
  lcd.print("Kerlek rakj a tuzre!");
  digitalWrite(9, LOW);
  delay(1500);
  digitalWrite(9, HIGH);
  delay(1500);
  digitalWrite(9, LOW);
  delay(1500);
  digitalWrite(9, HIGH);
  delay(1500);
  digitalWrite(9, LOW);
  delay(1500);
  digitalWrite(9, HIGH);
  delay(1500);
  digitalWrite(9, LOW);
  delay(1500);
  digitalWrite(9, HIGH);
  delay(1500);
  }

  if(meres > 50) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(meres);
  lcd.print(" Celsius fok");
  lcd.setCursor(0,1);
  lcd.print("Vigyazat!");
  lcd.setCursor(0,2);
  lcd.print("A radiator tul forro");
  }
  
  
  delay(30000);

lcd.begin(20, 4);
  
   if(meres>=merespuffer)
  {
  lcd.setCursor(0,0);
  lcd.print(meres);
  lcd.print(" Celsius fok");
  lcd.setCursor(0,1);
  lcd.print("A homerseklet no!");
  lcd.setCursor(0,2);
  lcd.print("Minden rendben van!");
  }

  if(meres<merespuffer)
  {
  lcd.setCursor(0,0);
  lcd.print(meres);
  lcd.print(" Celsius fok");
  lcd.setCursor(0,1);
  lcd.print("Homerseklet csokken");
  lcd.setCursor(0,2);
  lcd.print("Kerlek rakj a tuzre!");
  digitalWrite(9, LOW);
  delay(1500);
  digitalWrite(9, HIGH);
  delay(1500);
  digitalWrite(9, LOW);
  delay(1500);
  digitalWrite(9, HIGH);
  delay(1500);
  digitalWrite(9, LOW);
  delay(1500);
  digitalWrite(9, HIGH);
  delay(1500);
  digitalWrite(9, LOW);
  delay(1500);
  digitalWrite(9, HIGH);
  delay(1500);
  }

  if(meres > 50) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(meres);
  lcd.print(" Celsius fok");
  lcd.setCursor(0,1);
  lcd.print("Vigyazat!");
  lcd.setCursor(0,2);
  lcd.print("A radiator tul forro");
  }
  
  delay(30000);

  merespuffer = meres;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Refreshing...");
  delay(2000);
  lcd.clear();
}
