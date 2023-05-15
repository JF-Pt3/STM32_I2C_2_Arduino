//I2C SLAVE CODE

#include<Wire.h>                          //Library for I2C Communication functions


void setup(){
  Wire.begin(4); //Begins I2C communication with Slave Address as 8
  Wire.onReceive(receiveEvent); //Function call when Slave receives value from master
  Serial.begin(9600);  //Begins Serial Communication at 9600 baud rate                
} 


void loop(void) 

{

  delay(100);


}


void receiveEvent (int howMany)                    //This Function is called when Slave receives value from master

{

  while(0<Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  
  }
  Serial.print('\n');                   

}