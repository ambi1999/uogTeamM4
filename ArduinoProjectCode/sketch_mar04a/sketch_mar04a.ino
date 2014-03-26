int Leds[3] = {7, 2, 3}; //the leds that will scan the colour
int Indicator[3]={4, 5, 6}; //leds that indicate which stage of the process you are on
int Sensors[3] = {A2, A1, A0}; //sensors used in the scanning
int RGB[3] = {0, 0, 0}; //Array stores the sensor readings for the colour
int White[3] = {0, 0, 0};// array stores the white balance reading 
int Black[3] = {0, 0, 0}; // Stores the Black balance readings
boolean Calibrated = false;
void setup(){
 //setting all the led pins as outputs
 pinMode(Leds[0],OUTPUT);
 pinMode(Leds[1],OUTPUT);
 pinMode(Leds[2],OUTPUT);
 
 pinMode(Indicator[0],OUTPUT);
 pinMode(Indicator[1],OUTPUT);
 pinMode(Indicator[2],OUTPUT);
  //Starting serial communication
 Serial.begin(9600);
  }
  
void loop(){
  delay(5000); //Delay allows for user to prepare the correct cards 
  if(Calibrated == false){ //checks if the system has been  calibrated
    Calibrate(); //If not sends to Calibrate function
  }  
 Scan();//if has sends to scan function
 delay(60000); //Longer delay allows users to see result of scan before scanning starts again
}
 

  //Scan Function scans and converts the RGB values
void Scan(){
 Serial.println("Scan Colour"); //Tells user to scan Colour
 digitalWrite(Indicator[2],HIGH); //Sets the indication pin to say scanning has started
 for(int i=0; i<3; i++){ //As the Arrays have 3 sets of values the for loop starts at 0 and +1 every iteration until  and including 2
 digitalWrite(Leds[i], HIGH); //turn on scanning pins
 }
 delay(1000);//wait 1 sec
for(int i=0; i<3; i++){
 digitalWrite(Leds[i], LOW); //Turn Off scanning Pins 
 }
for(int i=0; i<3; i++){
 RGB[i] = analogRead(Sensors[i]); //Read sensor values
 }
delay(1000); //delay allows for system and user to re-sync 
for(int i=0; i<3; i++){
   int Boundary = White[i] -Black[i] //Setting the black value as the 0 point by taking it off the white to move the scale to start at 0
   int range = Boundary/255 //using Boundary as the maximum value of reflection we divide by 255 to gain the ratio value
   RGB[i] = (RGB[i] / range); //Dividing by the range then gives use the value for the colour inside the RGB scale
   if (RGB[i]>255){ //If the RGB Value is outside 255 the if sets it back to 255
   RGB[i]=255;
   }
   if (RGB[i]<0){ // If the RGB value is below 0 the if sets it back to 0
   RGB[i]=0;
   }
  }
 Serial.print("R = ");
 Serial.println(RGB[0]); //Prints the Array Values. Red
 Serial.print("G = ");
 Serial.println(RGB[1]); //Green
 Serial.print("B = ");
 Serial.println(RGB[2]); //Blue
 Serial.println("Colour scanned");
  }
  
  //this function is scanning the White and Black values for Calibration 
void Calibrate(){
 Serial.println("Calibrate White");
 digitalWrite(Indicator[0],HIGH); //Tells the user which stage the processes is at
 delay(1000) //Delay for user to set white card
  for(int i=0; i<3; i++){
 digitalWrite(Leds[i], HIGH); //Turns the LEDs
 }
 delay(1000);
for(int i=0; i<3; i++){
 digitalWrite(Leds[i], LOW);//Turns Leds off  
 White[i] = analogRead(Sensors[i]); //Reads the sensor values and stores in the Array
 }
 
 for(int i=0; i<3; i++){
 Serial.println(White[i]); //Prints only for testing 
 }
 delay(5000); //Allows user to place black card
 Serial.println("Calibrate Black");
 digitalWrite(Indicator[1],HIGH);
 delay(1000) //Delay to allow user to set black card
 for(int i=0; i<3; i++){
 digitalWrite(Leds[i], HIGH); //LEDs on
 }
 delay(1000);
for(int i=0; i<3; i++){
 digitalWrite(Leds[i], LOW);  //LEDs off
 Black[i] = analogRead(Sensors[i]); //Reads the sensor values and stores them into an array
 }
  for(int i=0; i<3; i++){
 Serial.println(Black[i]); //Testing Purposes
  }
 delay(10000);
 Calibrated = true; //sets calibrated to true to skip the calibration process for the rest of the session
}
//Comment 
