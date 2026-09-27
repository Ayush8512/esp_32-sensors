/*
 * Project: ESP32 IR Obstacle Sensor Interface
 * Author: Ayush
 * Repository: https://github.com/Ayush8512/esp_32-sensors
 * 
 * Circuit Wiring:
 * -----------------------------------------
 * IR Sensor Module      ESP32 DevKit Pin
 * -----------------------------------------
 * VCC                   3.3V (or 5V if 3.3V output is maintained)
 * GND                   GND
 * OUT / DO              GPIO 18
 * -----------------------------------------
 * 
 * Note: Most IR obstacle modules with LM393 comparator are ACTIVE LOW:
 *  - LOW (0)  -> Obstacle Detected (Module LED glows)
 *  - HIGH (1) -> Clear / No Obstacle
 */

// Pin Definitions
const int IR_PIN = 18;          // GPIO 18 connected to IR sensor OUT pin
const int LED_PIN = 2;          // GPIO 2 (Built-in LED on most ESP32 Dev modules)

// Variables for state tracking
int lastSensorState = -1;       // Initialize with invalid state to force first print
unsigned long obstacleCount = 0; // Count total obstacles detected

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  delay(1000); // Small delay for serial to stabilize

  Serial.println("========================================");
  Serial.println("  ESP32 IR Obstacle Sensor Initialized  ");
  Serial.println("========================================");

  // Configure Pins
  pinMode(IR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("System Ready! Place an object in front of the sensor...");
}

void loop() {
  // Read digital state from IR sensor
  int currentSensorState = digitalRead(IR_PIN);

  // Check if state has changed to prevent flooding serial monitor
  if (currentSensorState != lastSensorState) {
    if (currentSensorState == LOW) {
      // LOW means obstacle detected on standard LM393 IR modules
      obstacleCount++;
      digitalWrite(LED_PIN, HIGH); // Turn ON LED
      
      Serial.print("[ALERT] Obstacle Detected! | Total Count: ");
      Serial.println(obstacleCount);
    } else {
      // HIGH means clear path
      digitalWrite(LED_PIN, LOW);  // Turn OFF LED
      
      Serial.println("[INFO] Path Clear.");
    }
    
    // Update previous state
    lastSensorState = currentSensorState;
  }

  // Small debounce delay
  delay(50);
}
