int lmerah1 = 13;
int lkuning1 = 12;
int lhijau1 = 11;
int lmerah2 = 10;
int lkuning2 = 9;
int lhijau2 = 8;
int lmerah3 = 3;
int lkuning3 = 2;
int lhijau3 = 1;

byte ldr = A1;
byte led = 7;
int nilai;

void setup() {
  // put your setup code here, to run once:
    pinMode(lmerah1, OUTPUT);
    pinMode(lkuning1, OUTPUT);
    pinMode(lhijau1, OUTPUT);
    pinMode(lmerah2, OUTPUT);
    pinMode(lkuning2, OUTPUT);
    pinMode(lhijau2, OUTPUT);
    pinMode(lmerah3, OUTPUT);
    pinMode(lkuning3, OUTPUT);
    pinMode(lhijau3, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai = analogRead(ldr);
  if (nilai < 20){
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
digitalWrite(lmerah1, HIGH);
digitalWrite(lkuning1, LOW);
digitalWrite(lhijau1, LOW);

digitalWrite(lmerah2, LOW);
digitalWrite(lkuning2, HIGH);
digitalWrite(lhijau2, LOW);

digitalWrite(lmerah3, LOW);
digitalWrite(lkuning3, LOW);
digitalWrite(lhijau3, HIGH);
delay(2000);

digitalWrite(lmerah1, LOW);
digitalWrite(lkuning1, HIGH);
digitalWrite(lhijau1, LOW);

digitalWrite(lmerah2, LOW);
digitalWrite(lkuning2, LOW);
digitalWrite(lhijau2, HIGH);

digitalWrite(lmerah3, HIGH);
digitalWrite(lkuning3, LOW);
digitalWrite(lhijau3, LOW);
delay(20000);
digitalWrite(lmerah1, LOW);
digitalWrite(lkuning1, LOW);
digitalWrite(lhijau1, HIGH);

digitalWrite(lmerah2, HIGH);
digitalWrite(lkuning2, LOW);
digitalWrite(lhijau2, LOW);

digitalWrite(lmerah3, LOW);
digitalWrite(lkuning3, HIGH);
digitalWrite(lhijau3, LOW);
}
