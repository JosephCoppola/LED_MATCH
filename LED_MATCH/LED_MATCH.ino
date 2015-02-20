int g1 = 11;
int b1 = 10;
int r1 = 9;
int g2 = 6;
int b2 = 5;
int r2 = 3;
int s1 = A0;
int s2 = A1;
int s3 = A2;
int r1State;
int g1State;
int b1State;
int redAnswer;
int greenAnswer;
int blueAnswer;
boolean redCorrect;
boolean greenCorrect;
boolean blueCorrect;

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
  
  r1State = 0;
  g1State = 0;
  b1State = 0;
  redAnswer = 0;
  greenAnswer = 0;
  blueAnswer = 0;
  
  redCorrect = false;
  greenCorrect = false;
  blueCorrect = false;
  
  randomSeed(analogRead(5));
  
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
  
  setUserColor(anValR,anValG,anValB);
  setGuessColor(redAnswer,greenAnswer,blueAnswer);
  
  if(anValR >= redAnswer - 20 && anValR <= redAnswer + 20)
  {
    redCorrect = true;
  }
  else
  {
    redCorrect = false;
  }
  if(anValG >= greenAnswer - 20 && anValG <= greenAnswer + 20)
  {
    greenCorrect = true;
  }
  else
  {
    greenCorrect = false;
  }
  if(anValB >= blueAnswer - 20 && anValB <= blueAnswer + 20)
  {
    blueCorrect = true;
  }
  else
  {
    blueCorrect = false;
  }
}

void setUserColor(int red, int green, int blue)
{
  analogWrite(r2,red);
  analogWrite(g2,green);
  analogWrite(b2,blue);
}
 
void setGuessColor(int red, int green, int blue)
{
  analogWrite(r1, red);
  analogWrite(g1, green);
  analogWrite(b1, blue);  
}

void setRandomColorAnswer()
{
  redAnswer = random(-180,255);
  greenAnswer = random(-180,255);
  blueAnswer = random(-180,255);
  
  if(redAnswer < 0)
  {
    redAnswer = 0;
  }
  if(greenAnswer < 0)
  {
    greenAnswer = 0;
  }
  if(blueAnswer < 0)
  {
    blueAnswer = 0;
  }
}

void correctAnswer()
{
  setUserColor(0,255,0);
  setGuessColor(0,255,0);
  delay(100);
  setUserColor(0,0,0);
  setGuessColor(0,0,0);
  delay(100);
  setUserColor(0,255,0);
  setGuessColor(0,255,0);
  delay(100);
  setUserColor(0,0,0);
  setGuessColor(0,0,0);
  delay(100);
  setUserColor(0,255,0);
  setGuessColor(0,255,0);
  delay(100);
  setUserColor(0,0,0);
  setGuessColor(0,0,0);
  delay(100);
}
