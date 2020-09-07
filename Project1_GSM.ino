#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10); //tx,rx;
void setup() {
  pinMode(7,OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  float sensorVoltage;                           
  float sensorValue;   
  sensorValue = analogRead(A0); 
  sensorVoltage = sensorValue/1024*5.0;  
  /*if(Serial.available() > 0)
    switch(Serial.read()) {
      case 's':
        SendMe ssage();
        break;
       case 'c':
        makeCall();
        break;
    }*/
    Serial.println(sensorVoltage);
    delay(2000);
    if(sensorVoltage > 1.5) {
      buzzer();
      SendMessage1();
      delay(1000);
      SendMessage2();
      delay(5000);
      makeCall1();
      delay(100000);
      makeCall2();
      delay(100000);
      }
    //if(mySerial.available() > 0)
      //Serial.write(mySerial.read());
}

void SendMessage1() {
  mySerial.println("AT+CMGF=1\r");
  delay(1000);
  mySerial.println("AT+CMGS=\"+918464097939\"\r");
  delay(1000);
  mySerial.println("Gas is leaking.....");
  Serial.println("Message Sent...");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
void SendMessage2() {
  mySerial.println("AT+CMGF=1\r");
  delay(1000);
  mySerial.println("AT+CMGS=\"+917893070686\"\r");
  delay(1000);
  mySerial.println("Gas is leaking.....");
  Serial.println("Message Sent...");
  delay(100);
  mySerial.println((char)26);
  delay(1000);
}
void makeCall1(){
  mySerial.println("ATD+918464097939;");
  Serial.println("Calling...");
  delay(10000);
}
void makeCall2(){
  mySerial.println("ATD+917893070686;");
  Serial.println("Calling...");
  delay(10000);
}
void buzzer() {
  digitalWrite(7,HIGH);
  delay(1000);
  Serial.println("Buzzed..");
  digitalWrite(7,LOW);
}
