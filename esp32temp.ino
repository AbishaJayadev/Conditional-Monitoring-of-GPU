#include <DHT.h>
// Define GPIO pins
#define DHTPIN 26          // GPIO26 connected to DHT22 DATA pin
#define DHTTYPE DHT22      // DHT 22 (AM2302)
#define RELAY_PIN 13       // GPIO13 connected to Relay IN pin
// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);
// Temperature threshold in Celsius
const float TEMP_THRESHOLD = 10.0;
void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Initialize relay as OFF
}
void loop() {
  // Read temperature as Celsius
  float temperature = dht.readTemperature();
  // Read humidity
  float humidity = dht.readHumidity();
  // Check if any reads failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT22 sensor!");
    return;
  }
  // Print temperature and humidity to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  // Control relay based on temperature threshold
  if (temperature > TEMP_THRESHOLD) {
    digitalWrite(RELAY_PIN, LOW); // Turn ON relay
    Serial.println("Cooling system ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Turn OFF relay
    Serial.println("Cooling system OFF");
  }
  delay(2000); // Wait 2 seconds before next reading
}
