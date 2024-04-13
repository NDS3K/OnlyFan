#include <Arduino.h>
 
#define ir_pin 6
#define motor_pin1 7 
#define motor_pin2 8 
#define ena 9 
#define trig 10 
#define echo 11 
int distance; 
long duration;
long runtime; 

void setup()
{   
    Serial.begin(9600);
    
    pinMode(motor_pin1,OUTPUT);
    pinMode(motor_pin2,OUTPUT);
    pinMode(ena,OUTPUT);
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    digitalWrite(echo,HIGH);
    pinMode(ir_pin,INPUT);
    
}    


void loop()
{
    
    digitalWrite(trig,LOW); 
    delayMicroseconds(5);
    digitalWrite(trig,HIGH);
    delayMicroseconds(5);
    digitalWrite(trig,LOW);

    
    runtime = pulseIn(ir_pin,LOW);

    distance = int(runtime/2/29.412);

    
    /*if( distance > 0 && distance <= 30)
    {
      digitalWrite(motor_pin1,LOW); 
      digitalWrite(motor_pin2,HIGH);
      analogWrite(ena,255);
    }
    else if(distance > 30)
    {
        digitalWrite(motor_pin1,LOW);
        digitalWrite(motor_pin2,HIGH);
        analogWrite(ena,0);
    }*/
    
    

    if(digitalRead(ir_pin)== LOW){
        digitalWrite(motor_pin1,LOW); 
        digitalWrite(motor_pin2,HIGH);
        analogWrite(ena,255);
    }
    else{
         digitalWrite(motor_pin1,LOW);
        digitalWrite(motor_pin2,HIGH);
        analogWrite(ena,0);
    }
    if(millis() - duration > 400){
        Serial.println(digitalRead(ir_pin));
        Serial.println(analogRead(ir_pin));
        Serial.println( "rt"+runtime);
        duration = millis();
    }
   
    
    
}