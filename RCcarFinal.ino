// Pin Assignments

const int trigPin = 13;
const int echoPin = 12;
// const int rightPin = 5;
const int leftPin = 6;
const int backwardPin = 7;
const int forwardPin = 8;


const int stopDistance = 20; // anything less than this and the car either turns left or stops
int mode = 0;

void setup() {
  // Setting input and output pins
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // pinMode(rightPin, OUTPUT); 
  pinMode(leftPin, OUTPUT); 
  pinMode(backwardPin, OUTPUT); 
  pinMode(forwardPin, OUTPUT); 
}

void loop() {
  // Ultasonic sensor Logic
  long duration, distance;
  digitalWrite(trigPin, LOW);   //testing distance by toggling the trigger pin and using the echo pin to find how long it took for the signal to bounce back
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; // convert to cm
  if (distance < stopDistance) {    //Obstacle Avoidance Protocal
    mode = 2;   // Car stops
    
    mode = 3;   // Reverses to ensure it has room to turn around
    
    mode = 1;   // Turns around by going left
  }
  switch(mode) {
    case 0:   // Moves the RC Car Foward
      digitalWrite(backwardPin, LOW);
      digitalWrite(forwardPin, HIGH);
      //digitalWrite(rightPin, LOW);
      digitalWrite(leftPin, LOW);
      break;
    case 1:   // Turns the RC car to the left
      digitalWrite(backwardPin, LOW);
      digitalWrite(forwardPin, HIGH);
      //digitalWrite(rightPin, LOW);
      digitalWrite(leftPin, HIGH);
      delay(1000);
      break;
    case 2:   //Stops RC Car
      digitalWrite(backwardPin, LOW);
      digitalWrite(forwardPin, LOW);
      //digitalWrite(rightPin, LOW);
      digitalWrite(leftPin, LOW);
      delay(500);
      break;
    case 3:   // Reverses RC Car
      digitalWrite(backwardPin, HIGH);
      digitalWrite(forwardPin, LOW);
      //digitalWrite(rightPin, LOW);
      digitalWrite(leftPin, LOW);
      delay(200);
      break;
    default:
      break;
  }
}
