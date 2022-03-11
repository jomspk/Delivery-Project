#define Out_x 2
#define Out_y 0
#define Out_z 4

void setup() {
  // put your setup code here, to run once:

  Initialization();
}

void Initialization(){

  Serial.begin(9600);
  Serial.println("Starting!");
  pinMode(Out_x, OUTPUT);
  pinMode(Out_y, OUTPUT);
  pinMode(Out_z, OUTPUT);
  }
void loop() {
  // put your main code here, to run repeatedly:
  // 地球の重力である1Gの加速度
  float ms2 = 9.80665;

  // 電源電圧3.3V時のオフセット電圧
  float offset_voltage = 1.650;

  // XYZの電圧を取得する
  float x = (analogRead(Out_x)/1024.0)*5.0*1000;
  float y = (analogRead(Out_y)/1024.0)*5.0*1000;
  float z = (analogRead(Out_z)/1024.0)*5.0*1000;

  // XYZからオフセット電圧を引いた電圧を求める
  x = x - offset_voltage;
  y = y - offset_voltage;
  z = z - offset_voltage;

  // XYZから重力を求める
  float xg = x/1000.0;
  float yg = y/1000.0;
  float zg = z/1000.0;

  // XYZの重力から加速度を算出して出力する
  Serial.print("X:");
  Serial.print(xg*ms2);
  Serial.print("Y:");
  Serial.print(yg*ms2);
  Serial.print("Z:");
  Serial.println(zg*ms2);
  delay(100);
  
}
