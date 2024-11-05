#include <Servo.h>

//defining Servos
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

Servo servoverti;
int servov = 0;
int servovLimitHigh = 90;
int servovLimitLow = 20;

//Assigning LDRs
int ldr1 = 1; //top right LDR yellow
int ldr2 = 2; //top left LDR green
int ldr3 = 3; // bottom left LDR blue
int ldr4 = 0; // bottom right LDR orange


int maxSensorValue = 0;

void setup ()
{
  Serial.begin(9600); // Initialize serial communication
  servohori.attach(9);
  servohori.write(0);
  servoverti.attach(10);
  servoverti.write(0);
  delay(100);
}

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  
  //capturing analog values of each LDR
  int ReadLDR1 = analogRead(ldr1);
  int ReadLDR2= analogRead(ldr2);
  int ReadLDR3 = analogRead(ldr3);
  int ReadLDR4 = analogRead(ldr4);

  Serial.print("Max value: ");
  Serial.println(maxSensorValue);
  Serial.print("Sensor Values: ");
  Serial.print(ReadLDR1);
  Serial.print(", ");
  Serial.print(ReadLDR2);
  Serial.print(", ");
  Serial.print(ReadLDR3);
  Serial.print(", ");
  Serial.println(ReadLDR4);

 maxSensorValue = max(max(ReadLDR1, ReadLDR2), max(ReadLDR3, ReadLDR4));

  if (ReadLDR1 < maxSensorValue && ReadLDR2 < maxSensorValue) {
    if (servoh < 160)
      servoh += 1;
    servohori.write(servoh);
    Serial.println("servoX +");
    Serial.println(servoh);
  }
  if (ReadLDR3 < maxSensorValue && ReadLDR4 < maxSensorValue) {
    if (servoh > 20)
      servoh -= 1;
    servohori.write(servoh);
    Serial.println("servoX -");
    Serial.println(servoh);
  }

  if (ReadLDR2 < maxSensorValue && ReadLDR3 < maxSensorValue) {
    if (servov < 90)
      servov += 1;
    servoverti.write(servov);
    Serial.print("servoY +");
    Serial.println(servov);
  }
  if (ReadLDR1 < maxSensorValue && ReadLDR4 < maxSensorValue) {
    if (servov > 20)
      servov -= 1;
    servoverti.write(servov);
    Serial.println("servoY -");
    Serial.println(servov);
  }

}