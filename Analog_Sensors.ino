// C++ code
//
bool analogSel = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  for(uint8_t i(2); i <= 7; i++){
  	pinMode(i, OUTPUT);
  }
}

void loop()                                                                                             
          {
  if(digitalRead(8) == 0){
    analogSel = 1;
    digitalWrite(9, HIGH);   // Red ON
    digitalWrite(10, LOW);   // Green OFF
  }
  else {analogSel = 0;
        digitalWrite(9, LOW);    // Red OFF
        digitalWrite(10, HIGH);  // Green ON
  }
  if(analogSel == 1){
    // Read POT
  			uint16_t potReading = analogRead(A5);
  			uint8_t ledReading = potReading/146;
            
  // Turn all LEDs off
  for(uint8_t i(2); i <= 7; i++){
  			digitalWrite((i), LOW);
    
            }
 			 Serial.println(ledReading);
  // Turn  LEDs on according to POT 
    for(uint8_t i(0); i <= ledReading; i++){
  			digitalWrite((i+2), HIGH);
            }
  }else if(analogSel == 0){
    // Read photo resistor
    uint16_t photoReading = analogRead(A4);
    uint8_t ledReading = ((1023-photoReading)/146);
    
    // Turn all LEDs off
    for(uint8_t i(2); i <= 7; i++){
      digitalWrite((i), LOW);
    }
    
    Serial.println(photoReading);
    
    // Turn LEDs on according to photo resistor reading
    for(uint8_t i(0); i < ledReading; i++){
      digitalWrite((i+2), HIGH);
    }
  }
            delay(500);
          }
