#include <Servo.h>
#include <SoftwareSerial.h>

Servo base;
Servo arm;
Servo dish;

const byte rxPin = 3; 
const byte txPin = 2;
SoftwareSerial bluetooth(rxPin, txPin);

int basepos = 0;
int armpos = 0;
int dishpos = 0;

int switchPin = 8;

void setup() {
  base.attach(9);
  arm.attach(10);
  dish.attach(11);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  bluetooth.begin(9600); // runs bluetooth serial port
  Serial.begin(9600); // runs physical serial port on computer at same rate
 
}

void loop() {

  //for testing
  //count = count + 10;
  //arm.write(count);
  //delay(1000);

  if (digitalRead(switchPin) == LOW) {
    //return to starting position
    dish.write(125);
    delay(2500);
    arm.write(130);
    delay(2500);
    base.write(115);
    delay(2500);

   while (bluetooth.available() > 0) { // check if new data available
      int ctr = (int) bluetooth.read(); // if there is then read it to ctr
      if (ctr == 1) { // COMPOST
        //move to recepticle
        delay(2500);
        base.write(80);
        delay(2500);
        arm.write(100);
        delay(2500);
        dish.write(0);
        delay(2500);
        //return to starting position
        dish.write(125);
        delay(2500);
        arm.write(130);
        delay(2500);
        base.write(115);
        delay(2500);
        ctr = 0;
      }
      if (ctr == 2){ // TRASH
        //move to recepticle
        delay(2500);
        base.write(115);
        delay(2500);
        arm.write(150);
        delay(2500);
        dish.write(0);
        delay(2500);
        //return to starting position
        dish.write(125);
        delay(2500);
        arm.write(130);
        delay(2500);
        base.write(115);
        delay(2500);
        ctr = 0;
      }
      if (ctr == 3){ // RECYCLING
        //move to recepticle
        delay(2500);
        base.write(170);
        delay(2500);
        arm.write(90);
        delay(2500);
        dish.write(0);
        delay(2500);
        //return to starting position
        dish.write(125);
        delay(2500);
        arm.write(120);
        delay(2500);
        base.write(115);
        delay(2500);
        ctr = 0;
      }
    }
  }
}
