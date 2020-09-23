void setup(){
  // 시리얼 포트 초기화
  Serial.begin(115200);
}

void loop(){
  Serial.println("Hello World!"); // serial 포트로 메시지 출력 후 줄바꿈 (println)
  delay(1000); // 1초간 대기
}
