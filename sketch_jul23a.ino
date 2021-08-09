
int ledPin = 13;    // choose the pin for the LED
int input5Pin = 7;       // define push button input pins
int input4Pin = 6;
int input3Pin = 5;
int input2Pin = 4;
int input1Pin = 3;
int Trig_Pin = 9;
int Echo_Pin =10;



void setup()
{
  Serial.begin(9600);
  pinMode(Echo_Pin,INPUT);
  pinMode(Trig_Pin,OUTPUT);
  pinMode(ledPin, OUTPUT);   // declare LED as output
  pinMode(input5Pin, INPUT); // declare push button inputs
  pinMode(input4Pin, INPUT);
  pinMode(input3Pin, INPUT);
  pinMode(input2Pin, INPUT);
  pinMode(input1Pin, INPUT);
}

void loop()
{
  state=0;
  for(int i=3 ; i<=7 ; i++){

    checkPush (i);

  }

if(digitalRead(input1Pin)==HIGH) Serial.println("Play/Pause");
if(digitalRead(input2Pin)==HIGH) Serial.println("CloseTab");
if(digitalRead(input3Pin)==HIGH) Serial.println("Rewind");
if(digitalRead(input4Pin)==HIGH) Serial.println("Forward");
if(digitalRead(input5Pin)==HIGH) sensor(Trig_Pin,Echo_Pin);


delay(1000);

}


//This function is mainly used to check if the button is working
void checkPush(int pinNumber)
{
  int pushed = digitalRead(pinNumber);  // read input value
 
  if (pushed == HIGH) 
  {
     // turn LED ON
  digitalWrite(ledPin, HIGH); 
    
}
else{
     digitalWrite(ledPin, LOW);
    }
}

void sensor(int trig, int echo){
  float duration_us, distance_1,duration_us2,distance_2;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration_us = pulseIn(echo, HIGH);
  distance_1 = 0.017 * duration_us;
  delayMicroseconds(100);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration_us2 = pulseIn(echo, HIGH);
  distance_2 = 0.017*duration_us2;

  if(distance_2-distance_1>0) Serial.println("VoiceUp");
  else Serial.println("VoiceDown");
  Serial.println(distance_1);
}
