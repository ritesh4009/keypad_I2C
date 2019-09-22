#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 5;
const byte COLUMNS =4;
byte rowPins[ROWS] = {13,12,11,10,9}; //connect to row pinout of the keypad
byte columnPins[COLUMNS] = {A2,A3,A0,A1}; //connect to column pinout of keypad
//Define symbols on keypad
char hexakeys [ROWS][COLUMNS] = {
  {'A','B','#','*'},
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','E'},
  {'<','0','>','C'}
};

Keypad Customkeypad = Keypad(makeKeymap (hexakeys),rowPins,columnPins,ROWS, COLUMNS);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}