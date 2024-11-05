#include <Servo.h>

#define LDR1 A0
#define LDR2 A1
#define LDR3 A2
#define LDR4 A3

#define SERVO_X_PIN 10
#define SERVO_Y_PIN 11

Servo servoX;
Servo servoY;

void setup() {
  Serial.begin(9600);
  servoX.attach(SERVO_X_PIN);
  servoY.attach(SERVO_Y_PIN);
}

void loop() {
  int ldr1Value = analogRead(LDR1);
  int ldr2Value = analogRead(LDR2);
  int ldr3Value = analogRead(LDR3);
  int ldr4Value = analogRead(LDR4);

  int ldrSum = ldr1Value + ldr2Value + ldr3Value + ldr4Value;
  
  // Menghitung rata-rata nilai dari 4 LDR
  int averageValue = ldrSum / 4;

  // Menghitung perbedaan nilai antara setiap LDR dengan nilai rata-rata
  int ldr1Difference = ldr1Value - averageValue;
  int ldr2Difference = ldr2Value - averageValue;
  int ldr3Difference = ldr3Value - averageValue;
  int ldr4Difference = ldr4Value - averageValue;

  // Menggerakkan servo X untuk menyeimbangkan nilai LDR
  int servoXAngle = map(ldr1Difference - ldr3Difference, -1023, 1023, 0, 180); // Sesuaikan nilai minimum dan maksimum dengan karakteristik servo yang digunakan
  servoX.write(servoXAngle);

  // Menggerakkan servo Y untuk menyeimbangkan nilai LDR
  int servoYAngle = map(ldr2Difference - ldr4Difference, -1023, 1023, 0, 180); // Sesuaikan nilai minimum dan maksimum dengan karakteristik servo yang digunakan
  servoY.write(servoYAngle);

  Serial.print("LDR1: ");
  Serial.print(ldr1Value);
  Serial.print(" LDR2: ");
  Serial.print(ldr2Value);
  Serial.print(" LDR3: ");
  Serial.print(ldr3Value);
  Serial.print(" LDR4: ");
  Serial.print(ldr4Value);
  Serial.print(" Servo X Angle: ");
  Serial.print(servoXAngle);
  Serial.print(" Servo Y Angle: ");
  Serial.println(servoYAngle);

  delay(100);
}
