#include <Arduino.h>
#include "Lcd.h"

Lcd lcd(0x3F,16,2);

void setup() {
  lcd.begin();
}

void loop() {
  lcd.write(0,0,"hello, world!");
}
