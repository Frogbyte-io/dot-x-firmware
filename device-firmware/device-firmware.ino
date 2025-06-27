#include <ArduinoJson.h>

// Configuration constants
#define DEBOUNCE_VALUE 10
#define NUM_SLIDERS 5
#define SEND_INTERVAL 1000
#define LOOP_DELAY 50
#define JSON_BUFFER_SIZE 128

// Pin definitions for sliders
const int sliderPins[NUM_SLIDERS] = {A0, A1, A2, A3, A4};

// State variables
int lastSliderValues[NUM_SLIDERS];
static unsigned long lastSendTime = 0;

void setup() {
  Serial.begin(115200);
  
  // Initialize last slider values
  for (int i = 0; i < NUM_SLIDERS; i++) {
    lastSliderValues[i] = analogRead(sliderPins[i]);
  }
}

void loop() {
  // Read current slider values
  int currentSliderValues[NUM_SLIDERS];
  bool hasChanged = false;
  
  for (int i = 0; i < NUM_SLIDERS; i++) {
    currentSliderValues[i] = analogRead(sliderPins[i]);
    
    // Check if any slider has changed significantly
    if (abs(currentSliderValues[i] - lastSliderValues[i]) >= DEBOUNCE_VALUE) {
      hasChanged = true;
    }
  }
  
  // Send data if sliders changed or if it's time for periodic update
  unsigned long currentTime = millis();
  bool shouldSendPeriodic = (currentTime - lastSendTime >= SEND_INTERVAL);
  
  if (hasChanged || shouldSendPeriodic) {
    sendSliderData(currentSliderValues);
    
    // Update last values and send time
    if (hasChanged) {
      for (int i = 0; i < NUM_SLIDERS; i++) {
        lastSliderValues[i] = currentSliderValues[i];
      }
    }
    
    if (shouldSendPeriodic) {
      lastSendTime = currentTime;
    }
  }
  
  delay(LOOP_DELAY);
}

void sendSliderData(int sliderValues[]) {
  // Create JSON document
  DynamicJsonDocument jsonDoc(JSON_BUFFER_SIZE);
  
  // Populate JSON with slider values
  for (int i = 0; i < NUM_SLIDERS; i++) {
    String sliderKey = "slider" + String(i + 1);
    jsonDoc[sliderKey] = sliderValues[i];
  }
  
  // Send MessagePack data over Serial
  serializeMsgPack(jsonDoc, Serial);
  Serial.println();
}
