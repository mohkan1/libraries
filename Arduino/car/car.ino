#include <servo.h>

int servoPin = 3;
int LED = 2
int note[] = {
    1,
    2,
    3,
    4
  };

  
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(LED, OUTPUT)
}


void loop() {
  // put your main code here, to run repeatedly:

}
