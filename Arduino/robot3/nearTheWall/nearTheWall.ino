#include <Servo.h>
Servo left;
Servo right;


void setup()
{
  tone(4, 3000, 1000);
  delay(1000);
  Serial.begin(9600);
  left.attach(13);
  right.attach(12);
}

void loop()
{
  go();

}

void go() {

  long tLeft = rcTime(8);
  long tRight = rcTime(6);

  Serial.print("tLeft = ");
  Serial.print(tLeft);
  Serial.print("us  --- ");

  Serial.print("tRight = ");
  Serial.print(tRight);
  Serial.println(" us");


  int irLeft = irDetect(9, 10, 38000);
  int irRight = irDetect(2, 3, 38000);

  Serial.println(irLeft);
  Serial.println(irRight);

  if (irRight == 0 && irLeft == 1) { 
    Serial.print("forward");
    moveForward(20);

  } else if (irRight == 0 && irLeft == 0) { 
    Serial.print("turnleft");
    turnleft(35);

  } else if (irRight == 1 && irLeft == 1) {
    Serial.print("turnright");
    turnright(35);

  }




  delay(100);

}

long rcTime(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(1);
  pinMode(pin, INPUT);
  digitalWrite(pin, LOW);
  long time  = micros();
  while (digitalRead(pin));
  time = micros() - time;
  return time;
}



void moveForward(int time)
{


  left.writeMicroseconds(1550);
  right.writeMicroseconds(1450);
  delay(time);

}


void turnleft(int time)
{

  left.writeMicroseconds(1480);
  right.writeMicroseconds(1480);
  delay(time);

}

void turnright(int time)
{
  left.writeMicroseconds(1520);
  right.writeMicroseconds(1520);
  delay(time);
}

int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);
  delay(1);
  int ir = digitalRead(irReceiverPin);
  delay(1);
  return ir;
}
