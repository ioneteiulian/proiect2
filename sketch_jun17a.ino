#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,LOW);
  digitalWrite(S1,HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);
  redColor = map(redFrequency, 250, 420, 255,0);
  delay(100);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);
  greenColor = map(greenFrequency, 350,550, 255, 0);
  delay(100);
 
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);
  blueColor = map(blueFrequency, 150, 210, 255, 0);
  Serial.println(String(redColor)+","+String(greenColor)+","+String(blueColor));
  //Serial.println(String(redFrequency)+" "+String(greenFrequency)+" "+String(blueFrequency));
  delay(100);
  
}
