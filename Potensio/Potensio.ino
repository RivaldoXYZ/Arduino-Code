byte potensio = A0;
int nilai_pot, nilai_pwm;
byte led = 3;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  nilai_pot = analogRead(potensio);
  nilai_pwm = map(nilai_pot, 0, 1023, 0, 255);
  Serial.println(String() + nilai_pot + "" + nilai_pwm);
  analogWrite(led, nilai_pwm);
} 