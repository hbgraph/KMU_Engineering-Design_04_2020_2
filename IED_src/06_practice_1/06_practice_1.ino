#define PIN_LED 9

int i;

void setup(){
    pinMode(PIN_LED, OUTPUT);
}

void loop(){
    // 0 ~ 255
    analogWrite(PIN_LED, 0);
    delay(1000);
    analogWrite(PIN_LED, 120);
    delay(1000);
    analogWrite(PIN_LED, 255);
    delay(1000);
    for(i=0; i<256; i++){
      analogWrite(PIN_LED, i++);
      delay(10);
    }
}
