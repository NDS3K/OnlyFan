#include <Arduino.h>
// Define chân 

#define motor_pin1 7 // Chân điều khiển cực dương của động cơ
#define motor_pin2 8 // Chân điều khiển cực âm của động cơ
#define ena 9 // Nhận giá trị analog với 255 thì công suất = 100 %, với 0 thì = 0 %
#define trig 10 // chân phát ra sóng âm
#define echo 11 // chân nhận sóng âm

int distance; // biến lưu khoảng cách

long runtime; // biến lưu thời gian nhận tín hiệu từ cảm biến

void setup()
{   
    // Setup các chế độ của pin
    // Do chỉ có echo là nhận thông tin từ bên ngoài nên set input
    pinMode(motor_pin1,OUTPUT);
    pinMode(motor_pin2,OUTPUT);
    pinMode(ena,OUTPUT);
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
}    


void loop()
{

    Serial.begin(9600); //Khởi tạo Serial để đọc thông tin từ cảm biến 

    // trig tạo ra sóng âm 
    digitalWrite(trig,LOW); 
    delayMicroseconds(2);
    digitalWrite(trig,HIGH); 
    delayMicroseconds(5);
    digitalWrite(trig,LOW);

    
    

    runtime = pulseIn(echo,HIGH); //Thời gian echo nhận lại sóng âm

    distance = int(runtime/2/29.412); //Công thức tính sóng âm (datasheet)

    // Câu điều kiện logic nếu distance <= 30 thì khởi động động cơ
    if(distance <= 30)
    {
      digitalWrite(motor_pin1,HIGH); 
      digitalWrite(motor_pin2,LOW);
      analogWrite(ena,255);
    }
    // Câu điều kiện logic nếu distance > 30 thì dừng động cơ 
    else if(distance > 30)
    {
        digitalWrite(motor_pin1,HIGH);
        digitalWrite(motor_pin2,LOW);
        analogWrite(ena,0);
    }
    

    Serial.print(distance);// in ra giá trị khoảng cách 
    Serial.println("cm");
   
    
    
}