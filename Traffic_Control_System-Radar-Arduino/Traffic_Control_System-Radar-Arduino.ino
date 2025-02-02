// Pins for Ultrasonic Sensors
const int trigPins[4] = {2, 4, 6, 8};
const int echoPins[4] = {3, 5, 7, 9};

// Pins for Traffic Lights
const int redPins[4] = {10, 11, 12, 13};
const int yellowPins[4] = {A0, A1, A2, A3};
const int greenPins[4] = {A4, A5, A6, A7};

// Array to store distances
long distances[4];

void setup() {
  Serial.begin(9600);

  // Set pins for Ultrasonic Sensors
  for (int i = 0; i < 4; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
  }

  // Set pins for Traffic Lights
  for (int i = 0; i < 4; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
  }
}

void loop() {
  // Measure distances
  for (int i = 0; i < 4; i++) {
    distances[i] = measureDistance(trigPins[i], echoPins[i]);
  }

  // Find the road with the maximum distance (crowd)
  int maxIndex = findMaxIndex(distances, 4);

  // Control Traffic Lights
  for (int i = 0; i < 4; i++) {
    if (i == maxIndex) {
      greenLight(i);
    } else {
      redLight(i);
    }
  }

  delay(10000); // Keep the green light on for 10 seconds
}

long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

int findMaxIndex(long arr[], int size) {
  int maxIndex = 0;
  for (int i = 1; i < size; i++) {
    if (arr[i] > arr[maxIndex]) {
      maxIndex = i;
    }
  }
  return maxIndex;
}

void greenLight(int road) {
  digitalWrite(greenPins[road], HIGH);
  digitalWrite(yellowPins[road], LOW);
  digitalWrite(redPins[road], LOW);
}

void redLight(int road) {
  digitalWrite(greenPins[road], LOW);
  digitalWrite(yellowPins[road], LOW);
  digitalWrite(redPins[road], HIGH);
}
