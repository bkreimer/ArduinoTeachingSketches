/*
READING ANALOG VALUES
Jeff Thompson | 2013 | www.jeffreythompson.org

Unlike a digital sensor which only has two possible states (on
or off), analog sensors have an infinite number of states between
their min/max - until they enter the Arduino!  Since the Arduino
is digital, we convert the sensor values using the "analog-to-digital
converter", or ADC.  This stairsteps our analog values, making
a fairly decent approximation of analog input.

** In the case of the Arduino, this stairstepping has 1024 possible
values (0-1023).  However, getting this full range requires that
we tune our voltage divider circuit to maximize the sensor's output.

SCHEMATIC:
10k ohm potentiometer  
either end of pot +--------- +5V
                       
middle pin on pot +--+------ analog pin
                     |
              90-100k resistor
                     |
                    GND
                    
VOLTAGE DIVIDER:
To find the best value for the resistor, we use the voltage divider
formula, which can be stated as:
  Vout = (R2/(R1 + R2)) * Vin
  
Converted to find the second resistor:
  R2 = R1 / ((Vin/Vout) - 1)
  
So in our case:
  R2 = 10,000 / ((5/4.5) - 1)
  R2 = 10,000 / (1.11111111 - 1)
  R2 = 90,000 (or approximately 90-100k)

CHALLENGE:
+ What other parameters of the LED can you map the potentiometer's
  rotation to?
+ Can you use the pot's rotation to generate text of some kind?
+ Use a multimeter to find the min/max range for your other sensors;
  calculate the necessary resistor to make an optimal voltage divider.

Based on the 'AnalogInput' sketch from the Arduino examples.
*/

int sensorPin = A0;    // variable for analog pin (specified as A0-A5)
int sensorVal = 0;     // variable to read sensor value
int ledPin = 13;       // change LED blink rate based on sensor input!

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  // read the sensor's value (0-1023**)
  sensorValue = analogRead(sensorPin);
  
  // set the LED's blink to the sensor value
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
  
