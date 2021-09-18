
#include <SoftwareSerial.h>
#include <EEPROM.h>
const int BTRX = 2;  // Bluetooth RX pin number
const int BTTX = 3;  // Bluetooth TX pin number
const int leng = 10; // Length of value
SoftwareSerial BTSerial(BTRX,BTTX);

int addr = 0; //address in the EEPROM
//char value[leng]; //value to be get from / put to EEPROM

void setup() {

  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  
}


void loop() {
  String phoneNum = "";
  char value[leng] = ""; //value to be get from / put to EEPROM
   
  if (BTSerial.available()) // If data received from Bluetooth serial port
  {
    digitalWrite(LED_BUILTIN,HIGH); // turn the LED on (HIGH is the voltage level)
    Serial.println("Data Received, LED on");

    phoneNum = BTSerial.readString(); // check received data (hiker's phone number)
    //phoneNum = BTSerial.read();
    Serial.print("Phone Number = ");
    Serial.println(phoneNum);
    
    phoneNum.toCharArray(value,leng); // Prepare the value to be stored in EEPROM
    Serial.print("Value = ");
    Serial.println(value);
    
    //delay(1000);  // wait for a second
        
    EEPROM.put(addr, value); // store the data
    //EEPROM.write(addr, phoneNum);
    
    //EEPROM.get(addr,value);     // check the stored data
    //value = EEPROM.read(addr);
    //Serial.print(addr);
    //Serial.print("\t");
    //Serial.println(value);
    //for (int i = 0; i < addr; i++)
    for (int i = 0; i < EEPROM.length(); i++)
    {
      EEPROM.get(i,value);
      //value = EEPROM.read(i);
      Serial.print(i);
      Serial.print("\t{");
      Serial.print(value);
      Serial.println("}");
    }

    Serial.println("Data stored successfully.");
  
    //addr ++;  //move to the next address
    addr += sizeof(value);
    
    if (addr+leng >= EEPROM.length()) {  //when remaining address not enough to store next value, restart at the beginning.
      addr = 0;
    }
    
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    Serial.println("Finish, LED off");
    Serial.println("********************\n");

  }
}
