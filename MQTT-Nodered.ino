#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "TANSAM";
const char* password = "H!nd#$/19@24:24";

// MQTT Broker settings
const char* mqtt_server = "broker.hivemq.com";  // Replace with your MQTT broker IP or hostname
const int mqtt_port = 1883;
const char* mqtt_user = "";  // Optional: MQTT username
const char* mqtt_pass = "";  // Optional: MQTT password

// DHT Sensor settings
#define DHTPIN 4          // Pin connected to the DHT sensor data pin
#define DHTTYPE DHT11     // Change to DHT11 if you're using that sensor
DHT dht(DHTPIN, DHTTYPE);

// MQTT Topics
const char* publish_topic = "esp32/temperature";

// WiFi and MQTT client
WiFiClient espClient;
PubSubClient client(espClient);

// Function to connect to WiFi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

// Connect to MQTT Broker
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  // Start Serial Monitor
  Serial.begin(115200);

  // Connect to Wi-Fi
  setup_wifi();

  // Set MQTT server and callback function
  client.setServer(mqtt_server, mqtt_port);

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Reconnect to MQTT broker if disconnected
  if (!client.connected()) {
    reconnect();
  }

  // Handle MQTT communication
  client.loop();

  // Read temperature and humidity
  float temp = dht.readTemperature();  // Celsius temperature
  if (isnan(temp)) {
    Serial.println("Failed to read temperature from DHT sensor");
    return;
  }

  // Print temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°C");

  // Publish temperature to MQTT
  String tempStr = String(temp);
  client.publish(publish_topic, tempStr.c_str());

  // Wait for 10 seconds before reading the temperature again
  delay(10000);
}
