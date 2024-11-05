#include <Servo.h>

Servo servoX;
Servo servoY;

int ldr1 = A0; // LDR kiri atas
int ldr2 = A3; // LDR kanan atas
int ldr3 = A2; // LDR kiri bawah
int ldr4 = A3; // LDR kanan bawah

int posX = 80; // Posisi awal sumbu X
int posY = 60;  // Posisi awal sumbu Y (tegak lurus)
int threshold = 50; // Threshold untuk perbedaan cahaya

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
  int val2 = analogRead(ldr2*2);
  int val3 = analogRead(ldr3);
  int val4 = analogRead(ldr4);
  Serial.print(val1);
  Serial.print("   ");
  Serial.print(val2);
  Serial.print("   ");
  Serial.print(val3);
  Serial.print("   ");
  Serial.print(val4);
  Serial.println("   ");

  // Menghitung perbedaan untuk sumbu X dan Y
  int diffX = (val1 + val3) - (val2 + val4);
  int diffY = (val1 + val2) - (val3 + val4);

  // Logika pergerakan X
  if (abs(diffX) > threshold) {
    if (diffX > 0 && posX > 0) { 
      posX++;
    } else if (diffX < 0 && posX < 180) { 
      posX--;
    }
  }

  // Logika pergerakan Y (sudut 0 = tegak, sudut 90 = maju)
  if (abs(diffY) > threshold) {
    if (diffY > 0 && posY < 120) { 
      posY++;
    } else if (diffY < 0 && posY > 0) { 
      posY--;
    }
  }

  servoX.write(posX); // Menggerakkan servo X
  servoY.write(posY); // Menggerakkan servo Y

  delay(500); // Delay untuk stabilisasi
}
