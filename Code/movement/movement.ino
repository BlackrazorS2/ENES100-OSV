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
  
}

void driveReverse(double distance) {
  
}

//Left is true, right is false
void turn(double angle, boolean turningLeft) {
  
}

void setDirection(double angle) {
  
}

boolean dropArm(double angle) {
  
}

boolean raiseArm() {
  
}

int getObstacleDistance() {
  
}

//Left is true, right is false
boolean getStartingSide() {
  
}

boolean atMissionSite() {
  
}

double getSignal() {
  
}

double getMagnetism() {
  
}

// Might need a lot of thinking
void wiggle() {
  
}
