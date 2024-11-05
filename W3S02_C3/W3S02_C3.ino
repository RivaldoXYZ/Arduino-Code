#define ledpin 9
#define buttonpin 7

int buttonstate = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
  pinMode(buttonpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonstate = digitalRead(buttonpin);
  digitalWrite(ledpin, buttonstate);
}
