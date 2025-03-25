#include <Servo.h>

Servo base;
Servo arm;
Servo dish;

int basepos = 0;
int armpos = 0;
int dishpos = 0;

bool compost = false;
bool trash = false;
bool recycling = false;


void setup() {
  base.attach(9);
  arm.attach(10);
  dish.attach(11);

}

void loop() {
  if (compost == true){
    delay(100);
    base.write(45);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    dish.write(0);
  }

  if (trash == true){
    delay(100);
    base.write(90);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    dish.write(0);
  }

  if (recycling == true){
    delay(100);
    base.write(135);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    dish.write(0);
  }
 // need to add return to initial set position
}