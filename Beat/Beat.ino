#define SPEAKER 25
#define BEATTIME 100

void setup() {
  // put your setup code here, to run once:
  ledcSetup(1,12000,8);
  ledcAttachPin(SPEAKER,1);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long start = millis();
  while(millis() < start + 5000){
    ledcWriteTone(1,262);
    delay(BEATTIME);
    ledcWriteTone(1,264);
    delay(BEATTIME);
    ledcWriteTone(1,330);
    delay(BEATTIME);
    }
  
}
