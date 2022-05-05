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
    delay(500);
    Enes100.begin("Frostbytes", DATA, MARKER_ID, TX_PIN, RX_PIN);
    delay(500);

    //Inputs

    pinMode(MAGNET_PIN, INPUT);
    pinMode(SIGNAL_PIN, OUTPUT);
    pinMode(ULTRA_SONIC_PIN2, INPUT);

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
  
  delay(1000);
  for(int i = 0; i < 100; i++){
    resetLocation();
    Enes100.updateLocation();
    Enes100.println(xPos);
  }
  
    resetLocation();
    for(int untilStart = 5; untilStart > 0; untilStart--){
      Enes100.print("Starting in ");
      Enes100.print(untilStart);
      Enes100.println(" seconds");
      delay(1000);
    }
    resetLocation();
    Enes100.println("Starting!");
    Enes100.updateLocation();
    Enes100.println("Location found");
    Enes100.print("x Position is: ");
    Enes100.println(xPos);
    Enes100.print("y Position is: ");
    Enes100.println(yPos);
    Enes100.print("Current angle is: ");
    Enes100.println(angle);
    delay(3000);
    resetLocation();
    Enes100.println("Starting!");
    Enes100.updateLocation();
    Enes100.println("Location found");  //DELETE LATER 
    Enes100.print("x Position is: ");
    Enes100.println(xPos);
    Enes100.print("y Position is: ");
    Enes100.println(yPos);
    Enes100.print("Current angle is: ");
    Enes100.println(angle);
    // Update the OSV's current location
    
    //START OF TESTING CODE

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

       Enes100.println("Driving forwards");
       driveForwards(1);
       Enes100.println("Turning left");
       turn(0, LEFT);
       Enes100.println("Turning right");
       turn(PI/2, RIGHT);
       Enes100.println("Driving backwards");
       driveReverse(1);
    }
    */

    //SIGNAL TEST (ADD TO FUNCTION LATER)

    /*
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
    */

    
    //MAGNET TEST
    /*
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
    Serial.println("Starting in 5 seconds");
    delay(5000);
    myServo.write(39);
    Serial.println("Arm Dropped");
    double signal;
    boolean magnetic;
    do {
      signal = getSignal();
      magnetic = getMagnetism();
      //wiggle();
    } while(signal <= 0);
    //potentially remove later
    signal = signal * 2.5;
    
    Enes100.print("The signal is: ");
    Enes100.println(signal);
    Serial.print("The signal is: ");
    Serial.println(signal);
    if (magnetic){
      Enes100.print("The puck was magnetic");
      Serial.print("The puck was magnetic");
    } else {
      Enes100.print("The puck was not magnetic");
      Serial.print("The puck was not magnetic");
    }
    delay(1000);
    myServo.write(120);
    Serial.println("");
    Serial.println("done");
    */

    //ARM TEST 2 ELECTRIC BOOGALOO
    /*
    myServo.attach(SERVO_PIN);
    delay(5000);
    myServo.write(32);
    Serial.println("Arm Dropped");
    double signal = -1;
    boolean magnetic = false;


// -----    
// THIS BLOCK WAS MODIFIED TO ENSURE THAT A GUESS IS MADE IN NO READ

    int time = millis();
    do {
      signal = getSignal();
      magnetic = (magnetic) ? true : getMagnetism();
      wiggle();
      //DELETE THIS OR RIGHT STATEMENT CRAP IF BAD
    } while((signal <= 0) && ((millis() - time) < 20000));

    // DELETE IF BREAKS
    if (signal <= 0) {
      signal = 5; 
    }

// -----
    
    Enes100.print("The signal is: ");
    Enes100.println(signal);
    Serial.print("The signal is: ");
    Serial.println(signal);
    Enes100.mission(CYCLE, signal*10);
    if (magnetic){
      Enes100.print("The puck was magnetic");
      Serial.print("The puck was magnetic");
      Enes100.mission(MAGNETISM, MAGNETIC);
      
    } else {
      Enes100.print("The puck was not magnetic");
      Serial.print("The puck was not magnetic");
      Enes100.mission(MAGNETISM, NOT_MAGNETIC);
    }
    delay(1000);
    myServo.write(120);
    delay(3000);
    myServo.detach();
    */
    
    //ULTRA SONIC TEST
    /*
    
    Enes100.println("Ultra sonic sensor distance");
    Enes100.println(getObstacleDistance());
    Serial.println("Ultra sonic sensor distance");
    Serial.println(getObstacleDistance());
    delay(500);
    */

    //ULTRA SONIC WITH MOTORS TEST
    /*
    
    delay(5000);
    digitalWrite(LEFT_MOTOR_PIN1, HIGH);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
    delay(2000);
    Enes100.println("Ultra sonic sensor distance");
    Enes100.println(getObstacleDistance());
    delay(500);
    Serial.println("Ultra sonic sensor distance");
    Serial.println(getObstacleDistance());
    delay(5000);
    digitalWrite(LEFT_MOTOR_PIN1, LOW);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
    while(true){

    }
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


    //START OF ACTUAL MISSION
    
    //This portion of code determines starting side and gets us to the mission site.
    myServo.attach(SERVO_PIN);
    myServo.detach();
    startingPosition = getStartingSide();
    if (startingPosition) {
      turn(-PI/2,LEFT); //Current direction of turning is arbitrary, create method of determining later.
    } else {
      turn(PI/2,RIGHT);  //RIGHT
    }
    delay(1000);
    driveForwards(.7);
    
    while (atMissionSite() == false){
      driveForwards(.05);
      Enes100.println("yPos:");
      Enes100.println(yPos);
      delay(250);
    }
    
    //This portion of code drops the arm and collects the data
    
    myServo.attach(SERVO_PIN);
    delay(5000);
    myServo.write(80);
    myServo.write(35);
    Serial.println("Arm Dropped");
    Enes100.println("Arm Dropped");
    double signal = -1;
    boolean magnetic = false;


// -----    
// THIS BLOCK WAS MODIFIED TO ENSURE THAT A GUESS IS MADE IN NO READ

    do {
      signal = getSignal();
      magnetic = (magnetic) ? true : getMagnetism();
      wiggle();
      //DELETE THIS OR RIGHT STATEMENT CRAP IF BAD
      Enes100.println("WHILE RAN");
    } while((signal <= 0) && yPos > 1.1);

    // DELETE IF IT DOESNT WORK
    if (signal < -.5) {
      signal = 5; 
    }

// -----
    
    Enes100.print("The signal is: ");
    Enes100.println(signal);
    Serial.print("The signal is: ");
    Serial.println(signal);
    //Enes100.mission(CYCLE, signal*10);
    if (magnetic){
      Enes100.print("The puck was magnetic");
      Serial.print("The puck was magnetic");
      //Enes100.mission(MAGNETISM, MAGNETIC);
      
    } else {
      Enes100.print("The puck was not magnetic");
      Serial.print("The puck was not magnetic");
      //Enes100.mission(MAGNETISM, NOT_MAGNETIC);
    }
    delay(1000);
    myServo.write(120);
    delay(3000);
    myServo.detach();
    

    
  
    //This portion of code sets up the vehicle to start checking each lane.
    delay(3000);
    driveReverse(.9);
    delay(5000);

    //ALL .5 is checking ultrasonic distance
    //ALL .9 is distance to drive forward is lane is clear
    //ALL .6 is distance to drive (in y-dir) to get to new lane (.4 is also this)

    double CHECKING_ULTRASONIC_DISTANCE = 1.5;
    double DRIVE_FORWARD_IS_LANE_CLEAR = 1.5;
    double DISTANCE_TO_DRIVE_NEW_LANE = .65;

    
    if (startingPosition) {
      turn(0,LEFT);
    } else {
      turn(0,RIGHT); //RIGHT
    }
    driveForwards(.8); //This sets us up right next to the first obstacle, dont change
    //This portion of code checks each lane and gets us to the ending area. (CONDENSE LATER)
    
    //checking first row
    if (getObstacleDistance() > CHECKING_ULTRASONIC_DISTANCE){ //Checks 1st lane     THIS distance is arbitrary and should be changed if swapping to only 1 check
      driveForwards(DRIVE_FORWARD_IS_LANE_CLEAR);  //ARBITRARY DISTANCE TO DRIVE FORWARD, INCREASE IF CHANGING TO CHECK ONE LANE
    } else {
      if (startingPosition) { //Top is true
       turn(-PI/2,RIGHT); //RIGHT
        driveForwards(DISTANCE_TO_DRIVE_NEW_LANE);  //This distance puts us in the next lane
        turn(0,LEFT);
     } else {
        turn(PI/2,LEFT);
        driveForwards(DISTANCE_TO_DRIVE_NEW_LANE);
        turn(0,RIGHT); //RIGHT
     }
      if (getObstacleDistance() > CHECKING_ULTRASONIC_DISTANCE){ //Checks 2nd lane
        driveForwards(DRIVE_FORWARD_IS_LANE_CLEAR);
      } else {
        if (startingPosition) { //Top is true
          turn(-PI/2,RIGHT); //RIGHT
          driveForwards(DISTANCE_TO_DRIVE_NEW_LANE);
          turn(0,LEFT);
       } else {
          turn(PI/2,LEFT);
          driveForwards(DISTANCE_TO_DRIVE_NEW_LANE);
          turn(0,RIGHT); //RIGHT
        }
        driveForwards(DRIVE_FORWARD_IS_LANE_CLEAR); //If we're at the 3rd lane, we assume that it's the clear one
      }
    }
    //checking second row
    /*
    if (getObstacleDistance() > CHECKING_ULTRASONIC_DISTANCE){ //Checks 1st lane
      driveForwards(DRIVE_FORWARD_IS_LANE_CLEAR);
    } else {
      if (startingPosition) { //Top is true
       turn(PI/2,LEFT);
        driveForwards(1-DISTANCE_TO_DRIVE_NEW_LANE);
        turn(0,RIGHT); //RIGHT
     } else {
        turn(-PI/2,RIGHT); //RIGHT
        driveForwards(1-DISTANCE_TO_DRIVE_NEW_LANE);
        turn(0,LEFT);
     }
      if (getObstacleDistance() > CHECKING_ULTRASONIC_DISTANCE){ //Checks 2nd lane
        driveForwards(DRIVE_FORWARD_IS_LANE_CLEAR);
      } else {
        if (startingPosition) { //Top is true
          turn(PI/2,LEFT);
          driveForwards(1-DISTANCE_TO_DRIVE_NEW_LANE);
          turn(0,RIGHT); //RIGHT
       } else {
          turn(-PI/2,RIGHT); //RIGHT
          driveForwards(1-DISTANCE_TO_DRIVE_NEW_LANE);
          turn(0,LEFT);
        }
        driveForwards(DRIVE_FORWARD_IS_LANE_CLEAR); //If we're at the 3rd lane, we assume that it's the clear one
      }
    }
    */
    
    //This portion of code gets us facing the log and drives over it.
    
    resetLocation();
    if (yPos < 1.1) {
      turn(PI/2,LEFT);
      driveForwards(.6);
      turn(0,RIGHT); //RIGHT
    }
    /*
    myServo.attach(SERVO_PIN);
    delay(3000);
    myServo.write(25);
    */
    driveForwards(.7);
    
    //We should be over the finish line now
}


boolean resetLocation() {
    while(!Enes100.updateLocation() || xPos <= 0 || yPos <= 0) {
      xPos = Enes100.location.x;
      yPos = Enes100.location.y;
      angle = Enes100.location.theta;  
    }
    xPos = Enes100.location.x;
    yPos = Enes100.location.y;
    angle = Enes100.location.theta;
    return true;
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
    while(!resetLocation()){
      resetLocation();
    }
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
    while(!resetLocation()){
      resetLocation();
    }
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
  if(turningLeft){
    while ((angle < (turnAngle - .01)) || (angle > (turnAngle + .01))) {
        digitalWrite(LEFT_MOTOR_PIN1, LOW);
        digitalWrite(LEFT_MOTOR_PIN2, HIGH);

        digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
        digitalWrite(RIGHT_MOTOR_PIN2, LOW);

        delay(10);

        digitalWrite(LEFT_MOTOR_PIN1, LOW);
        digitalWrite(LEFT_MOTOR_PIN2, LOW);

        digitalWrite(RIGHT_MOTOR_PIN1, LOW);
        digitalWrite(RIGHT_MOTOR_PIN2, LOW);
        resetLocation();
    }
  } else {
    while ((angle < (turnAngle - .01)) || (angle > (turnAngle + .01))) {
        digitalWrite(LEFT_MOTOR_PIN1, HIGH);
        digitalWrite(LEFT_MOTOR_PIN2, LOW);

        digitalWrite(RIGHT_MOTOR_PIN1, LOW);
        digitalWrite(RIGHT_MOTOR_PIN2, HIGH);

        delay(10);

        digitalWrite(LEFT_MOTOR_PIN1, LOW);
        digitalWrite(LEFT_MOTOR_PIN2, LOW);

        digitalWrite(RIGHT_MOTOR_PIN1, LOW);
        digitalWrite(RIGHT_MOTOR_PIN2, LOW);
        resetLocation();
    }
  }
  Enes100.println("Stop turning");
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);

  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
  //break;
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
  Enes100.println("Ultra Sonic Distance:");
  Enes100.println(ultraDistance);
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
    if (yPos > .6 && yPos < .85) { //Change values after testing aruco marker placement
      // FORMERLY yPos > .6 && yPos < .85
      return true;
    }
  } else {
    if (yPos > 1.15 && yPos < 1.4) { //Change values after testing aruco marker placement
      // FORMERLY yPos > 1.15 && yPos < 1.4
      return true;
    }
  }
  return false;
}

int getSignal() {
  /*
  double signalValue = 0;
  for(int i = 0; i < 1000; i++){
    if(signalValue < (((double) analogRead(A0)) / 1023)) {
      signalValue = (((double) analogRead(A0)) / 1023) / 2; //gives circuit value from 0-1
    }
    delay(1);
  }
  return signalValue;
  */

  pwm_value = pulseIn(SIGNAL_PIN, HIGH);

    num = round(pwm_value / 1000.0);
    Serial.println("Duty Cycle: ");
    Serial.println((int) num);
    delay(1000);
    return((int) num);
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
   digitalWrite(LEFT_MOTOR_PIN1, LOW);
    digitalWrite(LEFT_MOTOR_PIN2, HIGH);

    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
    delay(125); //Wait 1/8 of a second

    digitalWrite(LEFT_MOTOR_PIN1, LOW);
    digitalWrite(LEFT_MOTOR_PIN2, LOW);

    digitalWrite(RIGHT_MOTOR_PIN1, LOW);
    digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}
