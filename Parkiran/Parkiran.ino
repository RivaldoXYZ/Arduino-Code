#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo servoMasuk;
Servo servoKeluar;

// Deklarasi Pin 
const int TrigMasuk = 13;
const int EchoMasuk = 12;
const int TrigKeluar = 11;
const int EchoKeluar = 10;

const int MAX_PARKING = 4;

float dMasuk, jMasuk, dKeluar, jKeluar;
int count = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  servoMasuk.attach(8);
  servoKeluar.attach(9);
  pinMode(TrigMasuk, OUTPUT);
  pinMode(EchoMasuk, INPUT);
  pinMode(TrigKeluar, OUTPUT);
  pinMode(EchoKeluar, INPUT);
  servoMasuk.write(0);
  servoKeluar.write(0);
  lcd.begin();
  lcd.print("Jumlah dalam Parkiran: 0/4");
}

void loop() {
  // Mengukur jarak masuk
  digitalWrite(TrigMasuk, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigMasuk, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigMasuk, LOW);
  
  jMasuk = pulseIn(EchoMasuk, HIGH);
  dMasuk = jMasuk * 0.034 / 2; 

  // Logika untuk Membuka pintu masuk
  if (dMasuk < 10 && count < MAX_PARKING) {
    servoMasuk.write(90); 
    delay(2000);
    servoMasuk.write(0); 
    count++;
    updateLcd();
  }

  // Mengukur jarak keluar
  digitalWrite(TrigKeluar, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigKeluar, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigKeluar, LOW);
  
  jKeluar = pulseIn(EchoKeluar, HIGH);
  dKeluar = jKeluar * 0.034 / 2; // Menghitung jarak dalam cm

  // Logika untuk membuka pintu keluar
  if (dKeluar < 10 && count > 0) {
    servoKeluar.write(90); // Buka pintu keluar
    delay(2000);
    servoKeluar.write(0); // Tutup pintu keluar
    count--;
    updateLcd();
  }

  delay(500); 
}

void updateLcd() {
  lcd.clear();
  lcd.print("Total dalam Parkiran: ");
  lcd.print(count);
  lcd.print("Dari Slot Maksimal : 4");
}
