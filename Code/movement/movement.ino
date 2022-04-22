#include "Enes100.h"
#include "Servo.h"

// Links
// https://github.com/BlackrazorS2/ENES100-OSV
// http://enes100.umd.edu/libraries/enes100
// https://create.arduino.cc/projecthub/ryanchan/how-to-use-the-l298n-motor-driver-b124c5
// https://create.arduino.cc/projecthub/abdularbi17/ultrasonic-sensor-hc-sr04-with-arduino-tutorial-327ff6
// https://create.arduino.cc/projecthub/diyguyChris/high-torque-servo-motor-control-35b1cc

    //digital pins

    int TX_PIN = 12;
    int RX_PIN = 13;
    int SERVO_PIN = 11;
    int LEFT_MOTOR_PIN1 = 2, LEFT_MOTOR_PIN2 = 3;
    int RIGHT_MOTOR_PIN1 = 4, RIGHT_MOTOR_PIN2 = 5;
    int ULTRA_SONIC_PWM = 6, ULTRA_SONIC_PIN2 = 7;
    int MAGNET_PIN = 8;

    //analog pins

    int SIGNAL_PIN = 9;
    
    //other
    float pwm_value = 0;
    double num = 0.0;

    double duration;
    double ultraDistance;
    Servo myServo;
    int MARKER_ID = 8;
    
    double xPos, yPos, angle;
    boolean startingPosition; //Top is true, bottom is false

    //constants
    
    boolean LEFT = true;
    boolean RIGHT = false;
   
void setup() {
    // Initialize Enes100 Library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    
    Enes100.begin("Frostbytes", DATA, MARKER_ID, TX_PIN, RX_PIN);

    //Inputs

    pinMode(MAGNET_PIN, INPUT);
    pinMode(SIGNAL_PIN, OUTPUT);
    pinMode(ULTRA_SONIC_PIN2, INPUT);

    myServo.attach(SERVO_PIN);

    //Outputs
    
    pinMode(LEFT_MOTOR_PIN1, OUTPUT);
    pinMode(LEFT_MOTOR_PIN2, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
    pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
    pinMode(SERVO_PIN, OUTPUT);
    pinMode(ULTRA_SONIC_PWM, OUTPUT);

    Serial.begin(9600);
    Serial.println("Running");
}

void loop() {


    // Update the OSV's current location

    //START OF TESTING CODE
    /*
    delay(10000); //gives us time to get to the arena
    Enes100.println("Half way to starting");
    delay(10000); 
    Enes100.println("Starting now");
    */

    //NAVIGATE MISSION TEST
    /*
    if (resetLocation() == false) {
      // emergency reverse
      Enes100.println("BRUH HOW OUT OF AREANNA");
      Enes100.println("WRITE THIS LATER, PROLLY BACKUP OSV");
      delay(1000);
    } else {
       Enes100.updateLocation();
       Enes100.println("Location found");  //DELETE LATER 
       Enes100.print("x Position is: ");
       Enes100.println(xPos);
       Enes100.print("y Position is: ");
       Enes100.println(yPos);
       Enes100.print("Current angle is: ");
       Enes100.println(angle);
       delay(1000);
    }
    
    Enes100.println("7 seconds until start");
    delay(7500);
    Enes100.println("Starting now");
    driveForwards(.2);
    Enes100.updateLocation();
       Enes100.println("Location found");  //DELETE LATER 
       Enes100.print("x Position is: ");
       Enes100.println(xPos);
       Enes100.print("y Position is: ");
       Enes100.println(yPos);
       Enes100.print("Current angle is: ");
       Enes100.println(angle);
       delay(1000);
    delay(500);
    raiseArm(5);
    */

    //LIMBO TEST
    /*
    delay(15000);
    Serial.println("Moving now");
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
    */
    
    //SERVO TEST
    /*
    delay(3000);
    raiseArm(10);
    Serial.println("Moved");
    delay(1000);
    raiseArm(0);
    Serial.println("Moved");
    delay(1000);
    raiseArm(10);
    Serial.println("Moved");
    delay(1000);
    */

    //MOVEMENT FUNCTIONS TEST
    /*
    driveForwards(1);
    turn(PI/2, LEFT);
    turn(0, RIGHT);
    driveReverse(1);
    */

    //SIGNAL TEST (ADD TO FUNCTION LATER)
    
    pwm_value = pulseIn(SIGNAL_PIN, HIGH);

    num = round(pwm_value / 1000.0);
    Serial.println("Duty Cycle: ");
    Serial.println((int) num);
    delay(1000);
    
    
//    Enes100.println("Signal is: ");
//    Enes100.println(getSignal());
//    Serial.println("Signal is: ");
//    Serial.println(getSignal());
//    delay(500);
    

    /*
    //MAGNET TEST
    
    boolean magnetic = getMagnetism();
    if (magnetic){
      Enes100.println("The puck was magnetic");
      Serial.println("The puck was magnetic");
      Enes100.mission(MAGNETISM, true);
    } else {
      Enes100.println("The puck was not magnetic");
      Serial.println("The puck was not magnetic");
      Enes100.mission(MAGNETISM, false);
    }
    delay(1000);
    */

    //COMPLETE ARM TEST (Starting at mission site)
    /*
    raiseArm(5); //idk what angle to put here
    double signal;
    boolean magnetic;
    while (getSignal() < .3){
      signal = getSignal();
      magnetic = getMagnetism();
      wiggle();
    }
    Enes100.print("The signal is: ");
    Enes100.println(signal);
    if (magnetic){
      Enes100.print("The puck was magnetic");
    } else {
      Enes100.print("The puck was not magnetic");
    }
    raiseArm(-5);
    */
    
    
    //ULTRA SONIC TEST

    /*
    Enes100.println("Ultra sonic sensor distance");
    Enes100.println(getObstacleDistance());
    delay(500);
    */
    
    //TESTING ARUCO
    /*
    if (resetLocation() == false) {
      // emergency reverse
      Enes100.println("BRUH HOW OUT OF AREANNA");
      Enes100.println("WRITE THIS LATER, PROLLY BACKUP OSV");
      delay(1000);
    } else {
       Enes100.updateLocation();
       Enes100.println("Location found");  //DELETE LATER 
       Enes100.print("x Position is: ");
       Enes100.println(xPos);
       Enes100.print("y Position is: ");
       Enes100.println(yPos);
       Enes100.print("Current angle is: ");
       Enes100.println(angle);
       delay(1000);
    }
    */

/*
    //START OF ACTUAL MISSION
    
    //This portion of code determines starting side and gets us to the mission site.
    startingPosition = getStartingSide();
    if (startingPosition) {
      turn(-PI/2,LEFT); //Current direction of turning is arbitrary, create method of determining later.
    } else {
      turn(PI/2,RIGHT);
    }
    driveForwards(.9);
    while (atMissionSite != false){
      driveForwards(.05);
      delay(250);
    }

    //This portion of code drops the arm and collects the data
    
    raiseArm(10); //idk what angle to put here
    double signal;
    boolean magnetic;
    while (getSignal() < .3){
      signal = getSignal();
      magnetic = getMagnetism();
      wiggle();
    }
    Enes100.print("The signal is: ");
    Enes100.println(signal);
    if (magnetic){
      Enes100.print("The puck was magnetic");
    } else {
      Enes100.print("The puck was not magnetic");
    }
    raiseArm(0);
  
    //This portion of code sets up the vehicle to start checking each lane.
    
    driveReverse(1);
    if (startingPosition) {
      turn(0,LEFT);
    } else {
      turn(0,RIGHT);
    }

    //This portion of code checks each lane and gets us to the ending area. (CONDENSE LATER)
    
    if (getObstacleDistance() > 2){ //Checks 1st lane
      driveForwards(2.8);
    } else {
      if (startingPosition) { //Top is true
       turn(-PI/2,RIGHT);
        driveForwards(.5);
        turn(0,LEFT);
     } else {
        turn(PI/2,LEFT);
        driveForwards(.5);
        turn(0,RIGHT);
     }
      if (getObstacleDistance() > 2){ //Checks 2nd lane
        driveForwards(2.8);
      } else {
        if (startingPosition) { //Top is true
          turn(-PI/2,RIGHT);
          driveForwards(.5);
          turn(0,LEFT);
       } else {
          turn(PI/2,LEFT);
          driveForwards(.5);
          turn(0,RIGHT);
        }
        driveForwards(2.8); //If we're at the 3rd lane, we assume that it's the clear one
      }
    }

    //This portion of code gets us facing the log and drives over it.
    
    resetLocation();
    if (yPos > .9) {
      turn(-PI/2,RIGHT);
      driveForwards(.6);
      turn(0,LEFT);
    }
    driveForwards(.7);

    //We should be over the finish line now
    */
}


boolean resetLocation() {
    if (Enes100.updateLocation()) {
      xPos = Enes100.location.x;
      yPos = Enes100.location.y;
      angle = Enes100.location.theta;
      return true;    
    }
    return false;
}

void driveForwards(double distance) {
  resetLocation();
  double initialXPos = xPos;
  double initialYPos = yPos;
  while (sqrt(sq(xPos - initialXPos) + sq(yPos - initialYPos)) < distance) {
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
    resetLocation();
  }
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);

  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

void driveReverse(double distance) {
  resetLocation();
  double initialXPos = xPos;
  double initialYPos = yPos;
  
  while (sqrt(sq(xPos - initialXPos) + sq(yPos - initialYPos)) < distance) {

    digitalWrite(LEFT_MOTOR_PIN1, LOW);
    digitalWrite(LEFT_MOTOR_PIN2, HIGH);

    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
    resetLocation();
  }
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);

  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

//Left is true, right is false
void turn(double turnAngle, boolean turningLeft) {
  //(angle < PI) ? angle : angle - (2PI)
  resetLocation();
  Enes100.print("Our angle is: ");
  Enes100.println(angle);
  Enes100.print("Our desired angle is: ");
  Enes100.println(turnAngle);
  Enes100.print("x-val: ");
  Enes100.println(xPos);
  Enes100.print("y-val: ");
  Enes100.println(yPos);
  if(turnAngle > 0){
    while (!(angle < turnAngle - .02) && !(angle > turnAngle + .02)) { //Current margin of error is arbitrary, adjust later
      if (turningLeft) {
        //Right wheels drive forward, left wheels drive backwards
        digitalWrite(LEFT_MOTOR_PIN1, LOW);
        digitalWrite(LEFT_MOTOR_PIN2, HIGH);

        digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
        digitalWrite(RIGHT_MOTOR_PIN2, LOW);
      } else {
        //Left wheels drive forward, right wheels drive backwards
        digitalWrite(LEFT_MOTOR_PIN1, HIGH);
        digitalWrite(LEFT_MOTOR_PIN2, LOW);

        digitalWrite(RIGHT_MOTOR_PIN1, LOW);
        digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
      }
      resetLocation();
    }
  } else {
    while (!(angle > turnAngle - .02) && !(angle < turnAngle + .02)) { //Current margin of error is arbitrary, adjust later
      if (turningLeft) {
        //Right wheels drive forward, left wheels drive backwards
        digitalWrite(LEFT_MOTOR_PIN1, LOW);
        digitalWrite(LEFT_MOTOR_PIN2, HIGH);

        digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
        digitalWrite(RIGHT_MOTOR_PIN2, LOW);
      } else {
        //Left wheels drive forward, right wheels drive backwards
        digitalWrite(LEFT_MOTOR_PIN1, HIGH);
        digitalWrite(LEFT_MOTOR_PIN2, LOW);

        digitalWrite(RIGHT_MOTOR_PIN1, LOW);
        digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
      }
      resetLocation();
    }
  }
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);

  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

void raiseArm(double armAngle) {  //We might want to condense these 2 into one function by adding a boolean condition for dropping or raising
  int val = 10;
  for (int i = 0; i < val; i++) {
      myServo.write(armAngle/val);
      delay(5000/val);  
  }
}

double getObstacleDistance() {
  digitalWrite(ULTRA_SONIC_PWM, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRA_SONIC_PWM, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_SONIC_PWM, LOW);
  duration = pulseIn(ULTRA_SONIC_PIN2, HIGH);
  ultraDistance = duration * 0.034 / 2;
  ultraDistance = ultraDistance / 100;
  return ultraDistance;
  
}

//Top is true, bottom is false
boolean getStartingSide() {
  resetLocation();
  return (yPos > 1);
}

//Top is true, bottom is false
boolean atMissionSite() {
  resetLocation();
  if (startingPosition) {
    if (yPos > .5 && yPos < .7) { //Change values after testing aruco marker placement
      return true;
    }
  } else {
    if (yPos > 1.3 && yPos < 1.5) { //Change values after testing aruco marker placement
      return true;
    }
  }
  return false;
}

double getSignal() {
  double signalValue = 0;
  for(int i = 0; i < 1000; i++){
    if(signalValue < (((double) analogRead(A0)) / 1023)) {
      signalValue = (((double) analogRead(A0)) / 1023) / 2; //gives circuit value from 0-1
    }
    delay(1);
  }
  return signalValue;
}

boolean getMagnetism() {
  int proximity = digitalRead(MAGNET_PIN);
  if (proximity == LOW){ // If the pin reads low, the switch is closed.
    return true;
  } else {
    return false;
  }
  //return (digitalRead(MAGNET_PIN) == HIGH);
}

// Might need a lot of thinking, probably just drive backwards tiny amount
void wiggle() {
   driveReverse(.025); 
   delay(250); //Wait 1/4 of a second
}
