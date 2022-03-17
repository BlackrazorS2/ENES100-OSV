#include "Enes100.h"

void setup() {
    // Initialize Enes100 Library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin

    int MARKER_ID = 3;
    int TX_PIN = 2;
    int RX_PIN = 4;
    int location = new int[3];

    
    Enes100.begin("DATA TEAM", DATA, MARKER_ID, TX_PIN, RX_PIN);

    Enes100.print("Destination is at (");
    Enes100.print(Enes100.destination.x);
    Enes100.print(", ");
    Enes100.print(Enes100.destination.y);
    Enes100.println(")");
    
    // Transmit the message from the arduino
    Enes100.mission('M');
    // Any other setup code...
    //comment
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
    location[0] = Enes100.destination.x;
    Enes100.print(Enes100.location.y);
    Enes100.print(", ");
    location[1] = Enes100.destination.y;
    Enes100.print(Enes100.location.theta);
    Enes100.println(")");
    location[2] = Enes100.destination.theta;
}

void driveForwards() {
  
}
void turn(int angle, boolean turningLeft) {
  
}
