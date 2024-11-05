int led1 = 9;
int led2 = 10;
int led3 = 11;
int button = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);    
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button) == HIGH){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(30000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(30000);
    digitalWrite(led1, LOs\W);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else {
    digitalWrite(led2, HIGH);
  }
}
