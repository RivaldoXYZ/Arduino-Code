#include <Servo.h>

Servo myservo;  // Membuat objek servo untuk mengendalikan motor servo

void setup() {
  myservo.attach(9);  // Menghubungkan pin 9 ke objek servo
}

void loop() {
  // Putar motor servo ke posisi 0 derajat
  myservo.write(0);
  delay(1000);  // Tunggu 1 detik
  
  // Putar motor servo ke posisi 90 derajat
  myservo.write(90);
  delay(1000);  // Tunggu 1 detik
  
  // Putar motor servo ke posisi 180 derajat
  myservo.write(360);
  delay(1000);  // Tunggu 1 detik
}
