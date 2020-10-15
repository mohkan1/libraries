#include <Servo.h>
Servo servoLeft;
Servo servoRight;
void setup()
{
  pinMode(10, INPUT); pinMode(9, OUTPUT);
  pinMode(13, INPUT); pinMode(2, OUTPUT);
  tone(4, 3000, 1000);
  delay(1000);
  Serial.begin(9600);
  servoLeft.attach(13);
  servoRight.attach(12);
}
void loop()
{

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
  
  if ((irRight == 0) && (irLeft == 1))
  {
    Serial.print("Forward");
    forward(20);
  }
  else if ((irRight == 1) && (irLeft == 1))
  {
    Serial.print("turnright");
    turnright(3500);
  }
  else if ((irRight == 0) && (irLeft == 0))
  {
    turnleft(3500);
    Serial.print("turnleft");
  }else if ((irRight == 1) && (irLeft == 0))
  {
    turnleft(3500);
  }else if (volts(A3) < 1.5)
  {
    Serial.print(volts(A3));
    servoLeft.detach();
    servoRight.detach();
  }
  Serial.println(volts(A3));
  Serial.println("light value");
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
float volts(int adPin)
{
  
  return float(analogRead(adPin)) * 5.0 / 1024.0;
  
}
int irDetect(int irLedPin, int irReceiverPin, long frequency)
{
  tone(irLedPin, frequency, 8);
  delay(1);
  int ir = digitalRead(irReceiverPin);
  delay(1);
  return ir;
}
void forward(int time)
{
  servoLeft.writeMicroseconds(1550);
  servoRight.writeMicroseconds(1450);
  delay(time);
}
void turnright(int time)
{
  servoLeft.writeMicroseconds(1520);
  servoRight.writeMicroseconds(1520);
  delay(time);
}
void turnleft(int time)
{


  servoLeft.writeMicroseconds(1480);
  servoRight.writeMicroseconds(1480);
  delay(time);
}

/*  else if (volts(A3) > 1.5)
  {
    servoLeft.detach();
    servoRight.detach();
  }
*/
