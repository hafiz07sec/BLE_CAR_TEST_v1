

char cmd;
#define inA 9
#define inB 10
#define inC 7
#define inD 8
#define ena 11
#define enb 6

void wheel(int lm, int rm);
int base_L = 200;
int base_R = 200;

void setup()
{
  //mySerial.begin(9600);
  Serial.begin(9600);

  mot_init();

}

void mot_init()
{
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(inC, OUTPUT);
  pinMode(inD, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  digitalWrite(inA, HIGH);
  digitalWrite(inB, HIGH);
  digitalWrite(inC, HIGH);
  digitalWrite(inD, HIGH);
}

void loop()
{
  /// motor_test();
if(Serial.available()>0)
{
  cmd = Serial.read();
  Serial.println(cmd);
  RC_CAR();
}
}

void RC_CAR()
{
  
    wheel(0, 0);
    switch (cmd) {
      case 'F':
        wheel(base_L, base_R);
        break;
      case 'B':
        wheel(-base_L, -base_R);
        break;
      case 'R':
        wheel(base_L, -base_R);
        break;
      case 'L':
        wheel(-base_L, base_R);
        break;
      case 'G':
        wheel(base_L - 100, base_R);
        break;
      case 'I':
        wheel(base_L, base_R - 100);
        break;
      case 'S':
        wheel(0, 0);
        break;
      case 'H':
        wheel(-base_L + 100, -base_R);
        break;
      case 'J':
        wheel(-base_L, -base_R + 100);
        break;
      case 'V':
        digitalWrite(13, HIGH);
        Serial.println("horn");
       
        break;
      case 'v':
        digitalWrite(13, LOW);
       // delay(100);
        break;
      
    
  }
}

void wheel(int lm, int rm)
{
  if (lm == 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, HIGH);
  }
  if (lm > 0)
  {
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
  }
  else if (lm < 0)
  {
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
  }


  if (rm == 0)
  {
    digitalWrite(inC, HIGH);
    digitalWrite(inD, HIGH);
  }
  if (rm > 0)
  {
    digitalWrite(inC, HIGH);
    digitalWrite(inD, LOW);
  }
  else if (rm < 0)
  {
    digitalWrite(inC, LOW);
    digitalWrite(inD, HIGH);
  }
  if (lm > 254) lm = 254;
  if (lm < -254) lm = -254;
  if (rm > 254) rm = 254;
  if (rm < -254) rm = -254;
  analogWrite(ena, abs(rm));
  analogWrite(enb, abs(lm));

}

void motor_test()
{
  wheel(200, 200);
  delay(5000);
  wheel(0, 0);
  delay(1000);

  wheel(200, -200);
  delay(5000);
  wheel(0, 0);
  delay(1000);

  wheel(-200, 200);
  delay(5000);
  wheel(0, 0);
  delay(1000);

  wheel(-200, -200);
  delay(5000);
  wheel(0, 0);
  delay(1000);
}
