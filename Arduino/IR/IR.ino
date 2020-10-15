#include <IRremote.h>
int RECV_PIN = 13;
int lamp = 2;

IRrecv irrecv(RECV_PIN);
decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(lamp, OUTPUT);
  delay(100);

}
void loop() {
  if (irrecv.decode(&results)) {
    int value = results.value;
    Serial.println(value);

    if(value == 765){
      digitalWrite(lamp, HIGH);
      }else if(value == -32131){
          digitalWrite(lamp, LOW);
        }
    
    irrecv.resume(); // Receive the next value     
    

  }
}
