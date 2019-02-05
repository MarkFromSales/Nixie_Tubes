/* 
https://github.com/MarkFromSales/Nixie_Tubes
More information in the README.MD
*/

#include "Adafruit_MCP23017.h"
Adafruit_MCP23017 mcp1;
Adafruit_MCP23017 mcp2;
#define addr1 0  // 0 = A2 low , A1 low , A0 low
#define addr2 7  // 7 = A2 high, A1 high, A0 high

// Variables for tube enable/disable
int nxeBL = 2;   // Nixie tube backlight control pin
int pinSW = 3;   // Enable switch GPIO 3, pin 5
int valSW = 0;   // Variable for Enable switch pin value
int pinCT = 16;  // How many pins in the MCPs to enable +1

// Function to set all the MCP GPIO pins to HIGH, shutting off the Nixies
void NixiesOff (){
  for (int thisPin = 0; thisPin < pinCT; thisPin++) {
      mcp1.digitalWrite(thisPin, HIGH);
      mcp2.digitalWrite(thisPin, HIGH);
  }
};

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Setup Start");
  mcp1.begin(addr1);
  mcp2.begin(addr2);

  // Set MCP Nixie Tube pins to OUTPUT
  for (int thisPin = 0; thisPin < pinCT; thisPin++) {
    mcp1.pinMode(thisPin, OUTPUT);
    mcp2.pinMode(thisPin, OUTPUT);
  }

  pinMode(nxeBL, OUTPUT);
  pinMode(pinSW, INPUT);
  Serial.println("Setup End");
}

void loop() {
  Serial.println();
  Serial.println("Loop Start");

  valSW = digitalRead(pinSW);      // Check the state of the Nixie enable switch
  Serial.print("valSW = ");
  Serial.println(valSW);

if (valSW == 1) {
  digitalWrite(nxeBL, HIGH);     // Turn on tube backlight LED

  // Tube 1
  mcp1.digitalWrite(0, HIGH);  // D
  mcp1.digitalWrite(1, LOW);   // C
  mcp1.digitalWrite(2, LOW);   // B
  mcp1.digitalWrite(3, LOW);   // A
  // Tube 2
  mcp1.digitalWrite(4, LOW);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, LOW);
  mcp1.digitalWrite(7, LOW);
  // Tube 3
  mcp1.digitalWrite(8, LOW);  // Currently showing 6 to test bug on this Tube with even numbers
  mcp1.digitalWrite(9, HIGH);
  mcp1.digitalWrite(10, HIGH);
  mcp1.digitalWrite(11, LOW);
  // Tube 4
  mcp1.digitalWrite(12, LOW);
  mcp1.digitalWrite(13, LOW);
  mcp1.digitalWrite(14, HIGH);
  mcp1.digitalWrite(15, LOW);
  // Tube 5
  mcp2.digitalWrite(0, HIGH);
  mcp2.digitalWrite(1, LOW);
  mcp2.digitalWrite(2, HIGH);
  mcp2.digitalWrite(3, LOW);
  // Tube 6
  mcp2.digitalWrite(4, LOW);
  mcp2.digitalWrite(5, HIGH);
  mcp2.digitalWrite(6, HIGH);
  mcp2.digitalWrite(7, LOW);
  // Tube 7
  mcp2.digitalWrite(8, HIGH);
  mcp2.digitalWrite(9, HIGH);
  mcp2.digitalWrite(10, HIGH);
  mcp2.digitalWrite(11, LOW);
  // Tube 8
  mcp2.digitalWrite(12, LOW);
  mcp2.digitalWrite(13, LOW);
  mcp2.digitalWrite(14, LOW);
  mcp2.digitalWrite(15, HIGH);

  delay(2000);
  NixiesOff();
  delay(2000);
}  
else {
  NixiesOff();
  digitalWrite(nxeBL, LOW);      // Turn off tube backlight LED
}
  Serial.println("Loop End");
}
//EOF