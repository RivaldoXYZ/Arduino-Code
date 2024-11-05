int analogValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(38400);
  Serial2.begin(19200);
  Serial3.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(0);
  serial.println(analogValue);
  serial.println(analogValue, DEC);
  serial.println(analogValue, HEX);
  serial.println(analogValue, OCT);
  serial.println(analogValue, BIN);

  serial.print("NO FORMAT");
  serial.print("/t");
  serial.print("DEC");
  serial.print("/t");
  serial.print("HEX");
  serial.print("/t");
  serial.print("OCT");
  serial.print("/t");
  serial.print("BIN");  
}
