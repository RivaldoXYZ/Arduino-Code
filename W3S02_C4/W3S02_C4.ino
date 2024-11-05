int led = 9;
int button = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button) == HIGH){
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
