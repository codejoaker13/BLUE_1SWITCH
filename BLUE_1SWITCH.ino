#include "BluetoothSerial.h"  // Include the Bluetooth Serial library

BluetoothSerial SerialBT;  // Create a BluetoothSerial object

const int relayPin = 27;   // Define the GPIO pin connected to the relay

void setup() {
  // Initialize the serial communication
  Serial.begin(115200);
  
  // Start Bluetooth communication
  SerialBT.begin("ESP32_Relay");  // Name the Bluetooth device
  Serial.println("The device started, now you can pair it with Bluetooth!");

  // Set relay pin as output
  pinMode(relayPin, OUTPUT);
  
  // Initially, set the relay to OFF
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Check if any data is received via Bluetooth
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();  // Read the incoming character
    Serial.println(incomingChar);  // Print the received character for debugging
    
    if (incomingChar == '1') {
      // Turn the relay ON
      digitalWrite(relayPin, HIGH);
      Serial.println("Relay is ON");
    }
    else if (incomingChar == '0') {
      // Turn the relay OFF
      digitalWrite(relayPin, LOW);
      Serial.println("Relay is OFF");
    }
  }

  delay(20);  // Small delay to avoid overwhelming the Bluetooth connection
}
