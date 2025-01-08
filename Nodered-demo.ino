#include <DHT.h>

// Define DHT sensor pin and type
#define DHTPIN 14        // Pin connected to DHT11 data pin
#define DHTTYPE DHT11   // Define the type of DHT sensor

DHT dht(DHTPIN, DHTTYPE); // Create a DHT object

void setup() {
  dht.begin();            // Initialize the DHT sensor
  Serial.begin(9600);     // Start the Serial Monitor at 9600 baud rate
}

void loop() {
  float H = dht.readHumidity();    // Read humidity value
  float T = dht.readTemperature(); // Read temperature value

  // Check if any reading failed
  if (isnan(H) || isnan(T)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Combine the data into a CSV format
  String dhtData = String(H) + "," + String(T);
  Serial.println(dhtData); // Print the data to the Serial Monitor

  delay(2000); // Wait 2 seconds before reading again
}


