

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUMPIXELS 50
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 //pin variables
int delayval = 10;

const int soundPin = 0;

//variables for storing raw sound and scaled value
int sound;
int scale;

void setup()
{
 //start the serial port a@ 9600bps
  Serial.begin(9600);
 //set RGB pins to OUTPUT
 pixels.begin();
 //pinMode(redPin, OUTPUT);
 //pinMode(greenPin, OUTPUT);
 //pinMode(bluePin, OUTPUT);
}

void loop()
{
 //read and store the audio from Envelope pin
 sound = analogRead(soundPin);
 //map sound which in a quiet room a clap is 300
 //from 0 to 3 to be used with switch case
 scale = map(sound, 0, 300, 0, 3);

 //print values over the serial port for debugging
 Serial.print(sound);
 Serial.print("   ");
 Serial.println(scale);

 //switch case on scaled value
switch (scale)
{
//if 0 RGB = Blue
case 0:
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,150,150)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  break;
//if 1 RGB = Green  
case 1:
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(150,0,150)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds)
  }
  break;
//if 2 RGB = Yellow  
case 2:
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds)
  }
  break;
//if 3 RGB = Red
case 3:
 for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,150)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds);
 }
  break;
//default off
default:
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds)
  }
  break;
  }
}
