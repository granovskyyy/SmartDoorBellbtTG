#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
#define PIR 4 // Input for HC-S501
#define BLUE 3 // Input for HC-S501
#define GREEN 5 // Input for HC-S501
#define RED 6 // Input for HC-S501
Servo myservo;

int lastState = -1;
void setup() {
  lcd.begin(16, 2);
  lcd.print("Enter password");
  pinMode(PIR,INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  myservo.attach(2);
}

void loop() {
  int pirValue = digitalRead(PIR);
  if (pirValue != lastState) {
    lcd.clear();

    if (pirValue == HIGH) {   // wykryto ruch
        lcd.print("ALARM");
        digitalWrite(RED, HIGH);
        digitalWrite(GREEN, LOW);
        myservo.write(0);
    }else {                  // brak ruchu
        lcd.print("WELCOME");
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, HIGH);
        myservo.write(90);
    }

      lastState = pirValue;
    }
}


