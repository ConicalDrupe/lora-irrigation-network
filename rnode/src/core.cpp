#include <Arduino.h>

const int BUTTON_PIN = 0; // cpp style istead of #define

// Shared state for ISR (Interrupt Service Routine)
// Use 'volatile' to prevent compiler from caching value
// Do this for all variables related Interrupts
volatile bool sendPacket = false;

// Interrupt Service Routine
// Use 'IRAM_ATTR' to put into fast on-chip RAM
// Must be short function for reactivity - no logging, no delays, no LoRa calls...
// Real work is done in the loop
void IRAM_ATTR onButtonPress() {
    sendPacket = true;
};

void setup() {
    Serial.begin(115200);

    pinMODE(BUTTON_PIN,INPUT_PULLUP);

    attachInterrup(digitalPinToInterrupt(BUTTON_PIN), onButtonPress, FALLING);

    Serial.println("Ready. Press PRG to send LoRa packet.")
};

void loop() {
    if (sendPacket) {
        sendPacket = false;

        Serial.println("Button pressed. Sending LoRa packet.");
        // code here
    }

    // Other 'non-blocking' tasks...
    // This is where polling would take place + deepsleep initiation
}
