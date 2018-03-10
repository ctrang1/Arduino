void setup() {
  // constants won't change. They're used here to
  // set pin numbers:
  const int buttonPin = 2; 
  const int ledPin = 13;
  const int motorIn1 = 9;
  const int motorIn2 = 10;
  int stat = 0;
  #define rank1 150
  #define rank2 200
  #define rank3 250

  int ledState = HIGH;
  int buttonState;
  int lastButtonState = LOW;


  long lastDebounceTime = 0;
  long debounceDelay = 50;

    pinMode (buttonPin, INPUT);
    pinMode (ledPin, OUTPUT);

    pinMode(motorIn1, OUTPUT);
    pinMode(motorIn2, OUTPUT);

    digitalWrite(ledPin, ledState);
    Serial. begin(9600);


  int reading = digitalRead(buttonPin);

 if (reading !=lastButtonState) {
  lastDebounceTime = millis();
 }
 if ((millis() - lastDebounceTime) > debounceDelay) {
  if (reading != buttonState) {
    
  buttonState = reading;
  if (buttonState == HIGH) {
    ledState = !ledState;
    stat = stat + 1;
    if(stat >= 4)
    {
      stat = 0;
       }
     }
   }
 }
 digitalWrite(ledPin, ledState);
 switch(stat)
 {
  case 1:
  clockwise(rank1);
  break;
  case 2:
  clockwise(rank2);
  break;
  case 3:
  clockwise(rank3);
  break;
  default:
  clockwise(0)
 lastButtonState = reading;
}
/*********************************************************/
void clockwise(int Speed)//
{
  analogWrite(motorIn1,0);
  analogWrite(motorIn2, Speed);
}
}
  // put your main code here, to run repeatedly:

}
