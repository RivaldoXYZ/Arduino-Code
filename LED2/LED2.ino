// Mendefinisikan pin LED
const int ledPins[] = {2, 3, 4, 5};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // Mengatur semua pin sebagai output
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Menghidupkan semua LED secara berurutan
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(500); // Delay setengah detik
  }

  // Mematikan semua LED secara berurutan
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(500); // Delay setengah detik
  }
}
