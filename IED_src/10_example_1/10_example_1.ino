#include <Servo.h>
#define PIN_SERVO 10

Servo myservo;
int degree;

void setup() {
  Serial.begin(9600);
  degree = 0;
  myservo.attach(PIN_SERVO); 
  myservo.write(degree);
}

void loop() {
    myservo.write(degree);
    delay(200);
    Serial.println(myservo.read());
    if(degree == 0){
      degree += 180;
    }else if(degree == 180){
      degree -= 180;
    }
}
