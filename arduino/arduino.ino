#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27 ,20,4);

const int TRIGGER = 2;
const int ECHO = 3;
const int servo = 6;
const int buzzer = 8;

NewPing sonar(TRIGGER, ECHO);
String dataLama = "";
String data = "";

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);
  myservo.attach(servo);
  myservo.write(0);
  delay(3000);
  myservo.detach();

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("ALAT PENDETEKSI");
  lcd.setCursor(7, 1);
  lcd.print("BANJIR");
  lcd.setCursor(1, 3);
  lcd.print("Aditya 13020190290");
}

void loop() {
  int jarak = sonar.ping_cm();
  delay(20);

  if(jarak > 16 && data != "off"){
    data = "off";
    myservo.attach(servo);
    myservo.write(0);
    delay(2000);
    myservo.detach();

    delay(1000);
  }

  if(jarak >=5 && jarak <=7){
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("SIAGA SATU");
      lcd.setCursor(2, 1);
      lcd.print("JARAK AIR ");
      lcd.print(jarak);
      lcd.print(" CM");
      lcd.setCursor(1, 3);
      lcd.print("Aditya 13020190290"); 

    if(jarak = 7){
      String dataJarak = String("SG 1,") + String("JK AIR:") + String(jarak) + String("CM ");
      if(dataJarak != dataLama){
        Serial.println(dataJarak+"BUKA BENDUNGAN");
        dataLama = dataJarak;
      }
      if(data !="on"){
        data = "on";
        myservo.attach(servo);
        delay(1000);
        myservo.write(180);
        delay(2000);
        myservo.detach();
      }
    }
      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);

      delay(2000);
      
  } else if(jarak >= 15 && jarak <=17) {

      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("SIAGA DUA");
      lcd.setCursor(2, 1);
      lcd.print("JARAK AIR ");
      lcd.print(jarak);
      lcd.print(" CM");
      lcd.setCursor(1, 3);
      lcd.print("Aditya 13020190290");

      if(jarak = 17){
        String dataJarak = String("SIAGA 2, ") + String("KETINGGIAN AIR : ") + String(jarak) + String(" CM");
        if(dataJarak != dataLama){
          Serial.println(dataJarak);
          dataLama = dataJarak;
        }
      } 

      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);

      delay(2000); 

  } else if(jarak >= 26 && jarak <=28) {
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("SIAGA TIGA"); 
      lcd.setCursor(2, 1);
      lcd.print("JARAK AIR ");
      lcd.print(jarak);
      lcd.print(" CM"); 
      lcd.setCursor(1, 3);
      lcd.print("Aditya 13020190290");

      if(jarak = 28){
        String dataJarak = String("SIAGA 3, ") + String("KETINGGIAN AIR : ") + String(jarak) + String(" CM");
        if(dataJarak != dataLama){
          Serial.println(dataJarak);
          dataLama = dataJarak;
        }  
        delay(1000);
      } 

      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(500);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);

      delay(2000);

  } else if (jarak > 28) {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("STATUS NORMAL");  
      lcd.setCursor(2, 1);
      lcd.print("JARAK AIR ");
      lcd.print(jarak);
      lcd.print(" CM");
      lcd.setCursor(1, 3);
      lcd.print("Aditya 13020190290");
      
      delay(2000);
  }

}
