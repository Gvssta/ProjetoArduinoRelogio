#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int h = 23;
int m = 59;
int s = 45;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  lcd.setCursor(0, 0);
  lcd.print("Hora: ");
  lcd.print(h);
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
  delay(1000);
}