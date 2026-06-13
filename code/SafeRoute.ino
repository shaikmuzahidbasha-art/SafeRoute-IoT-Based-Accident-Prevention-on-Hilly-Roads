Verify

#define TRIG1 9
#define ECHO1 10

#define TRIG2 5
#define ECHO2 6

#define LED1 3      // Red LED for Sensor 2
#define LED2 4      // Red LED for Sensor 1

#define BUZZER1 7   // Buzzer for Sensor 2
#define BUZZER2 8   // Buzzer for Sensor 1

#define GREEN1 11   // Green LED for Sensor 1
#define GREEN2 12   // Green LED for Sensor 2

void setup() {
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);

  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(GREEN1, OUTPUT);
  pinMode(GREEN2, OUTPUT);

  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);

  Serial.begin(9600);
}

long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

void loop() {

  long distance1 = getDistance(TRIG1, ECHO1);
  long distance2 = getDistance(TRIG2, ECHO2);

  Serial.print("Sensor 1: ");
  Serial.print(distance1);
  Serial.print(" cm   |   Sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // SENSOR 1 LOGIC
  if (distance1 > 0 && distance1 <= 5) {
    digitalWrite(LED2, HIGH);
    digitalWrite(BUZZER2, HIGH);
    digitalWrite(GREEN1, LOW);
  }
  else {
    digitalWrite(LED2, LOW);
    digitalWrite(BUZZER2, LOW);
    digitalWrite(GREEN1, HIGH);
  }

  // SENSOR 2 LOGIC
  if (distance2 > 0 && distance2 <= 5) {
    digitalWrite(LED1, HIGH);
    digitalWrite(BUZZER1, HIGH);
    digitalWrite(GREEN2, LOW);
  }
  else {
    digitalWrite(LED1, LOW);
    digitalWrite(BUZZER1, LOW);
    digitalWrite(GREEN2, HIGH);
  }

  delay(200);
}