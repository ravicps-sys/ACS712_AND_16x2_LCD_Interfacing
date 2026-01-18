#include <LiquidCrystal.h>

// LCD pin connections
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  const char jyothis[] = "JYOTHIS";
  const char electronics[] = "ELECTRONICS :)";
  lcd.setCursor(0,0);

  for (int i = 0; i < 7; i++) {   // 7 letters
    lcd.print(jyothis[i]);
    delay(100);                  // 100 ms delay
  }
  lcd.setCursor(0,1);
  for (int i = 0; i < sizeof(electronics)/sizeof(char) - 1; i++) {   // 7 letters
    lcd.print(electronics[i]);
    delay(100);                  // 100 ms delay
  }
  delay(1000);  // wait before repeating
}
