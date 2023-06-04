// defines pins numbers
int buzzer = 4;
const int trigPin = 5;
const int echoPin = 6;
// defines variables
long duration;
int distance = 0;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(4, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
if ((distance > 0)&&(distance < 10))
  {
  tone(buzzer, 450);
  delay(100);
  noTone(buzzer);
  delay(100);
}
else if ((distance > 10)&&(distance < 50))
  {
  tone(buzzer, 450);
  delay(500);
  noTone(buzzer);
  delay(500);
  }
else if ((distance > 50)&&(distance < 100)) {
  tone(buzzer, 450);
  delay(1000);
  noTone(buzzer);
  delay(1000);
}
else if (distance > 100){
  digitalWrite(buzzer, LOW);
}
delayMicroseconds(10);
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance); //distance is the returned integer, it is the distance in cm
}
