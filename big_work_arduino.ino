#include<stdio.h>
#include <Servo.h>
Servo mServo;
int mAngleNum = 0;
char mFront = 0;
const int mTrigPin = 2;
const int mEchoPin = 3;
int mDistance = 0;

void sendStatusToSerial();
void ranging();

void setup() {
  Serial.begin(9600);
  mServo.attach(6);
  pinMode(mTrigPin, OUTPUT);
  pinMode(mEchoPin, INPUT);
  pinMode(11, OUTPUT  );
  pinMode(9, OUTPUT  );
  pinMode(10, OUTPUT  );
}

void loop() {
  mServo.write(180 - mAngleNum);
  ranging();
  sendStatusToSerial();
  delay(60);

  if ( mFront == 0 )
  {
    mAngleNum ++;
    if ( mAngleNum > 180 )
    {
      mFront = 1;
    }
  }
  else
  {
    mAngleNum --;
    if ( mAngleNum < 0 )
    {
      mFront = 0;
    }
  }
  digitalWrite(11, 0);
  digitalWrite(9, 0);
  digitalWrite(10, 0);


  if (mDistance <= 50) {
    analogWrite(11, 255);
  }
  if (mDistance > 50 && mDistance <= 100) {
    analogWrite(9, 255);
  }
  if (mDistance > 100 && mDistance < 150 ) {
    analogWrite(10, 255);
  }
}


void sendStatusToSerial()
{
  char mAngleStr[5];
  char mDistanceStr[5];
  sprintf( mAngleStr, "%d", mAngleNum);
  sprintf( mDistanceStr, "%d", mDistance);
  delayMicroseconds(2);
  Serial.print( "<" );
  Serial.print(mAngleStr);
  Serial.print("|");
  Serial.print(mDistanceStr);
  Serial.print( ">" );
  Serial.println();
  delayMicroseconds(2);
}

void ranging()
{

  digitalWrite(mTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(mTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(mTrigPin, LOW);

  mDistance = pulseIn(mEchoPin, HIGH) / 58.0;

}
