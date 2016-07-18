//Make variables that correspond to pins
int speakerPin = 9;

int redPotPin = A0;
int bluePotPin = A1;
int greenPotPin = A2;

int redLedPin = 3;
int blueLedPin = 6;
int greenLedPin = 5;

int echoPin = 11;
int trigPin = 10;

int amountOfPots = 3;
 
void setup() {
  //Set the IO modes for all of the pins
  pinMode(redPotPin, INPUT);
  pinMode(bluePotPin, INPUT);
  pinMode(greenPotPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  //Read in the color values from the potentiometers and send it to the LED
  int redValue =  analogRead(redPotPin);
  int blueValue =  analogRead(bluePotPin);
  int greenValue =  analogRead(greenPotPin);
  analogWrite(redLedPin, redValue / 4);
  analogWrite(blueLedPin, blueValue / 4);
  analogWrite(greenLedPin, greenValue / 4);
  //Initialise ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Get distance from ultrasonic sensor
  int duration = pulseIn(echoPin, HIGH);
  float distanceInCentimeters = duration / 29 / 2;
  //Calculate frequency to use to turn speaker on and off at
  float mappedDistanceInCentimeters = map(0, 2000, 0, 678, distanceInCentimeters);
  float averagePotValue = ((redValue/ 4) + (blueValue / 4) + (greenValue / 4) + (mappedDistanceInCentimeters * 3)) / (amountOfPots + 3);
  float speakerDelay = map(0, 200, 300\
  , 700, averagePotValue);
  //Loop 75 times and turn speaker on and off at calculated frequency
  for (int i = 0; i < 75; i++)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(speakerDelay);
    digitalWrite(speakerPin, LOW);
  }
}
