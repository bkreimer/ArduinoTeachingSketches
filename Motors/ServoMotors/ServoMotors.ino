#include <Servo.h>    // import some extra code for working with servos!

/*
SERVO MOTORS
 Jeff Thompson | 2013 | www.jeffreythompson.org
 
 When you need more control over a motor's position and speed,
 a servo is a great tool. Inside a servo's case is a regular
 DC motor, some gears, and a little bit of electronics to
 control the unit.
 
 A continuous-rotation servo (capable of going around many times)
 takes an argument between 0-180 that sets the speed. 0 = full speed
 in one direction, 180 = full speed in the other, and around 90
 will stop the motor.
 
 Our example 'tunes' these values and the time it takes to move
 90º and for the motor to be still.
 
 CHALLENGE:
 + Can you create a variable for 90º to be reused or as a multiple?
   What about 10, 5, or 1º increments?
 + What might you use a servo for that a regular DC motor wouldn't
   do well?
 + Notice how noisy your servo is? Can you make it play music? 
 
 */

Servo s;               // instance of the servo (max 8 per sketch)
int servoPin = 9;      // pin for servo

void setup() {
  s.attach(servoPin);  // connect the servo to pin 9
}

void loop() {
  // clockwise  
  s.write(0);          // 0 moves full speed in clockwise dir
  delay(620);          // 620ms will be very close to 90º

  // pause
  s.write(93);         // speed of 93 (or somewhere around 90) is still
  delay(1000);
  
  // counter-clockwise
  s.write(180);        // reverse direction full speed
  delay(620);          // back 90º
  
  // pause
  s.write(93);
  delay(1000);
}
