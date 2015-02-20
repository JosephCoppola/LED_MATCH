int g1 = 11;
int b1 = 10;
int r1 = 9;
int g2 = 6;
int b2 = 5;
int r2 = 3;
int s1 = A3;
int s2 = A4;
int s3 = A5;
int r1State = 0;
int g1State = 0;
int b1State = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(g1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  r1State = analogRead(s1);
  g1State = analogRead(s2);
  b1State = analogRead(s3);
  
  int anValR = r1State/4;
  int anValG = g1State/4;
  int anValB = b1State/4;
  
  Serial.println(anValG);
  
  analogWrite(r2,anValR);
  analogWrite(g2,anValG);
  analogWrite(b2,anValB);
  
  setGuessColor(255, 0, 255);  // red
  
  
  
  /*
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);  // yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);  // aqua
  delay(1000);
  */
}
 
void setGuessColor(int red, int green, int blue)
{
  analogWrite(r1, red);
  analogWrite(g1, green);
  analogWrite(b1, blue);  
}
