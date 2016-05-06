/*
 * Blink
 * Turns on an LED on for one second, then off for one second, repeatedly.
 *
 * Most Arduinos have an on-board LED you can control. On the Uno and
 * Leonardo, it is attached to digital pin 13. If you're unsure what
 * pin the on-board LED is connected to on your Arduino model, check
 * the documentation at http://www.arduino.cc
 *
 * This example code is in the public domain.
 *
 * modified 8 May 2014
 * by Scott Fitzgerald
 */

/*
 * Morse Code timing Reference: 
 *   https://en.wikipedia.org/wiki/Morse_code#Representation.2C_timing_and_speeds
 */
int ledPin = 13;
int dotMs = 200;
int dashMs = 3 * dotMs;
int elementGapMs = dotMs;
int letterGapMs  = dashMs;
//
// the setup function runs once when you press reset or power the board
//
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledPin, OUTPUT);
  // Serial.begin( 9600 );
}
//
// the loop function runs over and over again forever
// An "A" (for Arduino) in Morse Code is "dot dash"
//
void loop() {
  dot();
  delay(elementGapMs);   // leave it off for the desired gap between dashes and dots in a letter
  dash();
  delay(letterGapMs);    // leave it off for the desired gap between letters
  // Serial.println( "in loop fcn ledPin = " + ledPin );
}

//
// Turn the led on for dot milliseconds, then turn it off
//
void dot() {
  digitalWrite(ledPin, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(dotMs);                   // wait for "dot" number of milliseconds
  digitalWrite(ledPin, LOW);      // turn the LED off by making the voltage LOW
}
//
// Turn the led on for dash milliseconds, then turn it off
//
void dash() {
  digitalWrite(ledPin, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(dashMs);                  // wait for "dash" number of milliseconds
  digitalWrite(ledPin, LOW);      // turn the LED off by making the voltage LOW
}

