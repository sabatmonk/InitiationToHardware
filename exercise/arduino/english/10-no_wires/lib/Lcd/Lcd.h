#ifndef Lcd_h
#include <Arduino.h>
#include "LiquidCrystal_I2C.h"
#define Lcd_h

class Lcd
{
  public:
    Lcd(int addr, int cols, int rows);
    void begin();
    void write(int col, int row, const char* text);
    void empty();
  private:
    LiquidCrystal_I2C _screen;
    int _addr;
    int _cols;
    int _rows;
};

#endif

