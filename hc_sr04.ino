#include <Servo.h>
#include <hcrs04.h>  //for sensor


/***
 * hc-sr04 Ultrasonic Distance Module Example
 * Written By: Sheldon Will
 * Date: 02/04/14
 * Version: 1.0
 *
 * License: MIT License
 */

//Usage: Save this example to a new sketch folder and remove the .cpp & .h file within that new folder to get rid of multiple definition errors.

//Change thse values to reflect your pin setup.
#define PINTRIG 2
#define PINECHO 3

////////////////sensor setup//////////
//Simply replace "PINTRIG" and "PINECHO" with your corresponding defines.
hcrs04 mySensor(PINTRIG, PINECHO);
///////////////servo setup/////////
Servo myservo;  // create servo object to control a servo: max 8 servos
int pos = 0;    // variable to store the servo position 
 
void setup()
{
  //Necessary for sensor
  Serial.begin(9600);
  Serial.println("Basic HC-SR04 Ultrasonic Sensor Example");
  mySensor.begin();
  //Necessary for servo
  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop()
{
  //Servo Code
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  //Sensor Code: Get results from the sensor
  float DISTANCE = mySensor.read(); 
  Serial.print(DISTANCE);
  Serial.println(" cm");
  delay(500);
}