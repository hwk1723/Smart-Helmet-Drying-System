#include <Bonezegei_HCSR04.h>

const int TRIGGER_PIN = 10;
const int ECHO_PIN = 11;
bool flag = false;
int counter = 0;

Bonezegei_HCSR04 ultrasonic(TRIGGER_PIN, ECHO_PIN);

void setup() {
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  digitalWrite(5, HIGH);
}

void loop() {
  int d = ultrasonic.getDistance();
    Serial.println(d);
  if (d <= 25 && flag == false){
    if(counter >= 5){
      Serial.println("Helmet detected!");
      Serial.println("Fan on");
      digitalWrite(7, HIGH);
      delay(600000); // 10-minutes
      // delay(5000);
      Serial.println("Fan off");
      digitalWrite(7, LOW);
      flag = true;
      counter = 0;
    }
    counter += 1;
  }
  else if (d > 25 && flag == true){
    flag = false;
    counter = 0;
  }
  else{
    Serial.println("Do nothing...");
    counter = 0;
  }
  delay(2000);
}
