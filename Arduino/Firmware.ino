// Include Libraries
#include "Arduino.h"
#include "pulse-sensor-arduino.h"
#include "SoftwareSerial.h"


// Pin Definitions
#define HEARTPULSE_PIN_SIG  A3

// object initialization
PulseSensor heartpulse;
SoftwareSerial serial(10, 11); // Initializing RX, TX pins

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() {
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    serial.begin(115200);
    while (!Serial || !serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    heartpulse.begin(HEARTPULSE_PIN_SIG);
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() {
    int heartpulseBPM = heartpulse.BPM;
    Serial.println(heartpulseBPM);

    if (serial.available()) {
    Serial.write(serial.read());
    }

    if (Serial.available()) {
        serial.write(Serial.read());
    }

    if (heartpulse.QS == true) {
        heartpulse.QS = false;
    }  
}
