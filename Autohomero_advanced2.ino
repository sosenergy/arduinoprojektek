// #include "RTClib.h"
#include <LiquidCrystal.h>
#include "DHT.h"
#define SensorPin 7 // connect the out pin of dht sensor to D4 pin of arduino nano
// DateTime now;
//char daysOfTheWeek[7][12] = {"Vasarnap", "Hetfo   ", "Kedd    ", "Szerda  ", "Csutort.", "Pentek  ", "Szombat "};
//RTC_DS3231 rtc;
#define Dht DHT11

DHT dht(SensorPin, Dht);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//void showDate(void);
//void showTime(void);
//void showDay(void); 



void setup() {

 // lcd.createChar(0, smiley);
  
lcd.begin(16, 2);
  
dht.begin(); 

pinMode(A0, INPUT);

Serial.begin(9600);

/* if (! rtc.begin()) 
  {
    Serial.println("Couldn't find RTC Module");
     lcd.setCursor(0,0);
     lcd.print("RTCmodulhiany");
     while (1);
  }

  if (rtc.lostPower()) 
  {
    lcd.setCursor(0, 0);
    lcd.print("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  */
} 

void loop() {
  
int hum = dht.readHumidity();
int temp = dht.readTemperature();
float fesz;
int dig=0;
int be=A0;
dig = analogRead(be);
fesz = dig * 0.0048 * 4.287 * 0.7216;

lcd.setCursor(0, 0);

lcd.print(temp); lcd.print(" fok, ");lcd.print(hum);lcd.print(" %");
//lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
//lcd.write(byte(0));

lcd.setCursor(0,1);

lcd.print("Akku: ");lcd.print(fesz);lcd.print(" Volt");



/*  now = rtc.now();
  if(now.hour()<10) lcd.print("0");
  lcd.print(now.hour());
  lcd.print(':');
  if (now.minute()<10) lcd.print("0");
  lcd.print(now.minute());
  lcd.print(':');
  if(now.second()<10) lcd.print("0");
  lcd.print(now.second()); */
  delay(1000);
  lcd.clear();

}
 
