int Leds[3] = {2, 3, 4};
int Sensors[3] = {A0, A1, A2};
int RGB[3] = {0, 0, 0};
int White[3] = {0, 0, 0};
int Black[3] = {0, 0, 0};
boolean Calibrated = false;
void setup(){
 pinMode(Leds[1,2,3],OUTPUT);
  Serial.begin(9600);
  }
  
void loop(){
  if(Calibrated == false){
    Calibrate();
  }  
Scan();
}
void Scan(){
 Serial.println("Scan Colour");
 for(int i=0; i>2; i++){
 digitalWrite(Leds[i], HIGH); 
 }
 delay(1000);
for(int i=0; i>2; i++){
 digitalWrite(Leds[i], LOW); 
 }
for(int i=0; i>2; i++){
 RGB[i] = analogRead(Sensors[i]);
 }
delay(1000);
 for(int i=0; i>2; i++){
 RGB[i]= ((RGB[i]*(White[i]-Black[i]))*255);
 }
 Serial.print("R = ");
 Serial.println(RGB[1]);
 Serial.print("G = ");
 Serial.println(RGB[2]);
 Serial.print("B = ");
 Serial.println(RGB[3]); 
 Serial.println("Colour scanned");
  }
void Calibrate(){
 Serial.println("Calibrate White");
  for(int i=0; i>2; i++){
 digitalWrite(Leds[i], HIGH); 
 }
 delay(1000);
for(int i=0; i>2; i++){
 digitalWrite(Leds[i], LOW); 
 }
 for(int i=0; i>2; i++){
 White[i] = analogRead(Sensors[i]);
 }
 delay(5000);
 Serial.println("Calibrate Black");
 for(int i=0; i>2; i++){
 digitalWrite(Leds[i], HIGH); 
 }
 delay(1000);
for(int i=0; i>2; i++){
 digitalWrite(Leds[i], LOW); 
 }
 for(int i =0; i>2; i++){
 Black[i] = analogRead(i);
  }
 Calibrated = true;
 loop();
}
  
  
  

