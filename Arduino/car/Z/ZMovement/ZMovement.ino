#include <Servo.h>
Servo left;
Servo right;
int bass[] = {2093,2349,2637,1319,1047,1147,1760,1976, 1397,1568};

void setup() {
 moveForward(); 
  turnleft();
  
  moveDiagonal();
  
  turnright(); 
  moveForward();
   
  dropTheBass();
  rotate();
  
  moveForward();
  turnleft();
  
  moveDiagonal();
  turnright();
  moveForward();
}

void loop() {
  
}



void moveForward()
{
  left.attach(13);
  right.attach(12);
  for(int speed = 0; speed < 200; speed += 2)   
  {    
    left.writeMicroseconds(1500-speed);   
    right.writeMicroseconds(1500+speed);  
    delay(20);                                 
  }  
  delay(250);                                 
  for(int speed = 200; speed < 0; speed -= 2) 
  {    
    left.writeMicroseconds(1500-speed);   
    right.writeMicroseconds(1500+speed);
    delay(20);                                
  }  
  left.detach();                          
  right.detach();
}

void moveDiagonal()
{
  left.attach(13);
  right.attach(12);
  for(int speed = 0; speed <= 100; speed += 2)   
  {    
    left.writeMicroseconds(1500-speed);   
    right.writeMicroseconds(1500+speed);  
    delay(20);                                 
  }  
  delay(2500);                                 
  for(int speed = 100; speed >= 0; speed -= 2) 
  {    
    left.writeMicroseconds(1500-speed);   
    right.writeMicroseconds(1500+speed);
    delay(20);                                
  }  
  left.detach();                          
  right.detach();
}

void turnright()
{
  left.attach(13);
  right.attach(12);
  for(int speed = 0; speed <= 100; speed += 2)
  {
    left.writeMicroseconds(1500-speed);  
    right.writeMicroseconds(1500-speed);  
    delay(20);
  }
  delay(150);
}

void turnleft()
{
  left.attach(13);
  right.attach(12);
  for(int speed = 0; speed <= 100; speed += 2)  
  {
    left.writeMicroseconds(1500+speed);  
    right.writeMicroseconds(1500+speed);  
    delay(20);
  }   
  delay(200);
}
  

void dropTheBass()
{
  int elementCount = sizeof(bass) / sizeof(int);
  for (int index = 0; index < elementCount; index++)
  {
    tone(4, bass[index], 500);  
    delay(600);
  }
}

void rotate()
{
  left.attach(13);
  right.attach(12);
  for(int speed = 0; speed <= 100; speed += 2)  
  {
    left.writeMicroseconds(1500-speed);  
    right.writeMicroseconds(1500-speed);  
    delay(38);
  }
  delay(20);     
}
