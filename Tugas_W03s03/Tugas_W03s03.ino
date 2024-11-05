int ledAqua = 13;
int ledRed = 7;
int ledOrange = 8;
int ledYellow = 10;

void Led1(){
  digitalWrite(ledAqua, HIGH);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledOrange, LOW);
  digitalWrite(ledYellow, HIGH);
  Serial.println("LED 1 Aktif");
  delay(100);
}
void Led2(){
  digitalWrite(ledAqua, LOW);
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledOrange, HIGH);
  digitalWrite(ledYellow, LOW);
  Serial.println("LED 2 Aktif");
  delay(100);
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledAqua, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledOrange, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Led1();
  Led2();
}
