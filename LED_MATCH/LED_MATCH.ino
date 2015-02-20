int g1 = 11;
int b1 = 10;
int r1 = 9;
int g2 = 3;
int b2 = 5;
int r2 = 6;
int s1 = A0;
int s2 = A1;
int s3 = A2;
int rState;
int gState;
int bState;
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
  
  rState = 0;
  gState = 0;
  bState = 0;
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
  rState = analogRead(s1);
  gState = analogRead(s2);
  bState = analogRead(s3);
  
  int anValR = rState/4;
  int anValG = gState/4;
  int anValB = bState/4;
  
  if(anValR < 5)
  {
    anValR = 0;
  }
  if(anValG < 5)
  {
    anValG = 0;
  }
  if(anValB < 5)
  {
    anValB = 0;
  }
  
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
  
  if(redCorrect && greenCorrect && blueCorrect)
  {
    correctAnswer();
    redCorrect = false;
    greenCorrect = false;
    blueCorrect = false;
    setRandomColorAnswer();
  }
}

void setUserColor(int red, int green, int blue)
{
  analogWrite(r1,red);
  analogWrite(g1,green);
  analogWrite(b1,blue);
}
 
void setGuessColor(int red, int green, int blue)
{
  analogWrite(r2, red);
  analogWrite(g2, green);
  analogWrite(b2, blue);  
}

void setRandomColorAnswer()
{
  redAnswer = random(-180,255);
  greenAnswer = random(-180,255);
  blueAnswer = random(-180,255);
  
  int possibleWhite = 0;
  
  if(redAnswer < 0)
  {
    redAnswer = 0;
  }
  else if(redAnswer > 200)
  {
    possibleWhite++;
  }
  if(greenAnswer < 0)
  {
    greenAnswer = 0;
  }
  else if(greenAnswer > 200)
  {
    possibleWhite++;
  }
  if(blueAnswer < 0)
  {
    blueAnswer = 0;
  }
  else if(blueAnswer > 200)
  {
    possibleWhite++;
  }

  if(possibleWhite == 3)
  {
    int randomColorToZero = random(0,2);
    
    switch(randomColorToZero)
    {
      case 0: redAnswer = 0; break;
      case 1: greenAnswer = 0; break;
      case 2: blueAnswer = 0; break;
      default: break;
    }
  }
}

void correctAnswer()
{
    setUserColor(0,255,0);
    setGuessColor(0,255,0);
    delay(1000);
    setUserColor(0,0,0);
    setGuessColor(0,0,0);
    delay(1000);
    setUserColor(0,255,0);
    setGuessColor(0,255,0);
    delay(1000);
    setUserColor(0,0,0);
    setGuessColor(0,0,0);
    delay(1000);
    setUserColor(0,255,0);
    setGuessColor(0,255,0);
    delay(1000);
    setUserColor(0,0,0);
    setGuessColor(0,0,0);
    delay(1000);
}
