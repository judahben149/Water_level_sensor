//Water level sensor project with LED indicators
//Two float sensors (which are just contact switches that either close...
//...or open based on the level of the water) are used here


const int upperswitch = 2; //Pin on the Arduino where the first float switch is connected
const int lowerswitch = 3; // Pin on the Arduino where the second float switch is connected
const int pumplight = A0; //Pin of the LED that shows if the pump is on or off
const int upperlight = A3; //LED that shows if the water is still above 75%(or wherver you position the float switch)
const int lowerlight = A1; //LED that shows if the water is still above 25%
const int relay = 4; //Pin where the relay is connected to

int upper = 0;
int lower = 0;
bool state = false;

void setup() {
  //setup code here runs once:
  
  // declare which pins are used as output and which are input
  pinMode(relay, OUTPUT);
  pinMode(upperswitch, INPUT);
  pinMode(lowerswitch, INPUT);
  pinMode(upperlight, OUTPUT);
  pinMode(lowerlight, OUTPUT);
  pinMode(pumplight, OUTPUT);

  //set the initial state for the pins the devices are connected to
  //The upper and lower lights are turned on briefly then back off when the device is first turned on
  digitalWrite(relay, LOW);
  digitalWrite(upperlight, HIGH);
  digitalWrite(lowerlight, HIGH);
  delay(3000);
  digitalWrite(upperlight, LOW);
  digitalWrite(lowerlight, LOW);
  delay (2000);
}


void loop() {
  //code here runs on and on forever
  upper = digitalRead(upperswitch); //take digital readings of the upper switch pin and store the value in the variable
  lower = digitalRead(lowerswitch);//take digital readings of the lower switch pin and store the value in the variable

  if (upper == HIGH) { //code to run if the upper switch is high
    digitalWrite(relay, LOW);
    digitalWrite(upperlight, HIGH);
    digitalWrite(pumplight, LOW);
    if (lower == HIGH) {
      digitalWrite(lowerlight, HIGH);
    }
  }
  else if (upper == LOW) {
    digitalWrite(upperlight, LOW);
  }

  if (lower == HIGH) {
    digitalWrite(lowerlight, HIGH);
  }

  if (upper == LOW) {
    if (lower == LOW) {
      digitalWrite(relay, HIGH);
      digitalWrite(lowerlight, LOW);
      digitalWrite(pumplight, HIGH);
    }
  }

}
