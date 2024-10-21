#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int h = 23;
int m = 59;
int s = 45;
int buttonClockIn = 6;
int buttonClockOut = 7;
void setup() {
  pinMode(buttonClockIn, INPUT_PULLUP);
  pinMode(buttonClockOut, INPUT_PULLUP);
}

void setup() {
  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  lcd.setCursor(0, 0);
  lcd.print("Hora: ");
  lcd.print(h);
}
void updateTimeDisplay() {
  lcd.setCursor(0, 0);
  lcd.print("Hora: ");
  lcd.print(h < 10 ? "0" : ""); lcd.print(h);
  lcd.print(":");
  lcd.print(m < 10 ? "0" : ""); lcd.print(m);
  lcd.print(":");
  lcd.print(s < 10 ? "0" : ""); lcd.print(s);
}

void updateClockTime() {
  s++;
  if (s >= 60) {
    s = 0; m++;
  }
  if (m >= 60) {
    m = 0; h++;
  }
  if (h >= 24) {
    h = 0;
  }
}

void loop() {
  updateClockTime();
  updateTimeDisplay();
  delay(1000);
}