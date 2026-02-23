#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
#define PIR 4 // Input for HC-S501
#define BLUE 3 // Input for HC-S501
#define GREEN 5 // Input for HC-S501
#define RED 6 // Input for HC-S501
int pirValue; // Place to store read PIR Value
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
}

void loop() {
   if (digitalRead(PIR) == LOW) { 
    digitalWrite(RED, LOW); 
    digitalWrite(GREEN, HIGH);
  } else {
    digitalWrite(RED, HIGH); 
    digitalWrite(GREEN, LOW);
  }
}


