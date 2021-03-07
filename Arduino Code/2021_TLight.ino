/*
authors: Gindember Diaz, Edwin ZepedaVidal
Date: March 7,2021
EECE.4250
Section 201
Laboratory 1: Traffic Light Controller
*/

int ledGreen = 13;      //Green LED assigned to pin 13
int ledYellow = 12;     //Yellow LED assigned to pin 12
int ledRed = 11;        //Red LED assigned to pin 11

int buzzer = 5;         //Buzzer assigned to pin 5

int pushButton = 3;     //pushButtton assigned to pin 3;
int buttonState;        //Button State used for intial debugging. (outputs 1 when pushed, 0 when not)

void setup() {
  
  Serial.begin(9600);

  pinMode(ledGreen,OUTPUT);     //Assigns the pins that that the LEDs are connected as OUTPUT
  pinMode(ledYellow,OUTPUT);    //Allowing for the ouput of voltage turning on LEDs
  pinMode(ledRed,OUTPUT);
  pinMode(pushButton,INPUT);    //Assigns the pin for pushbutton as input, 
  pinMode(buzzer,OUTPUT);       //Same as LED but with passive buzzer

buttonState = digitalRead(pushButton);    //assigns buttonState as the staus of pushButton(Pin 3)
delay(1);                                 //button state need to intialize the the traffic light loop.
Serial.println(buttonState);      //Outputs State of buttonState (should output "0" intial) used for debugging


while(buttonState == 0)           //While loop until button pressed, when pressed buttonstate = 1
{
    digitalWrite(ledRed,HIGH);    //The following code is for the intial state of light
    delay(500);                   //The Red LED will flash until the button is pushed
    digitalWrite(ledRed,LOW);
    delay(500);
    digitalWrite(ledRed,HIGH);
    delay(500);
    buttonState = digitalRead(pushButton);      //reading the state of pushButton, thus used for debugging
    delay(1);
    Serial.println(buttonState);                //Same as before outputs state of buttonState, used for debugging
   
}
//While done, because of the location of the digital read of pushButton, The Red LED left on when the pushbutton is pushed
//Which is what is required, when the button is push the traffic light pattern starts, R-G-Y, RED-GREEN-YELLOW

delay(12000) ;                  //Red Led on for 12 seconds
digitalWrite(buzzer,HIGH);      //Buzzer turns for 3 seconds before light changes, 12+3 = 15, Red LED on for total of 15 seconds
delay(3000);                    //Delay for 3 the time buzzer will be on.
digitalWrite(buzzer,LOW);       //Red LED off
digitalWrite(ledRed,LOW);       //Buzzer off
}

//This is the infinate loop for the R-G-Y pattern

void loop() {
    digitalWrite(ledGreen,HIGH);
    delay(12000);
    digitalWrite(buzzer,HIGH);
    delay(3000);
    digitalWrite(buzzer,LOW);
    digitalWrite(ledGreen,LOW);

    
    digitalWrite(ledYellow,HIGH);   //according to the lab requirement the buzzer is on for 3 seconds before the light changes
    digitalWrite(buzzer,HIGH);      //But the yellow light is only on for 3 seconds, thus the buzzer is on the entire time the yellow LED is on
    delay(3000);                    //In addtion, the buzzer is on the entire time from the last 3 seconds of green and the entire 3 seconds of yellow.
    digitalWrite(buzzer,LOW);
    digitalWrite(ledYellow,LOW);

    
    digitalWrite(ledRed,HIGH);
    delay(12000);
    digitalWrite(buzzer,HIGH);
    delay(3000);
    digitalWrite(buzzer,LOW);
    digitalWrite(ledRed,LOW);
   
  Serial.println("end");                //Just a line for debugging, prints the word "end"m denotes when a full pattern is completed.

}
