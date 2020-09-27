#define PIN_LED 7

int i;
int j;
int duty;
int period;

void setup(){
    pinMode(PIN_LED, OUTPUT);
    period = set_period(100);
}

void loop(){
    for(i=0; i<100; i++){
        duty = set_duty(i);
	      for(j=0; j<5; j++){
	          digitalWrite(PIN_LED, 1);
            delayMicroseconds(period * (duty / 100));
	          digitalWrite(PIN_LED, 0);
	          delayMicroseconds(period - period * (duty / 100));
	       }
    }
    for(i=100; i>0; i--){
        duty = set_duty(i);
	      for(j=0; j<5; j++){
	          digitalWrite(PIN_LED, 1);
            delayMicroseconds(period * (duty / 100));
	          digitalWrite(PIN_LED, 0);
	          delayMicroseconds(period - period * (duty / 100));
	       }
     }
}

int set_period(int period){
    // period: 100 to 10000 (unit: us)
    return period;
}
int set_duty(int duty){
    // duty: 0 to 100 (unit: %)
    return duty;
}
