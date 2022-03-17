#include "Enes100.h"

// Links
// https://github.com/BlackrazorS2/ENES100-OSV
// http://enes100.umd.edu/libraries/enes100

    int TX_PIN = 2;
    int RX_PIN = 4;
    int SERVO_PIN = 6;

    int MARKER_ID = 3;
    double xPos, yPos, angle;
   
void setup() {
    // Initialize Enes100 Library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    
    Enes100.begin("Frostbytes", DATA, MARKER_ID, TX_PIN, RX_PIN);

}

void loop() {
    // Update the OSV's current location
    while (!Enes100.updateLocation()) {
        // OSV's location was not found
        Enes100.println("404 Not Found");
    }
    Enes100.print("OSV is at (");
    Enes100.print(Enes100.location.x);
    Enes100.print(", ");
    xPos = Enes100.location.x;
    Enes100.print(Enes100.location.y);
    Enes100.print(", ");
    yPos = Enes100.location.y;
    Enes100.print(Enes100.location.theta);
    Enes100.println(")");
    angle = Enes100.location.theta;
}

void driveForwards() {
  
}
void turn(int angle, boolean turningLeft) {
  
}
