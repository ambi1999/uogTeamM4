int RedLed = 2;
int GreenLed = 3;
int BlueLed = 4;
int RedSensor = A0;
int GreenSensor = A1;
int BlueSensor = A2;
int Red = 0;
int Green = 0;
int Blue = 0;
int WhiteRed = 0;
int WhiteGreen = 0;
int WhiteBlue = 0;
int BlackRed = 0;
int BlackGreen = 0;
int BlackBlue = 0;
boolean Calibrated = false;
void setup(){
 pinMode(RedLed,OUTPUT);
 pinMode(GreenLed,OUTPUT);
 pinMode(BlueLed,OUTPUT);
 Serial.begin(9600);
  }
  
void loop(){
  if(Calibrated == false){
    Calibrate();
  }  
Scan();
}
void Scan(){
 digitalWrite(RedLed, HIGH); 
 digitalWrite(GreenLed, HIGH);
 digitalWrite(BlueLed, HIGH);
 delay(1000);
 digitalWrite(RedLed, LOW); 
 digitalWrite(GreenLed, LOW);
 digitalWrite(BlueLed, LOW);
 Red = analogRead(RedSensor);
 Green = analogRead(GreenSensor);
 Blue = analogRead(BlueSensor);
 Red=((Red-(WhiteRed-BlackRed))*255);
 Green=((Green-(WhiteGreen-BlackGreen))*255);
 Blue= ((Blue- (WhiteBlue-BlackGreen))*255);
 Serial.print("R = ");
 Serial.println(Red);
 Serial.print("G = ");
 Serial.println(Green);
 Serial.print("B = ");
 Serial.println(Blue); 
  }
void Calibrate(){
 Serial.print("Calibrate White");
 digitalWrite(RedLed, HIGH); 
 digitalWrite(GreenLed, HIGH);
 digitalWrite(BlueLed, HIGH);
 delay(1000);
 digitalWrite(RedLed, LOW); 
 digitalWrite(GreenLed, LOW);
 digitalWrite(BlueLed, LOW);
 WhiteRed = analogRead(RedSensor);
 WhiteGreen = analogRead(GreenSensor);
 WhiteBlue = analogRead(BlueSensor);
 delay(5000);
 Serial.print("Calibrate Black");
 digitalWrite(RedLed, HIGH); 
 digitalWrite(GreenLed, HIGH);
 digitalWrite(BlueLed, HIGH);
 delay(1000);
 digitalWrite(RedLed, LOW); 
 digitalWrite(GreenLed, LOW);
 digitalWrite(BlueLed, LOW);
 BlackRed = analogRead(RedSensor);
 BlackGreen = analogRead(GreenSensor);
 BlackBlue = analogRead(BlueSensor); 
 Calibrated = true;
 loop();
}
  
  
  
