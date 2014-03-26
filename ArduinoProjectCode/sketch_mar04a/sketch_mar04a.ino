int Leds[3] = {7, 2, 3}; //the leds that will scan the colour
int Indicator[3]={4, 5, 6}; //leds that indicate which stage of the process you are on
int Sensors[3] = {A2, A1, A0}; //sensors used in the scanning
int RGB[3] = {0, 0, 0}; //Array stores the sensor readings for the colour
int White[3] = {0, 0, 0};// array stores the white balance reading 
int Black[3] = {0, 0, 0}; // Stores the Black balance readings
int WhiteHolder = 1023;
int BlackHolder =1023;
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
 delay(10000); //Longer delay allows users to see result of scan before scanning starts again

}
  //Scan Function scans and converts the RGB values
void Scan(){
 Serial.println("Scan Colour"); //Tells user to scan Colour
 digitalWrite(Indicator[2],HIGH); //Sets the indication pin to say scanning has started
//as the pins are different brightnessess this evens them out so the reading is correct
 analogWrite(Leds[0], 400);
 /*
 The LEDs all have a different brightness when using digitalWrite(Leds[i], HIGH).
 This then interferes with the colour detection so by using analogWrite(leds[0], Value).
 We are able to equal out the brightness of the leds
 */
 analogWrite(Leds[1], 1500); //turn on scanning pins
 analogWrite(Leds[2], 20); //turn on scanning pins
  delay(1000);//wait 1 sec
for(int i=0; i<3; i++){
  RGB[i] = analogRead(Sensors[i]); //Read sensor values
  digitalWrite(Leds[i], LOW); //Turn Off scanning Pins
 }
delay(1000); //delay allows for system and user to re-sync 
 for(int i=0; i<3; i++){
 int Range = White[i] - Black[i]; //This moves the scale from Black[i] to white[i] to have a base 0 with scale.
 RGB[i] = ((RGB[i]-Black[i])/(Range)*255);
 /*
 By taking the Black away from the colour we adjust for the white balance. 
 By timsing the range by 255 we bring it on the Scale.
 Dividing the 2 brings the RGB[] scanned value into the range.
 */
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
 delay(1000); //Delay for user to set white card
 //as the pins are different brightnessess this evens them out so the reading is correct
 analogWrite(Leds[0], 400); //turn on scanning pins
 analogWrite(Leds[1], 1500); //turn on scanning pins
 analogWrite(Leds[2], 20); //turn on scanning pins
 delay(1000);
for(int i=0; i<3; i++){
 White[i] = analogRead(Sensors[i]); //Reads the sensor values and stores in the Array
 digitalWrite(Leds[i], LOW);//Turns Leds off 
}
 for(int i=0; i<3; i++){
 Serial.println(White[i]); //Prints only for testing 
 }
 delay(5000); //Allows user to place black card
 Serial.println("Calibrate Black");
 digitalWrite(Indicator[1],HIGH);
 delay(1000); //Delay to allow user to set black card
//as the pins are different brightnessess this evens them out so the reading is correct
 analogWrite(Leds[0], 400); //turn on scanning pins
 analogWrite(Leds[1], 1500); //turn on scanning pins
 analogWrite(Leds[2], 20); //turn on scanning pins
 delay(1000);
for(int i=0; i<3; i++){
  Black[i] = analogRead(Sensors[i]); //Reads the sensor values and stores them into an array
  digitalWrite(Leds[i], LOW);  //LEDs off
   }
  for(int i=0; i<3; i++){
 Serial.println(Black[i]); //Testing Purposes. prints the black value so the algorithm can be hand implimented 
  }
 delay(10000);
 Calibrated = true; //sets calibrated to true to skip the calibration process for the rest of the session
}
