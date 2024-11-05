#include <Servo.h>

// Definisikan pin untuk servo dan potensiometer
const int servoPin = 9;
const int potentiometerPin = A0;

// Buat objek servo
Servo servoMotor;

void setup() {
  // Mulai serial communication
  Serial.begin(9600);

  // Attach servo ke pin yang ditentukan
  servoMotor.attach(servoPin);
}

void loop() {
  // Baca nilai dari potensiometer
  int potValue = analogRead(potentiometerPin);

  // Konversi nilai potensiometer menjadi sudut (0-180)
  int angle = map(potValue, 0, 1023, 0, 180);

  // Putar servo ke sudut yang sesuai
  servoMotor.write(angle);

  // Tampilkan nilai potensiometer dan sudut servo
  Serial.print("Nilai Potensiometer: ");
  Serial.print(potValue);
  Serial.print("\tSudut Servo: ");
  Serial.println(angle);

  // Delay untuk memberikan waktu bacaan yang stabil
  delay(100);
}