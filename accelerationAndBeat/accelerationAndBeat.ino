#define Out_x 2
#define Out_y 15
#define Out_z 4
#define SPEAKER 25
#define BEATTIME 350

// offset voltage when 3.3V
float offset_voltage = 1650.0;
// Gravitational acceleration
float ms2 = 9.80665;
void setup() {
  // put your setup code here, to run once:
  Initialization();
}

void loop() {
  // put your main code here, to run repeatedly:
  float z_axis = calc_acceleration();
  if(z_axis>85)
  Beat();
}

void Initialization(){

  Serial.begin(9600);
  Serial.println("Starting!");

  // Setup for acceleration
  pinMode(Out_x, OUTPUT);
  pinMode(Out_y, OUTPUT);
  pinMode(Out_z, OUTPUT);

  // Setup for buzzer
  ledcSetup(1,12000,8);
  ledcAttachPin(SPEAKER,1);
  }

float calc_acceleration(){
  // Get XYZ voltage
  float x = (analogRead(Out_x)/1024.0)*3.3*1000;
  float y = (analogRead(Out_y)/1024.0)*3.3*1000;
  float z = (analogRead(Out_z)/1024.0)*3.3*1000;

  // minus offset voltage
  x = x - offset_voltage;
  y = y - offset_voltage;
  z = z - offset_voltage;

  // Get XYZ gravity
  float xg = x/1000.0;
  float yg = y/1000.0;
  float zg = z/1000.0;

  // XYZの重力から加速度を算出して出力する
  Serial.print("X:");
  Serial.print(xg*ms2);
  Serial.print(",Y:");
  Serial.print(yg*ms2);
  Serial.print(",Z:");
  Serial.println(zg*ms2);
  delay(100);

  return zg*ms2;
  }
void Beat(){
  unsigned long start = millis();
  while(millis() < start + 5000){
    Beat_first();
    Beat_first();
    Beat_second();
    Beat_first();
    Beat_first();
    Beat_second();
    ledcWriteTone(1, 0);
    }
  }

void Beat_first(){
  ledcWriteTone(1,494);
  delay(BEATTIME);
  ledcWriteTone(1,494);
  delay(BEATTIME);  
  ledcWriteTone(1,494);
  delay(BEATTIME*2); 
  }
void Beat_second(){
  ledcWriteTone(1,622);
  delay(BEATTIME);
  ledcWriteTone(1,494);
  delay(BEATTIME);  
  ledcWriteTone(1,494);
  delay(BEATTIME);
  ledcWriteTone(1,440);
  delay(BEATTIME);  
  ledcWriteTone(1,392);
  delay(BEATTIME);
  ledcWriteTone(1,440);
  delay(BEATTIME);
  ledcWriteTone(1,494);
  delay(BEATTIME*2);
  } 
void Beat_third(){
  ledcWriteTone(1,440);
  delay(BEATTIME);
  ledcWriteTone(1,330);
  delay(BEATTIME);  
  ledcWriteTone(1,440);
  delay(BEATTIME);
  ledcWriteTone(1,330);
  delay(BEATTIME);  
  } 
