/* 
  https://github.com/MarkFromSales/Nixie_Tubes
  More information in the README.MD
*/

#include "Adafruit_MCP23017.h"
Adafruit_MCP23017 mcp1;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Setup Start");
  mcp1.begin(0x00);
  
  // Tube 1
  mcp1.pinMode(0, OUTPUT);
  mcp1.pinMode(1, OUTPUT);
  mcp1.pinMode(2, OUTPUT);
  mcp1.pinMode(3, OUTPUT);
  // Tube 2
  mcp1.pinMode(4, OUTPUT);
  mcp1.pinMode(5, OUTPUT);
  mcp1.pinMode(6, OUTPUT);
  mcp1.pinMode(7, OUTPUT);
  // Tube 3
  mcp1.pinMode(8, OUTPUT);
  mcp1.pinMode(9, OUTPUT);
  mcp1.pinMode(10, OUTPUT);
  mcp1.pinMode(11, OUTPUT);
  // Tube 4
  mcp1.pinMode(12, OUTPUT);
  mcp1.pinMode(13, OUTPUT);
  mcp1.pinMode(14, OUTPUT);
  mcp1.pinMode(15, OUTPUT);

  Serial.println("Setup End");
}

void loop() {
  Serial.println();
  Serial.println("Loop Start");

  // Tube 1
  mcp1.digitalWrite(0, LOW);
  mcp1.digitalWrite(1, HIGH);
  mcp1.digitalWrite(2, HIGH);
  mcp1.digitalWrite(3, LOW);
  // Tube 2
  mcp1.digitalWrite(4, LOW);
  mcp1.digitalWrite(5, HIGH);
  mcp1.digitalWrite(6, HIGH);
  mcp1.digitalWrite(7, LOW);
  // Tube 3
  mcp1.digitalWrite(8, LOW);
  mcp1.digitalWrite(9, HIGH);
  mcp1.digitalWrite(10, HIGH);
  mcp1.digitalWrite(11, LOW);
  // Tube 4
  mcp1.digitalWrite(12, LOW);
  mcp1.digitalWrite(13, HIGH);
  mcp1.digitalWrite(14, HIGH);
  mcp1.digitalWrite(15, LOW);

  delay(2000);
  Serial.println("Loop End");
}
//EOF