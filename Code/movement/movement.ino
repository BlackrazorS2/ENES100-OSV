#include "Enes100.h"

// Links
// https://github.com/BlackrazorS2/ENES100-OSV
// http://enes100.umd.edu/libraries/enes100

    int TX_PIN = 2;
    int RX_PIN = 4;
    int SERVO_PIN = 6;

    int MARKER_ID = 3;
    double xPos, yPos, angle;

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

    if (getStartingSide()) {
      
    }
    
    

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
  while (angle != newAngle) { //Change from != as they're doubles
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

//Left is true, right is false
boolean getStartingSide() {
  resetLocation();
  if (yPos > 1) { //ASSUMING 0,0 is bottom left of arena
    return true;
  } else {
    return false;
  }
}

boolean atMissionSite() {
  
}

double getSignal() {
  
}

double getMagnetism() {
  
}

// Might need a lot of thinking, probably just drive backwards tiny amount
void wiggle() {
  
}
