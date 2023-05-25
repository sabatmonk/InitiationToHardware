#include <Arduino.h>
#include "Lcd.h"

Lcd::Lcd(int addr, int cols, int rows) : _screen(addr,cols,rows){
    _addr = addr;
    _cols = cols;
    _rows = rows; 
}

void Lcd::begin(){
  _screen.init();
  _screen.clear();         
  _screen.backlight();
}

void Lcd::write(int col, int row, const char* text){
    _screen.setCursor(col, row);
    _screen.print(text);
}

void Lcd::empty(){
    _screen.clear();
}

