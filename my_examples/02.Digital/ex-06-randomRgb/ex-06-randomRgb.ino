/* 
 * Random RGB - set random intervals (cycles) for the three leds
 *
 * Turns on and off a light emitting diode (LED) connected to a digital
 * pin, without using the delay() function.  This means that other code
 * can run at the same time without being interrupted by the LED code.
 *
 * The circuit:
 * - 3 LEDs attached to pins 2, 3, and 4
 *
 * created 2005 - by David A. Mellis
 * modified 8 Feb 2010 - by Paul Stoffregen
 * modified 11 Nov 2013 - by Scott Fitzgerald
 * modified 15 May 2016 - by Tom Hartung
 *
 * This example code is in the public domain.
 * http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */
//
// constants won't change. Used here to set the pin numbers:
//
const int ledPin2 = 2;      // LED on pin 2
const int ledPin3 = 3;      // LED on pin 3
const int ledPin4 = 4;      // LED on pin 4
//
// Variables will change:
//
int ledPin2State = HIGH;             // ledState used to set LED 2
int ledPin3State = HIGH;             // ledState used to set LED 3
int ledPin4State = HIGH;             // ledState used to set LED 4
//
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
//
unsigned long currentMillis = 0;
unsigned long led2LastMillis = 0;        // last time LED 2 was updated
unsigned long led3LastMillis = 0;        // last time LED 3 was updated
unsigned long led4LastMillis = 0;        // last time LED 4 was updated

int maxCycleSecs = 3;
unsigned long led2CycleMillis = 1000;           // interval at which to blink led 2 (milliseconds)
unsigned long led3CycleMillis = 1000;           // interval at which to blink led 3 (milliseconds)
unsigned long led4CycleMillis = 1000;           // interval at which to blink led 4 (milliseconds)
/**
 * return a random number of milliseconds for cycling an led
 */
unsigned long getRandomCycleMillis() {
  unsigned long maxCycleMillis = 1000 + maxCycleSecs;
  unsigned long randomCycleMillis = random( maxCycleMillis );
  return randomCycleMillis;
}
/**
 * Setup the pins and output
 */
void setup() {
  // set the digital pins as output:
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
  currentMillis = millis();
  led2LastMillis = millis();
  led3LastMillis = millis();
  led4LastMillis = millis();
  Serial.println( currentMillis );
}

/**
 * Loop: here is where you'd put code that needs to be running all the time.
 */
void loop() {
  currentMillis = millis();
  // Serial.println( currentMillis );

  if( currentMillis - led2LastMillis >= led2CycleMillis ) {
    led2LastMillis = currentMillis;       // save the last time you blinked the LED
    //
    // toggle the LED
    //
    if (ledPin3State == LOW) {
      ledPin2State = HIGH;
    } else {
      ledPin2State = LOW;
    }
    digitalWrite(ledPin2, ledPin2State);    // set the LED with the ledState of the variable:
  }
  if( currentMillis - led3LastMillis >= led3CycleMillis ) {
    led3LastMillis = currentMillis;       // save the last time you blinked the LED
    //
    // toggle the LED
    //
    if (ledPin3State == LOW) {
      ledPin3State = HIGH;
    } else {
      ledPin3State = LOW;
    }
    digitalWrite(ledPin3, ledPin3State);    // set the LED with the ledState of the variable:
  }
  if( currentMillis - led4LastMillis >= led4CycleMillis ) {
    led4LastMillis = currentMillis;       // save the last time you blinked the LED
    //
    // toggle the LED
    //
    if (ledPin4State == LOW) {
      ledPin4State = HIGH;
    } else {
      ledPin4State = LOW;
    }
    digitalWrite(ledPin4, ledPin4State);    // set the LED with the ledState of the variable:
  }
}

