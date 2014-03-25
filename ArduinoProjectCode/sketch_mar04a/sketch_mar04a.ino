int Leds[3] = {7, 2, 3};
int Indicator[3]={4, 5, 6};
int Sensors[3] = {A2, A1, A0};
int RGB[3] = {0, 0, 0};
int White[3] = {0, 0, 0};
int Black[3] = {0, 0, 0};
boolean Calibrated = false;
void setup(){
 
 pinMode(Leds[0],OUTPUT);
 pinMode(Leds[1],OUTPUT);
 pinMode(Leds[2],OUTPUT);
 
 pinMode(Indicator[0],OUTPUT);
 pinMode(Indicator[1],OUTPUT);
 pinMode(Indicator[2],OUTPUT);
  
 Serial.begin(9600);
  }
  
void loop(){
    
  if(Calibrated == false){
    Calibrate();
  }  
  Scan();
}


  //comment
void Scan(){
 Serial.println("Scan Colour");
 digitalWrite(Indicator[2],HIGH);
 for(int i=0; i<3; i++){
 digitalWrite(Leds[i], HIGH); 
 }
 delay(1000);
for(int i=0; i<3; i++){
 digitalWrite(Leds[i], LOW); 
 }
for(int i=0; i<3; i++){
 RGB[i] = analogRead(Sensors[i]);
 }
delay(1000);
 for(int i=0; i<3; i++){
 RGB[i]= ((RGB[i]*(White[i]-Black[i]))*255);
 }
// Serial.print("R = ");
 Serial.println(RGB[0]);
// Serial.print("G = ");
 Serial.println(RGB[1]);
 //Serial.print("B = ");
 Serial.println(RGB[2]); 
 //Serial.println("Colour scanned");
  }
  
  //this function is doing xyz
void Calibrate(){
 Serial.println("Calibrate White");
 digitalWrite(Indicator[0],HIGH);
  for(int i=0; i<3; i++){
 digitalWrite(Leds[i], HIGH); 
 }
 delay(1000);
for(int i=0; i<3; i++){
 digitalWrite(Leds[i], LOW); 
 White[i] = analogRead(Sensors[i]);
 }
 delay(5000);
 Serial.println("Calibrate Black");
 digitalWrite(Indicator[1],HIGH);
 for(int i=0; i<3; i++){
 digitalWrite(Leds[i], HIGH); 
 }
 delay(1000);
for(int i=0; i<3; i++){
 digitalWrite(Leds[i], LOW); 
 Black[i] = analogRead(i);
 }
 Calibrated = true;
}
