/* 
  https://github.com/MarkFromSales/Nixie_Tubes
  More information in the README.MD

  Based on provided example, "Blink without Delay"
*/

// Variables will change:
int ledState  = LOW;                 // ledState used to set the LED
int potVal;                          // Variable value of potentiometer pin
unsigned long previousMillis = 0;    // will store last time LED was updated

// Constants won't change:
const long interval = 2000;     // interval at which to blink (milliseconds)
const int ledPin =  8;          // Tube backlight pin
const int potPin = A5;          // Potentiometer pin

// Tube variables
int driverA = 13; // Set the K155ID1 or 74141 IC input A Arduino GPIO pin
int driverB = 11; // Set the K155ID1 or 74141 IC input B Arduino GPIO pin
int driverC = 10; // Set the K155ID1 or 74141 IC input C Arduino GPIO pin
int driverD = 12; // Set the K155ID1 or 74141 IC input D Arduino GPIO pin
int tubeDot = 9;  // Pin to directly drive the decimal for tubes with that pin

// Function to set all the MCP GPIO pins to HIGH, shutting off the Nixies
void NixieOff () {
  digitalWrite(driverD, HIGH);
  digitalWrite(driverC, HIGH);
  digitalWrite(driverB, HIGH);
  digitalWrite(driverA, HIGH);
};

void NixieSet (int tubeVal) {
  digitalWrite(driverD, (tubeVal & 0x08) >> 3);
  digitalWrite(driverC, (tubeVal & 0x04) >> 2);
  digitalWrite(driverB, (tubeVal & 0x02) >> 1);
  digitalWrite(driverA, tubeVal & 0x01);
};


void setup() {
  // Initialize serial for debugging
  Serial.begin(9600);
  Serial.println();
  Serial.println("Setup Start");
  
  // Set the pin configurations
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(tubeDot, OUTPUT);
  digitalWrite(tubeDot, HIGH);
  pinMode(driverA, OUTPUT);
  pinMode(driverB, OUTPUT);
  pinMode(driverC, OUTPUT);
  pinMode(driverD, OUTPUT);
  NixieOff();
  Serial.println("Setup End");
}


void loop() {
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  potVal = map(analogRead(potPin), 0, 1023, 500, 5);

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState  = HIGH;
      NixieOff();    // Set all four Nixie IC inputs to HIGH, which is none
    } else {
      ledState  = LOW;
      NixieSet(analogRead(potPin) / 100);   // Set Nixie IC inputs according to what is in the brackets (0-9)
      Serial.print("potPin /100 Value: ");
      Serial.println(analogRead(potPin) / 100);
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}

// EOF
