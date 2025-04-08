#include <Servo.h>

Servo base;
Servo arm;
Servo dish;

int basepos = 0;
int armpos = 0;
int dishpos = 0;

bool compost = false;
bool trash = true;
bool recycling = false;
int count = 0;

int switchPin = 8;


void setup() {
  base.attach(9);
  arm.attach(10);
  dish.attach(11);
  pinMode(switchPin, INPUT_PULLUP);
 
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
  

    if (compost == true){
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
      compost = false;
      trash = true;
    
   }

    if (trash == true){
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
      trash = false;
      recycling = true;
      
    }

    if (recycling == true){
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
      recycling = false;
    }

  }

}
