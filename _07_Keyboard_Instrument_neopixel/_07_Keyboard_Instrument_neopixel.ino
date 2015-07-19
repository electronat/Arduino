#include <Adafruit_NeoPixel.h>
 
#define PIN      6
#define N_LEDS 2
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int buttons[6];

int notes[] = {262,294,330,349};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  buttons[0] = 2;
  strip.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyVal = analogRead(A0);
  Serial.println(keyVal);
  
  if(keyVal == 1023){
    tone(8, notes[0]);
    chase(strip.Color ( 44,  21,  0)); // redest orange
  }
  else if(keyVal >= 990 && keyVal <= 1010){
    tone(8, notes[1]);
    chase(strip.Color ( 24,  0,  24)); // magenta
  }
  else if(keyVal >= 505 && keyVal <= 515){
    tone(8, notes[2]);
    chase(strip.Color (  17,  0, 44)); // purple
  }
  else if(keyVal >= 5 && keyVal <= 10){
    tone(8, notes[3]);
    chase(strip.Color (  0, 10,  44)); // royal blue
  }
  else{
    noTone(8);
    chase(strip.Color (  44,  30, 0)); //slightly yellower
  }
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-1, 0); // Erase pixel a few steps back
      strip.show();
      delay(1);
  }
}
