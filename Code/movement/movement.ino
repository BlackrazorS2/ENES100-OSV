#include "Enes100.h"

// Links
// https://github.com/BlackrazorS2/ENES100-OSV
// http://enes100.umd.edu/libraries/enes100

    int TX_PIN = 2;
    int RX_PIN = 4;
    int SERVO_PIN = 6;

    int MARKER_ID = 3;
    double xPos, yPos, angle;
    
    boolean startingPosition; //Top is true, bottom is false

    boolean LEFT = true;
    boolean RIGHT = false;
   
void setup() {
    // Initialize Enes100 Library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    
    Enes100.begin("Frostbytes", DATA, MARKER_ID, TX_PIN, RX_PIN);

}

void loop() {
    // Update the OSV's current location
    if (resetLocation() == false) {
      // emergency reverse
      Enes100.println("BRUH HOW OUT OF AREANNA");
      Enes100.println("WRITE THIS LATER, PROLLY BACKUP OSV");
    }

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
    
    dropArm(PI/2); //idk what angle to put here
    double signal;
    boolean magnetic;
    while (getSignal() < .3){
      signal = getSignal();
      magnetic = getMagnetism();
      wiggle();
    }
    Serial.print("The signal is: ");
    Serial.println(signal);
    if (magnetic){
      Serial.print("The puck was magnetic");
    } else {
      Serial.print("The puck was not magnetic");
    }
    raiseArm();

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
    driveForwards(1);

    //We should be over the finish line now
    
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
  int initialXPos = xPos;
  int initialYPos = yPos;
  while (sqrt(sq(xPos - initialXPos) + sq(yPos - initialYPos)) < distance) {
    //Activate both wheel motors
    resetLocation();
  }
}

void driveReverse(double distance) {
  resetLocation();
  int initialXPos = xPos;
  int initialYPos = yPos;
  while (sqrt(sq(xPos - initialXPos) + sq(yPos - initialYPos)) < distance) {
    //Activate both wheel motors backwards
    resetLocation();
  }
}

//Left is true, right is false
void turn(double newAngle, boolean turningLeft) {
  resetLocation();
  while (angle > newAngle * 1.05 || angle < newAngle * .95) { //Current margin of error is arbitrary, adjust later
    if (turningLeft) {
      //Right wheels drive forward, left wheels drive backwards
    } else {
      //Left wheels drive forward, right wheels drive backwards
    }
    resetLocation();
  }
}

void setDirection(double newAngle) { //Is this really neccessary?
  
}

boolean dropArm(double angle) {
  
}

boolean raiseArm() {
  
}

int getObstacleDistance() {
  
}

//Top is true, bottom is false
boolean getStartingSide() {
  resetLocation();
  if (yPos > 1) { //ASSUMING 0,0 is bottom left of arena
    return true;
  } else {
    return false;
  }
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
  
}

double getMagnetism() {
  
}

// Might need a lot of thinking, probably just drive backwards tiny amount
void wiggle() {
  while(getSignal() < .1) {
    driveReverse(.05); 
    delay(250); //Wait 1/4 of a second
  }
}
