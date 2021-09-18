/***
  Print out all values stored inside EEPROM
***/

#include <EEPROM.h>

int addr = 0; //address in the EEPROM
char value[10]; //value to be get from / put to EEPROM

void setup() {

  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  
  Serial.print("EEPROM.length() = ");
  Serial.println(EEPROM.length());
  
  for (addr = 0; addr < EEPROM.length(); addr++)
  {
    digitalWrite(LED_BUILTIN,HIGH); // turn the LED on (HIGH is the voltage level)
    EEPROM.get(addr,value);
    //value = EEPROM.read(addr);
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
