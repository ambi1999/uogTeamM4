// LED pins
int ledArray[] = {2,3,4};

// boolean to know if the balance has been set
boolean balanceSet = false;

//place holders for colour
//const int buttonPin = 4;
int red = 0;
int green = 0;
int blue = 0;
int buttonState = 0;

float colourArray[] = {0,0,0};
float whiteArray[] = {0,0,0};
float blackArray[] = {0,0,0};



int avgRead;

void setup(){
 
  //pinMode(buttonPin, INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
 
}

void loop(){
   //buttonState = digitalRead(buttonPin);
   //if (buttonState == HIGH) {  
    checkBalance(); 
    checkColour();
    printColour();
   //}
      
    }

void checkBalance(){
  
  if(balanceSet == false){
    setBalance();
  }
}

void setBalance(){
  //set white balance
   delay(5000);                             
  for(int i = 0;i<=2;i++){
     digitalWrite(ledArray[i],HIGH);
     delay(100);
     getReading(5);         
     whiteArray[i] = avgRead;
     digitalWrite(ledArray[i],LOW);
     delay(100);
  }
   //set black balance
    delay(5000);             
  for(int i = 0;i<=2;i++){
     digitalWrite(ledArray[i],HIGH);
     delay(100);
     getReading(5);
     blackArray[i] = avgRead;
     //blackArray[i] = analogRead(2);
     digitalWrite(ledArray[i],LOW);
     delay(100);
  }
  balanceSet = true;
  
  delay(5000);
  }

void checkColour(){
    for(int i = 0;i<=2;i++){
     digitalWrite(ledArray[i],HIGH);  
     delay(100);                      
     getReading(5);                  
     colourArray[i] = avgRead;        
     float greyDiff = whiteArray[i] - blackArray[i];                    
     colourArray[i] = (colourArray[i] - blackArray[i])/(greyDiff)*255; 
     digitalWrite(ledArray[i],LOW);   
     delay(100);
  }
}
void getReading(int times){
  int reading;
  int tally=0;
 
for(int i = 0;i < times;i++){
   reading = analogRead(0);
   tally = reading + tally;
   delay(10);
}

avgRead = (tally)/times;
}


void printColour(){
Serial.print("R = ");
Serial.println(int(colourArray[0]));
Serial.print("G = ");
Serial.println(int(colourArray[1]));
Serial.print("B = ");
Serial.println(int(colourArray[2]));
//delay(2000);
}

