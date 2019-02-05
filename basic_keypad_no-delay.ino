/* 
https://github.com/MarkFromSales/Nixie_Tubes
More information in the README.MD
*/

// Tube variables
const int driverA = 13; // Set the K155ID1 or 74141 IC input A Arduino GPIO pin
const int driverB = 11; // Set the K155ID1 or 74141 IC input B Arduino GPIO pin
const int driverC = 10; // Set the K155ID1 or 74141 IC input C Arduino GPIO pin
const int driverD = 12; // Set the K155ID1 or 74141 IC input D Arduino GPIO pin
const int tubeDot = 9;  // Pin to directly drive the decimal for tubes with that pin
const int ledPin = 8;           // Tube backlight pin

// Function to set all the Nixie IC GPIO pins to HIGH, shutting off the Nixies
void NixieOff () {
  digitalWrite(driverD, HIGH);
  digitalWrite(driverC, HIGH);
  digitalWrite(driverB, HIGH);
  digitalWrite(driverA, HIGH);
};

// Function to set the value of the Nixie tube by taking the input number, converting it to Binary Coded Decimal (BCD), and writing pins for IC inputs
void NixieSet (int tubeVal) {
  digitalWrite(driverD, (tubeVal & 0x08) >> 3);
  digitalWrite(driverC, (tubeVal & 0x04) >> 2);
  digitalWrite(driverB, (tubeVal & 0x02) >> 1);
  digitalWrite(driverA, tubeVal & 0x01);
};


// Setup for keypad input
#include "Keypad.h"
const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {7, 6, 5, 4};     //connect to the row    pinouts of the keypad - four in a row
byte colPins[COLS] = {A0, A1, A2, A3}; //connect to the column pinouts of the keypad - four in a row

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


class NixieUpdate {
    int tubeVal;                 // Sets the value of the tube
    char key = keypad.getKey();  // Capture the key press from the keypad

    public:
    NixieUpdate (int value) {
        key = value;
    }

    void Update() {
        if (key != NO_KEY && key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '#' && key != '*') {
            NixieSet(key);
            digitalWrite(tubeDot, HIGH);
            digitalWrite(ledPin, LOW);
            Serial.print("Void Update Condition 1: Key ");
            Serial.println(key);
        }
        else if (key != NO_KEY && key == '*') {
            NixieOff();
            digitalWrite(tubeDot, LOW);
            digitalWrite(ledPin, LOW);
            Serial.print("Void Update Condition 2: Key ");
            Serial.println(key);
        }
        else if (key != NO_KEY) {
            NixieOff();
            digitalWrite(tubeDot, HIGH);
            digitalWrite(ledPin, HIGH);
            Serial.print("Void Update Condition 3: Key ");
            Serial.println(key);
        }
        else {
            NixieOff();
            digitalWrite(tubeDot, HIGH);
            digitalWrite(ledPin, HIGH);
            //Serial.println("Void Update Condition 4: No Key");
        }
    }
};

NixieUpdate tube();

void setup(){
  // Initialize serial for debugging
  Serial.begin(9600);
  Serial.println();
  Serial.println("Setup Start");
  
  // Set the pin configurations
  pinMode(ledPin, OUTPUT);
  pinMode(tubeDot, OUTPUT);
  digitalWrite(tubeDot, HIGH);
  pinMode(driverA, OUTPUT);
  pinMode(driverB, OUTPUT);
  pinMode(driverC, OUTPUT);
  pinMode(driverD, OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  
  NixieOff();
  Serial.println("Setup End");
}

void loop() {
  char key = keypad.getKey();
  NixieUpdate tube(key);
  tube.Update();
}

// EOF