# ESP32_projects
ESP32 Projects Repository
This repository contains a collection of ESP32-based projects demonstrating various applications such as IoT, Bluetooth communication, and integration with platforms like Node-RED and Blynk IoT. Each project is documented with code, setup instructions, and features.

Table of Contents
Simple Home Automation
Bluetooth Connection
Node-RED and ESP32
1. Simple Home Automation
Description
This project uses the ESP32 to implement basic home automation features:

Servo Motor: Acts as a door, controlled based on ultrasonic sensor values.
DHT11 Sensor: Monitors temperature and humidity, displaying the data in Blynk IoT.
Blynk IoT Control: Allows remote control of a servo motor based on sensor data.
Features
Real-time temperature and humidity monitoring.
Door automation based on distance values from an ultrasonic sensor.
Remote servo motor control via Blynk IoT.
Hardware Requirements
ESP32 Dev Board
Ultrasonic Sensor (e.g., HC-SR04)
Servo Motor (e.g., SG90)
DHT11 Sensor
Jumper wires, breadboard, and power supply
Setup Instructions
Install the Blynk IoT app and set up a project. Get the authentication token.
Connect the components as per the circuit diagram provided in the project folder.
Update the Wi-Fi credentials and Blynk token in the code.
Upload the code to the ESP32.
2. Bluetooth Connection Between Laptop and Mobile
Description
This project demonstrates how to establish a Bluetooth communication bridge between a laptop and a mobile device using the ESP32. It allows data exchange over Bluetooth.

Features
Bidirectional data transfer between devices.
ESP32 acts as a Bluetooth bridge.
Hardware Requirements
ESP32 Dev Board
Laptop with Bluetooth capability
Mobile device with a Bluetooth terminal app
Setup Instructions
Install a Bluetooth terminal app on your mobile device.
Pair your ESP32 with both the laptop and the mobile device.
Load the code into the ESP32 to handle Bluetooth communication.
Test data exchange between devices.
3. Node-RED and ESP32 Integration
Description
This project integrates ESP32 with Node-RED to create a dashboard and handle serial communication. It demonstrates how to visualize and interact with sensor data in real-time.

Features
ESP32 sends data to Node-RED over serial communication.
A Node-RED dashboard displays sensor readings and controls.
Hardware Requirements
ESP32 Dev Board
PC with Node-RED installed
Required Node-RED libraries:
serial
dashboard
Setup Instructions
Install Node-RED on your PC. Follow the Node-RED installation guide.
Install the required Node-RED libraries (serial, dashboard).
Connect the ESP32 to your PC via USB.
Deploy the Node-RED flow provided in the project folder.
Upload the ESP32 code and start interacting with the dashboard.
