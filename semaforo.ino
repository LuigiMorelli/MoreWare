#define RED 13
#define YELLOW 12
#define GREEN 11

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
}

void loop() {
  digitalWrite(RED, HIGH);
  delay(5000);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  delay(5000);
  digitalWrite(YELLOW, HIGH);
  delay(3000);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
}
