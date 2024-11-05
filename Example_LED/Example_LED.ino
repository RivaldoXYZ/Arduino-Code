void speedBuzzer(int waktu);
const int pinBuzzer = 0;
int ulang = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pinBuzzer, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  for ( ulang = 0; ulang < 20; ulang++) {
    speedBuzzer(250);
  }
  for ( ulang = 0; ulang < 20; ulang++) {
    speedBuzzer(500);
  }
}
void speedBuzzer(int waktu) {
  digitalWrite(pinBuzzer, HIGH);
  delay(waktu);
  digitalWrite(pinBuzzer, LOW);
  delay(waktu);
}