int timer = 300;
int myPins[] = {2,3,4,5,6,7,8,9,10,11,12,13,44,45,46};
//int myBrightnesses[] = {0, 17, 34, 51, 68, 85, 102, 119, 136, 153, 170, 187, 204, 221, 238};
//int myBrightnesses[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int myBrightnesses[] = {3,6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45};
int myFadeamounts[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int pinCount = 15;
int brightness = 0;    // how bright the LED is
int fadeAmount = 3;    // how many points to fade the LED by
 
 void setup() {
    Serial.begin(9600);
   // set  the transistor pin as output:
     for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(myPins[thisPin], OUTPUT);
  }
 }
 
 void loop() {
  // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      // turn the pin on:
      delay(2);
      analogWrite(myPins[thisPin], myBrightnesses[thisPin]);
      // change the brightness for next time through the loop:
      myBrightnesses[thisPin] = myBrightnesses[thisPin] + myFadeamounts[thisPin];
      // reverse the direction of the fading at the ends of the fade:
      if (myBrightnesses[thisPin] <= 2 || myBrightnesses[thisPin] >= 250) {
        myFadeamounts[thisPin] = -myFadeamounts[thisPin];
      }
      // wait for 30 milliseconds to see the dimming effect
      delay(0);
  }
 }
