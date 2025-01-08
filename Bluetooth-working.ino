#include "BluetoothSerial.h"

// Create a BluetoothSerial object
BluetoothSerial SerialBT;

void setup() {
  // Initialize serial communication with the laptop (USB connection)
  Serial.begin(115200);
  Serial.println("Starting Bluetooth Serial Bridge...");

  // Initialize Bluetooth Serial with a device name
  if (!SerialBT.begin("ESP32_BT_Bridge")) { // Set your Bluetooth device name
    Serial.println("An error occurred initializing Bluetooth");
  } else {
    Serial.println("Bluetooth initialized. Device is ready to pair.");
  }
}

void loop() {
  // Bridge: Laptop Serial -> Bluetooth Serial
  if (Serial.available()) {
    String msgFromLaptop = Serial.readString(); // Read data from laptop
    SerialBT.print("From Laptop: ");
    SerialBT.println(msgFromLaptop);           // Send to Bluetooth device
    Serial.print("Sent to Bluetooth: ");
    Serial.println(msgFromLaptop);             // Debug in Serial Monitor
  }

  // Bridge: Bluetooth Serial -> Laptop Serial
  if (SerialBT.available()) {
    String msgFromBluetooth = SerialBT.readString(); // Read data from Bluetooth
    Serial.print("Received from Bluetooth: ");
    Serial.println(msgFromBluetooth);               // Print on Serial Monitor
    Serial.print("Sending to Laptop: ");
    Serial.println(msgFromBluetooth);               // Debug
  }
}
