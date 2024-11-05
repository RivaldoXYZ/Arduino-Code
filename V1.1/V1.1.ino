#include <Servo.h>

Servo servoX;
Servo servoY;

int ldr1 = A0; // LDR kiri atas
int ldr2 = A1; // LDR kanan atas
int ldr3 = A2; // LDR kiri bawah
int ldr4 = A3; // LDR kanan bawah

int posX = 90; // Posisi awal sumbu X
int posY = 0;  // Posisi awal sumbu Y (tegak lurus)
int threshold = 10; // Threshold untuk perbedaan cahaya

int directionX = 1; // 1 untuk ke kanan, -1 untuk ke kiri
int directionY = 1; // 1 untuk ke atas, -1 untuk ke bawah

void setup() {
  servoX.attach(8);  // Servo X pada pin 9
  servoY.attach(10); // Servo Y pada pin 10

  servoX.write(posX); // Set posisi awal X
  servoY.write(posY); // Set posisi awal Y

  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
  pinMode(ldr4, INPUT);

  Serial.begin(9600);
}

void loop() {
  int val1 = analogRead(ldr1);
  int val2 = analogRead(ldr2);
  int val3 = analogRead(ldr3);
  int val4 = analogRead(ldr4);

  // Menghitung perbedaan untuk sumbu X dan Y
  int diffX = (val1 + val3) - (val2 + val4);
  int diffY = (val1 + val2) - (val3 + val4);

  Serial.print("Perbedaan X: "); Serial.println(diffX);
  Serial.print("Perbedaan Y: "); Serial.println(diffY);
  Serial.print("Pembacaan Sensor : "); 
  Serial.print(val1);
  Serial.print(", "); 
  Serial.print(val2);
  Serial.print(", "); 
  Serial.print(val3);
  Serial.print(", "); 
  Serial.println(val4);

  

  // Logika pergerakan X
  if (abs(diffX) > threshold) {
    if (diffX > 0) { 
      posX += directionX;
    } else if (diffX < 0) { 
      posX -= directionX;
    }
  }

  // Batasi posisi X agar tidak melebihi batas
  if (posX >= 160) {
    posX = 160;
    directionX = -1; // Balik arah jika mencapai maksimum
  } else if (posX <= 0) {
    posX = 0;
    directionX = 1; // Balik arah jika mencapai minimum
  }

  // Logika pergerakan Y (sudut 0 = tegak, sudut 90 = maju)
  if (abs(diffY) > threshold) {
    if (diffY > 0) { 
      posY += directionY;
    } else if (diffY < 0) { 
      posY -= directionY;
    }
  }

  // Batasi posisi Y agar tidak melebihi batas
  if (posY >= 120) {
    posY = 120;
    directionY = -1; // Balik arah jika mencapai maksimum
  } else if (posY <= 0) {
    posY = 0;
    directionY = 1; // Balik arah jika mencapai minimum
  }

  servoX.write(posX); // Menggerakkan servo X
  Serial.print("Posisi Servo X: "); Serial.println(posX);
  servoY.write(posY); // Menggerakkan servo 
  Serial.print("Posisi Servo Y: "); Serial.println(posY);
  Serial.println(" ");

  delay(1000); // Delay untuk stabilisasi
}