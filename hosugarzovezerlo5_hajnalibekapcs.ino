
#define EGY 3600000
#define KET 7200000
#define HA 10800000
#define NEGY 14400000
#define OT 18000000
#define HAT 21600000
#define HET 25200000
#define NYOLC 28800000
#define FEL 1800000
#define TEST 3000

void setup() {
  
  pinMode(2, OUTPUT);
}

void loop() {

  digitalWrite(2, LOW);  // BE 
  delay(TEST);   // 3s
  digitalWrite(2, HIGH);   // KI
  delay(TEST); // 3s
  digitalWrite(2, LOW);   // BE
  delay(TEST);        // 3s           
  digitalWrite(2, HIGH);    // KI
  delay(HAT); // várakozás, 6 órahossza  
  digitalWrite(2, LOW); // hajnali bekapcs!
  delay(HA);     // üzem 3 órán át ( ms ) (3 óra = 10800000 )
  digitalWrite(2, HIGH); // biztonsági reggeli lekapcs.
  delay(KET);     //  2 órás szünet!   
  // released: 2020.01.14.K az SPC tréning előtti napon hogy hajnalonként meleg legyen a szobában.  
  // módosítva 2020-03-19. Koronajárvány kellős közepén...jelenleg 73 magyar fertőzött, 1 halott eddig...és még megy a Jabil. Levi szerint jövő csüt és bezár. Viki szerint holnap 20-án már 100 felett lesz a betegek száma, szerintem 98.
  // ja igen, a módosítás annyi volt hogy 6-ról 5 órára vettem le a várakozási időt éjszaka és 2-ről 3-ra növeltem a bekapcsolt időtartamot. SL.  
  // Újabb módosítás: visszatettem 6-ra a kikapcs időtartamot és 2-re redukáltam a bekapcs időt. 2020.11.25.k - 3.hetem a Hagyónál. 
  //Jah, most találtam ki az óra képző függvényt hogy ne kelljen mindig számolgatni.

  // 2020.11.26. függvénnyel nem volt jó ezért most konstansokkal oldottam meg az órák számát számolgatás nélkül.

  
  }

 /* int ora (int hours) {
    return hours*60*60*1000;
} 
*/
