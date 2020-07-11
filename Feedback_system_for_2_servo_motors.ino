
#include <Servo.h>
#include <EEPROM.h>
 
 
int ButtonPin = 4;
int ButtonState = 0 ;
int servo1Pin = 2;
int servo2Pin = 3;
int analogPin = A0;
byte ReadValue = 0;
int x = 0;
byte y = 0;
int i;
Servo servo1;
Servo servo2;


void setup()

{
  pinMode(ButtonPin, INPUT);
  servo1.attach(2);
  servo2.attach(3);
  servo1.write(0);
  servo2.write(0);
  
}
 
void loop() {
  
  

  ButtonState = digitalRead(ButtonPin);
  
  

  
 if (ButtonState == HIGH) // it will start recording the values of the first motor when the button is clicked
 
 {

  for (i = 0 ; i <= 200 ; i++){
    
    
   x = analogRead(analogPin);
   y = map(x,0,1023,0,180); // this will change the vaule of the analog read to a value suitable to be a servo angle
   servo1.write(y);
   EEPROM.write(i,y); // store the value in address (i)
   delay(500);
   ReadValue = EEPROM.read(i); // read the adress (i)
   servo2.write(ReadValue); // servo 2 will rotate with the angle stored in address (i)
   
   
  }
 }

}

 
  
    


  
  

  

 
  
 
  
