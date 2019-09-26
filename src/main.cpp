#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h>
#include <string.h>

const byte ROWS = 5;
const byte COLUMNS =4;
byte rowPins[ROWS] = {6,7,8,9,10}; //connect to row pinout of the keypad
byte columnPins[COLUMNS] = {2,3,4,5}; //connect to column pinout of keypad
//Define symbols on keypad
char hexakeys [ROWS][COLUMNS] = {
  {'A','B','#','*'},
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','E'},
  {'L','0','R','C'}
};

Keypad Customkeypad = Keypad(makeKeymap (hexakeys),rowPins,columnPins,ROWS, COLUMNS);

void receiveevent(int howmany);
void requestEvent();
int key;
int d;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(50);
  Wire.onReceive (receiveevent);
  Wire.onRequest (requestEvent);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(13,OUTPUT);  // LED
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  d =Customkeypad.getKey();

  if (d!= 0)
  {
    Serial.println(d);
    digitalWrite (13, HIGH);
  }
  
  while (digitalRead(13))
  {
    /* do nothing */
  }
  
}

void receiveevent(int howmany)
{
  while (Wire.available())
  {
    char c = Wire.read();
    switch (c)
    {
    case 'A':
      digitalWrite(10, HIGH);
      Serial.println(c);
      break;
    case 'a':
      digitalWrite(10, LOW);
      Serial.println(c);
      break;
    case 'B':
      digitalWrite(11, HIGH);
      Serial.println(c);
      break;
    case 'b':
      digitalWrite(11, LOW);
      Serial.println(c);
      break;
    case 'C':
      digitalWrite(12, HIGH);
      Serial.println(c);
      break;
    case 'c':
      digitalWrite(12, LOW);
      Serial.println(c);
      break;
    case 'K':
      key = 1;
      Serial.println(key);
      break;
    default:
      break;
    }   
  }
}

void requestEvent() {
  // Send response back to Master
  Wire.write(d);
  digitalWrite (13, LOW);
}
