#include <Arduino.h>
#line 1 "C:\\Users\\Owner\\Downloads\\Trash robot\\ctr_robot\\CTR_Motor_Control\\CTR_Motor_Control.ino"
#include <Servo.h>

Servo base;
Servo arm;
Servo dish;

int basepos = 0;
int armpos = 0;
int dishpos = 0;

bool compost = true;
bool trash = false;
bool recycling = false;


#line 16 "C:\\Users\\Owner\\Downloads\\Trash robot\\ctr_robot\\CTR_Motor_Control\\CTR_Motor_Control.ino"
void setup();
#line 25 "C:\\Users\\Owner\\Downloads\\Trash robot\\ctr_robot\\CTR_Motor_Control\\CTR_Motor_Control.ino"
void loop();
#line 16 "C:\\Users\\Owner\\Downloads\\Trash robot\\ctr_robot\\CTR_Motor_Control\\CTR_Motor_Control.ino"
void setup() {
  base.attach(9);
  arm.attach(10);
  dish.attach(11);



}

void loop() {
  if (compost == true){
    //move to recepticle
    delay(100);
    base.write(45);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    //return to starting position
    base.write(135);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    compost = false;
    
  }

  if (trash == true){
    //move to recepticle
    delay(100);
    base.write(90);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    //return to starting position
    base.write(135);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    trash = false;
    
  }

  if (recycling == true){
    //move to recepticle
    delay(100);        
    base.write(135);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    //return to starting position
    base.write(135);
    delay(100);
    arm.write(0);
    delay(100);
    dish.write(180);
    delay(100);
    recycling = false;
  }

}

