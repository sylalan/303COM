/***
  Print out all values stored inside EEPROM
***/

#include <EEPROM.h>
const int leng = 10; // Length of char value[]

int addr = 0; //address index of EEPROM
char value[leng]; //value to be get from EEPROM

void setup() {

  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  
  Serial.print("EEPROM.length() = ");
  Serial.println(EEPROM.length());
  
  for (addr = 0; addr < EEPROM.length(); addr+=leng) // Get stored data, jump to next address index, until reach the last EEPROM address
  {
    digitalWrite(LED_BUILTIN,HIGH); // turn the LED on (HIGH is the voltage level)
    EEPROM.get(addr,value); // get value from EEPROM
    Serial.print(addr);
    Serial.print("\t{");
    Serial.print(value);
    Serial.println("}");
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
  }
  Serial.end();

}


void loop() {

}
