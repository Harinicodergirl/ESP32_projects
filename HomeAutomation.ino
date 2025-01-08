#define BLYNK_TEMPLATE_ID "TMPL3LvITe_IZ"
#define BLYNK_TEMPLATE_NAME "Home automation"
#define BLYNK_AUTH_TOKEN "kVt8EgL4ZH7Lad4qXEntdrmizXWQwMQb"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <ESP32Servo.h>

// Pin Definitions
#define TRIG_PIN 5
#define ECHO_PIN 18
#define DHTPIN 19
#define DHTTYPE DHT11

// Blynk Virtual Pins
#define VIRTUAL_TEMP_PIN V0
#define VIRTUAL_DIST_PIN V1



// WiFi Credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "TANSAM";
char pass[] = "H!nd#$/19@24:24";

// Global Variables
DHT dht(DHTPIN, DHTTYPE);

Servo myservo;

BLYNK_WRITE(V2) {  // Virtual Pin 1 (Slider)
  int angle = param.asInt();  // Get the value from the slider
  myservo.write(angle);  // Set the servo angle
}

void setup() {
  // Serial Monitor setup
  Serial.begin(9600);

  // Initialize WiFi
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);

  // Initialize Sensors
  dht.begin();
  myservo.attach(21);

  // Configure GPIO Pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("Setup Complete!");
}

void loop() {
  // Run Blynk
  Blynk.run();

  // Read Temperature from DHT11
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.println(temp);
    Blynk.virtualWrite(V0, temp);
  }

  // Measure Distance using HC-SR04
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  float duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance <= 0 || distance > 400) {
    Serial.println("Invalid distance reading!");
  } else {
    Serial.print("Distance: ");
    Serial.println(distance);
    Blynk.virtualWrite(V1, distance);
    
  }

  // Add delay to prevent spamming
  delay(2000); // 2 seconds
}
