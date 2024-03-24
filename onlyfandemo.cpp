#include <Arduino.h>

// Define chân cắm 
#define ir_pin A0
#define motor_pin 5
int analog_values;
int digital_values;

void setup() {
  // Điều chỉnh Mode của chân cắm 
  
  pinMode(ir_pin,INPUT);
  pinMode(motor_pin,OUTPUT);
}

void loop() {
  get_values();
  if( digitalRead(ir_pin) == 1)
  {
    analogWrite(motor_pin,255);
  }
  else if (digitalRead(ir_pin)==0)
  {
    analogWrite(motor_pin,0);
  }
  

  
  
}
void get_values(){
  analog_values = analogRead(ir_pin);
  digital_values = digitalRead(ir_pin);
  Serial.print("Gía trị Analog của Sensor "+ analog_values );
  Serial.print("Gía trị Digital của Sensor "+ digital_values);
}


