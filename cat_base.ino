#include <Adafruit_CircuitPlayground.h>


int ledPin = 13; // select pin for LED


// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;

int sensorPin1 = A0; // selects the inuput pin for the elbow_L sensor
int sensorPin2 = A1; // selects the input pin for the wrist_R sensor
int sensorValue1 = 0; // variable to store the value coming from the sensor
int sensorValue2 = 0; // variable to store the value coming from the sensor


void setup() {
  // initialize serial communication at 9600 bits per second:
  CircuitPlayground.begin(); // turn ON the Circuit 
  Serial.begin(9600); // turn ON the circuit sensor
  pinMode(ledPin, INPUT); // activate the LED and incoming value


  CircuitPlayground.clearPixels();
  defaultCol();

}

void loop() {
  // turn off speaker when not in use
  CircuitPlayground.speaker.enable(false);


/* previous entries / was taking too long.  Delete if alternative is found
  CircuitPlayground.setPixelColor(0,0,0,0);
  CircuitPlayground.setPixelColor(1,0,0,0);
  CircuitPlayground.setPixelColor(2,0,0,0); */

  
  // read the value from the sensor; 
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  Serial.println(sensorValue1);
  Serial.println(sensorValue2);
  
  //turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(100);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for <sensorValue1> milliseconds:

/*  previous entries / was taking too long.  Delete if alternative is found
 if (sensorValue>=800) {
    CircuitPlayground.setPixelColor(0,150,90,150);
    CircuitPlayground.setPixelColor(1,10,163,200);
    CircuitPlayground.setPixelColor(2,90,16,200); 
     delay(100); */


//for (int f =0; f<) {}
  
Serial.println(sensorValue1); 
Serial.println(sensorValue2);

if (sensorValue1>=400) {
  rainbow();
  delay(10);
  } else {
  defaultCol();
  }

  if (sensorValue2>=800) {
  rainbow();
  delay(10);
  } else {
  defaultCol();
  }

}

void defaultCol() {
  
     CircuitPlayground.setPixelColor(0,15, 38, 228);
     CircuitPlayground.setPixelColor(1,255, 0, 179);
     CircuitPlayground.setPixelColor(2,15, 38, 228);
     CircuitPlayground.setPixelColor(3,255, 0, 179);
     CircuitPlayground.setPixelColor(4,15, 38, 228);
     CircuitPlayground.setPixelColor(3,255, 0, 179);
     CircuitPlayground.setPixelColor(6,15, 38, 228);
     CircuitPlayground.setPixelColor(7,255, 0, 179);
     CircuitPlayground.setPixelColor(8,15, 38, 228);
     CircuitPlayground.setPixelColor(9,255, 0, 179);
}

void rainbow() {

  CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * pixeln));
  if (pixeln == 11) {
    pixeln = 0;
    CircuitPlayground.clearPixels();
    }

  }
void tempRed() {
   CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(2 * pixeln));
  if (pixeln == 11) {
    pixeln = 0;
    CircuitPlayground.clearPixels();
    }
} 
