// Arduino pin assignment
#define PIN_LED 9
#define PIN_TRIG 12
#define PIN_ECHO 13

// configurable parameters
#define SND_VEL 346.0 // sound velocity at 24 celsius degree (unit: m/s)
#define INTERVAL 100 // sampling interval (unit: ms)
#define _DIST_MIN 100 // minimum distance to be measured (unit: mm)
#define _DIST_MAX 300 // maximum distance to be measured (unit: mm)

// global variables
float timeout; // unit: us
float dist_min, dist_max, dist_raw; // unit: mm
float scale; // convert pulse duration to distance

void setup(){
// initialize GPIO pins
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_TRIG, OUTPUT);
    digitalWrite(PIN_TRIG, LOW);
    pinMode(PIN_ECHO, INPUT);

// initialize USS related variables
    dist_min = _DIST_MIN;
    dist_max = _DIST_MAX;
    timeout = (INTERVAL / 2) * 1000.0; // precalculate pulseIn() timeout value. (unit: us)
    dist_raw = 0.0;
    scale = 0.001 * 0.5 * SND_VEL;

// initialize serial port
    Serial.begin(38400);
}

void loop(){
// get a distance reading from the USS
    dist_raw = USS_measure(PIN_TRIG, PIN_ECHO);
// output the read value to the serial port
    Serial.print("MIN:0,");
    Serial.print("raw:");
    Serial.print(dist_raw); Serial.print(",");
    Serial.println("Max:400");
// turn on the LED if the distance is between dist_min and dist_max
    if(dist_raw < dist_min || dist_raw > dist_max){
        analogWrite(PIN_LED, 255);
    }
    else{
        analogWrite(PIN_LED, 0);
    }
// do something here
        delay(50); // assume that it takes 50ms to do something.
// wait until next sampling time
    delay(INTERVAL);
}

// get a distance reading from USS. return value is in millimeter.
float USS_measure(int TRIG, int ECHO)
{
    float reading;
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    reading = pulseIn(ECHO, HIGH, timeout) * scale; // unit: mm
    if(reading < dist_min || reading > dist_max) reading = 0.0; // return 0 when out of range.
    return reading;
}
