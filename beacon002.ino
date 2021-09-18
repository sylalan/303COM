
#include <SoftwareSerial.h>
#include <EEPROM.h>
const int BTRX = 2;  // RX pin number
const int BTTX = 3;  // TX pin number
const int leng = 10; // Length of char value[]
SoftwareSerial BTSerial(BTRX,BTTX);

int addr = 0; // address index of EEPROM

void setup() {

  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  
}


void loop() {
  String phoneNum = ""; // Hiker's phone number
  char value[leng] = ""; // value to be get from / put to EEPROM
   
  if (BTSerial.available()) // If data received from Bluetooth serial port
  {
    digitalWrite(LED_BUILTIN,HIGH); // turn the LED on (HIGH is the voltage level)
    Serial.println("Data Received, LED on");

    phoneNum = BTSerial.readString(); // check received data (hiker's phone number)
    Serial.print("Phone Number = ");
    Serial.println(phoneNum);
    
    phoneNum.toCharArray(value,leng); // Prepare the value to be stored in EEPROM
    Serial.print("Value = ");
    Serial.println(value);
    
    EEPROM.put(addr, value); // store the data
    
    EEPROM.get(addr,value); // check the stored data
    Serial.print(addr);
    Serial.print("\t{");
    Serial.print(value);
    Serial.println("}");
    
    Serial.println("Data stored successfully.");
    
    addr += sizeof(value);  // Move to the next address index
    
    if (addr+leng >= EEPROM.length()) {  // When remaining address not enough to store next value, restart at the beginning.
      addr = 0;
    }
    
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    Serial.println("Finish, LED off");
    Serial.println("********************\n");

  }
}
