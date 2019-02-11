/* 
  https://github.com/MarkFromSales/Nixie_Tubes
  More information in the README.MD

  Based on provided example, "Blink without Delay"

  Testing using the I2C adapter for 16x2 LCD from - http://wiki.sunfounder.cc/index.php?title=I2C_LCD2004
*/


// Constants won't change:
const int ledPin = 8;           // Tube backlight pin

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


// Setup for keypad input
//#include "Arduino.h"
#include "Keypad.h"
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {7, 6, 5, 4}; //connect to the row    pinouts of the keypad - four in a row
byte colPins[COLS] = {A0, A1, A2, A3}; //connect to the column pinouts of the keypad - four in a row

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);



void setup() {
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

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  // Print a test message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("  Nixie Tester  ");
  lcd.setCursor(0,1);
  lcd.print("                ");
  
  Serial.println("Setup End");
}


void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY && key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '#' && key != '*') {
    NixieSet(key);   // Set Nixie IC inputs according to what is in the brackets (0-9)
    digitalWrite(tubeDot, HIGH);
    digitalWrite(ledPin, LOW);
    Serial.print("Key Pressed: ");
    Serial.println(key);
    lcd.setCursor(0,1);
    lcd.print(" Key Pressed:   ");
    lcd.setCursor(14,1);
    lcd.print(key);
    delay(2000);
  }
  else if (key != NO_KEY && key == '*') {
    NixieOff();
    digitalWrite(tubeDot, LOW);
    digitalWrite(ledPin, LOW);
    Serial.print("Key Pressed: ");
    Serial.println(key);
    lcd.setCursor(0,1);
    lcd.print(" Key Pressed:   ");
    lcd.setCursor(14,1);
    lcd.print(key);
    delay(2000);
  }
  else if (key != NO_KEY) {
    NixieOff();
    digitalWrite(tubeDot, HIGH);
    digitalWrite(ledPin, HIGH);
    Serial.print("Key Pressed: ");
    Serial.println(key);
    lcd.setCursor(0,1);
    lcd.print(" Key Pressed:   ");
    lcd.setCursor(14,1);
    lcd.print(key);
    delay(2000);
  }
  else {
    NixieOff();    // Set all four Nixie IC inputs to HIGH, which is none
    digitalWrite(tubeDot, HIGH);
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0,1);
    lcd.print("                ");
    //lcd.clear();
  }

}

// EOF
