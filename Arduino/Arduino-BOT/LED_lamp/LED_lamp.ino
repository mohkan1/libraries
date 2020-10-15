int lamp = 2;

static int order[] = {1000,1000,1000,2000,2000,2000,1000,1000,1000};
int number = sizeof(order)/2;



void blinkLED(int input, int timeOfTheLightning[]) {
  for (int x = 0; x < number; x++) {
    digitalWrite(input, HIGH);
    Serial.print(timeOfTheLightning[x]);
    Serial.print(" ");
    delay(timeOfTheLightning[x]);
    digitalWrite(input, LOW);
    delay(1000);
  }
}

void lampOrder() {
  for (int x = 0; x < 3; x++) {
    blinkLED(lamp, order);
    delay(1000);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lamp, OUTPUT);
  lampOrder();
  delay(1000);

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
