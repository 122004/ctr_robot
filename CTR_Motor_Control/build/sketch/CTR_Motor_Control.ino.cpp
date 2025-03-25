#include <Arduino.h>
#line 1 "C:\\Users\\Owner\\Downloads\\Trash robot\\ctr_robot\\CTR_Motor_Control\\CTR_Motor_Control.ino"
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


#line 16 "C:\\Users\\Owner\\Downloads\\Trash robot\\ctr_robot\\CTR_Motor_Control\\CTR_Motor_Control.ino"
void setup();
#line 23 "C:\\Users\\Owner\\Downloads\\Trash robot\\ctr_robot\\CTR_Motor_Control\\CTR_Motor_Control.ino"
void loop();
#line 16 "C:\\Users\\Owner\\Downloads\\Trash robot\\ctr_robot\\CTR_Motor_Control\\CTR_Motor_Control.ino"
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
    arm.write();
    delay(100);
    dish.write(180);
    delay(100);
    dish.write(0);
  }

  if (trash == true){
    delay(100);
    base.write(90);
    delay(100);
    arm.write();
    delay(100);
    dish.write(180);
    delay(100);
    dish.write(0);
  }

  if (recycling == true){
    delay(100);
    base.write(135);
    delay(100);
    arm.write();
    delay(100);
    dish.write(180);
    delay(100);
    dish.write(0);
  }
 // add return to initial set position
}
