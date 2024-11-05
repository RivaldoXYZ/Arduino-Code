const int ldrTopLeft = A3;
const int ldrTopRight = A2;
const int ldrBottomLeft = A0;
const int ldrBottomRight = A1;

const int servoHorizontal = 9;
const int servoVertical = 10;

int topLeftValue, topRightValue, bottomLeftValue, bottomRightValue;
int horizontalAngle, verticalAngle;

void setup() {
  Serial.begin(9600);
  pinMode(ldrTopLeft, INPUT);
  pinMode(ldrTopRight, INPUT);
  pinMode(ldrBottomLeft, INPUT);
  pinMode(ldrBottomRight, INPUT);
  pinMode(servoHorizontal, OUTPUT);
  pinMode(servoVertical, OUTPUT);
}

void loop() {
  // Read sensor values twice to reduce noise
  topLeftValue = analogRead(ldrTopLeft);
  topLeftValue = analogRead(ldrTopLeft);
  topRightValue = analogRead(ldrTopRight);
  topRightValue = analogRead(ldrTopRight);
  bottomLeftValue = analogRead(ldrBottomLeft);
  bottomLeftValue = analogRead(ldrBottomLeft);
  bottomRightValue = analogRead(ldrBottomRight);
  bottomRightValue = analogRead(ldrBottomRight);

  // Calculate optimal angle based on sensor readings
  int averageTop = (topLeftValue + topRightValue) / 2;
  int averageBottom = (bottomLeftValue + bottomRightValue) / 2;
  int averageLeft = (topLeftValue + bottomLeftValue) / 2;
  int averageRight = (topRightValue + bottomRightValue) / 2;

  if (averageTop > averageBottom) {
    verticalAngle = map(averageTop, 0, 1023, 0, 180);
  } else {
    verticalAngle = map(averageBottom, 0, 1023, 0, 180);
  }

  if (averageLeft > averageRight) {
    horizontalAngle = map(averageLeft, 0, 1023, 0, 180);
  } else {
    horizontalAngle = map(averageRight, 0, 1023, 0, 180);
  }

  // Adjust servo angles
  servoWrite(servoHorizontal, horizontalAngle);
  servoWrite(servoVertical, verticalAngle);

  delay(1000); // adjust delay time as needed
}

void servoWrite(int servoPin, int angle) {
  int pulseWidth = map(angle, 0, 180, 500, 2500);
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
  delay(20); // adjust delay time as needed
}