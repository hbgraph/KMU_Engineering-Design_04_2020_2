int outPin = 7;               

void setup() {
  pinMode(outPin, OUTPUT);    
}

void loop() {
  digitalWrite(outPin, HIGH); 
  delayMicroseconds(1000);      
  digitalWrite(outPin, LOW); 
  delayMicroseconds(1000);
}
