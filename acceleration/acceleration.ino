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

  int x = analogRead(Out_x);
  int y = analogRead(Out_y);
  int z = analogRead(Out_z);

  //Serial.print("X:");
  //Serial.println(x);
  Serial.print("Y:");
  Serial.println(y);
  //Serial.print("Z:");
  //Serial.println(z);
  delay(100);
  
}
