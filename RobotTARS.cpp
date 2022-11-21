#define MotorRight1 7
#define MotorRight2 12
#define MotorLeft1 2
#define MotorLeft2 4
//#define MotorRightSpeed 9
//#define MotorLeftSpeed 10

#include <Servo.h>
Servo CraneWars1;
Servo CraneWars2;
//int Speed = 150;
char command;
void setup() 
{
  // put your setup code here, to run once:
  pinMode(MotorLeft1, OUTPUT);
  pinMode(MotorLeft2, OUTPUT);
  pinMode(MotorRight1, OUTPUT);
  pinMode(MotorRight2, OUTPUT);
//  pinMode(MotorRightSpeed, OUTPUT);
//  pinMode(MotorLeftSpeed, OUTPUT);
  Serial.begin(9600);
  CraneWars1.attach(5);
  CraneWars2.attach(10);
  CraneWars1.write(-20);
  CraneWars2.write(-100);
}

void loop() 
{
  if(Serial.available())
  {
    command = Serial.read();
  }
  //analogWrite(MotorRightSpeed, Speed);
  //analogWrite(MotorLeftSpeed, Speed);
  if(command == 'S')
  {
    Stop();
  }
  if(command == 'F')
  {
    Forward();
  }
  if(command == 'B')
  {
    Backward();
  }
  if(command == 'L')
  {
    Right();
  }
  if(command == 'R')
  {
    Left();
  }
  if(command == 'X') //Angle button on
  {
    CraneWars1.write(63); 
    delay(500);
  }
  if(command == 'x') //Angle button off
  {
    CraneWars1.write(-40);
    delay(500);
  }
  if(command == 'U')
  {
    CraneWars2.write(18); 
    delay(500);
  }
  if(command == 'u')
  {
    CraneWars2.write(-100);
    delay(500);
  }
}

void Forward()
{
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);
}

void Backward()
{
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, HIGH);
}

void Stop()
{
  digitalWrite(MotorRight1, LOW);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, LOW);
  digitalWrite(MotorLeft2, LOW);
}

void Right()
{
  digitalWrite(MotorRight1, HIGH);
  digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorLeft1, LOW);
  //digitalWrite(MotorLeft2, LOW);
  digitalWrite(MotorLeft2, HIGH);
}

void Left()
{
  digitalWrite(MotorRight1, LOW);
  //digitalWrite(MotorRight2, LOW);
  digitalWrite(MotorRight2, HIGH);
  digitalWrite(MotorLeft1, HIGH);
  digitalWrite(MotorLeft2, LOW);
}
