//I2C SLAVE CODE

#include<Wire.h>                          //Library for I2C Communication functions


void setup(){
  Wire.begin(4); //Begins I2C communication with Slave Address as 8
  Wire.onReceive(receiveEvent); //Function call when Slave receives value from master
  Wire.onRequest(requestEvent);
  Serial.begin(9600);  //Begins Serial Communication at 9600 baud rate                
} 


void loop(void) 

{

  delay(100);


}


void receiveEvent (int howMany)                    //This Function is called when Slave receives value from master

{
  //Serial.println("\nEstas aqui??");   
  while(0<Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  
  }
  Serial.print('\n');                   

}

void requestEvent()                           //This Function is called when Master wants value from slave
{
  String my_string = "\r\nOla eu sou o arduino";
  unsigned int string_size = my_string.length(); 
  //Serial.println("\nOlha aqui: "); 
  //Serial.println(string_size);
 // byte SlaveSend = 'S';    
  //Serial.println("\nOlha aqui: "); 
  //Serial.println((char)SlaveReceived); 
  Wire.write(my_string.c_str());
  //Wire.write(SlaveSend);                          // sends one byte converted POT value to master

}