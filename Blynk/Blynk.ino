// #define BLYNK_TEMPLATE_ID           "TMPL6cbrOWc5z"
// #define BLYNK_TEMPLATE_NAME         "Pampa Air"
// #define BLYNK_AUTH_TOKEN            "Uwg-Mw6pHDHlm8-9bPSWl9IQW9GJTyQc"

// #define BLYNK_TEMPLATE_ID "TMPL6Qwcemnl1"
// #define BLYNK_TEMPLATE_NAME "NailaIOT"
// #define BLYNK_AUTH_TOKEN "m1heKIzoeYTVSkU9t1DwDrosNpL_NZTC"
#define BLYNK_TEMPLATE_ID "TMPL6zrLbM2gA"
#define BLYNK_TEMPLATE_NAME "Deteksi Banjir"
#define BLYNK_AUTH_TOKEN "7hN3K6Aa7c2imZBAkumX0MOwu5KeVOiX"

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "rahma";
char pass[] = "hp123456";
// char ssid[] = "iPhone";
// char pass[] = "1234567890";

// pin Lcd Blynk
WidgetLCD lcd(V1);

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  lcd.clear();
  lcd.print(2, 0, "BENDUNGAN IOT");
}

void loop()
{
  Blynk.run();
  // lcd.print(0, 1, "Kirim Data");

  String data = "";
  while(Serial.available() > 0){
    data += char(Serial.read());
  }


  Serial.println(data);
  // Serial.println("Slider Value: " + String(sliderValue));

  // print data di Lcd blynk 
  if(data.length() > 0){
    lcd.clear();
    lcd.print(0, 0, data);
  }
  
  delay(1000);
}
