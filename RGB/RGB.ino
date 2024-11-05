int ledgreen = 1;
int ledred = 2;
int ledyellow = 3;
int led2 = 4;
const int buzzer = 13;

void setup() {
  pinMode (ledgreen, OUTPUT);
  pinMode (ledred, OUTPUT);
  pinMode (ledyellow, OUTPUT);
  pinMode (led2, OUTPUT);
}

void loop() {
  digitalWrite (ledgreen, HIGH);
  digitalWrite (ledred, LOW);
  digitalWrite (ledyellow, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (buzzer, HIGH);
  delay(100);
  digitalWrite (ledgreen, LOW);
  digitalWrite (ledred, HIGH);
  digitalWrite (ledyellow, LOW);
  digitalWrite (led2, LOW);
  digitalWrite (buzzer, LOW);
  delay(100);
  digitalWrite (ledgreen, LOW);
  digitalWrite (ledred, LOW);
  digitalWrite (ledyellow, HIGH);
  digitalWrite (led2, LOW);
  digitalWrite (buzzer, HIGH);
  delay(100);
  digitalWrite (ledgreen, LOW);
  digitalWrite (ledred, LOW);
  digitalWrite (ledyellow, LOW);
  digitalWrite (led2, HIGH);
  digitalWrite (buzzer, LOW);
  delay(100);
  
}
