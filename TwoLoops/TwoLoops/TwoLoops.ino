
int frames = 0;
int frames2 = 0;
int numEntries = 5;
int numbersArray[] = {1,2,3,4,5};
int numbersArray2[] = {43,44,45,46,47};
unsigned long startMillis;
unsigned long currentMillis;
unsigned long startMillis2;
unsigned long currentMillis2;


void setup() {
Serial.begin(115200);
startMillis = millis();
startMillis2 = millis();
}

void loop() {
  // put your main code here, to run repeatedly: 
  frames = floor(millis() / 1000);// this determines the rate the value changes at
  frames %= numEntries; 
  frames2 = floor(millis() / 1500);
  frames2 %= numEntries; 
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  currentMillis2 = millis();
  if (currentMillis - startMillis > 1000)  //test whether the period has elapsed - this determines when to do something
  {
    Serial.println(numbersArray[frames]);
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
  }

  if (currentMillis2 - startMillis2 > 1500)  //test whether the period has elapsed - this determines when to do something
  {
    Serial.println(numbersArray2[frames2]);
    startMillis2 = currentMillis2;  //IMPORTANT to save the start time of the current LED state.
  }
}
