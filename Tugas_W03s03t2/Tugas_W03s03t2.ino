int ledRed = 13;
int ledGreen = 3;
int button1 = 10;
int button2 = 8;

int But1, But2 = 0;


void fun1(){
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  delay(1000);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
}
void fun2(){
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(1000);
  digitalWrite(ledGreen, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  But1 = digitalRead(button1);
  But2 = digitalRead(button2);
  Serial.println(But1);
  Serial.println(But2);
  if(But1 == 1){
    fun1();
  }
  if(But2 == 1) {
    fun1();
  }
  else {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
  }
}
