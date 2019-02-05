/* 
  https://github.com/MarkFromSales/Nixie_Tubes
  More information in the README.MD

  Based on provided example, "Blink without Delay"
*/

// Variables will change:
int potVal;    // Variable value of potentiometer pin
int swtVal;    // Varuabke value of the switch pin

// Constants won't change:
const int ledPin = 8;           // Tube backlight pin
const int potPin = A5;          // Potentiometer pin
const int swtPin = 7;           // Pin to use for the on/off switch


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
  pinMode(swtPin, INPUT);
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
  potVal = map(analogRead(potPin), 0, 1023, 500, 5);
  swtVal = digitalRead(swtPin);
  
  if (swtVal == 1) {
    NixieOff();    // Set all four Nixie IC inputs to HIGH, which is none
    digitalWrite(ledPin, HIGH);
  } else {
    NixieSet(analogRead(potPin) / 100);   // Set Nixie IC inputs according to what is in the brackets (0-9)
    digitalWrite(ledPin, LOW);
    Serial.print("potPin /100 Value: ");
    Serial.println(analogRead(potPin) / 100);
  }

}

// EOF