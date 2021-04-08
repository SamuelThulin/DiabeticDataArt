#include <CSV_Parser.h>

int frames = 0;
int frames2 = 0;
int framesChecker;
int numEntries = 5;
char **date;
char **weekday;
char **time12;
char **time24;
float *mmol;
float *timeInterval;
unsigned long startMillis;
unsigned long currentMillis;
unsigned long startMillis2;
unsigned long currentMillis2;

char * csv = 
"Date, Weekday,  Time, Time24, Mmol, TimeInterval\n" 
"3-Sep-2019,Tuesday,4:11 AM,4:11,11,226\n" 
"3-Sep-2019,Tuesday,7:57 AM,7:57,9.2,124\n"
"3-Sep-2019,Tuesday,10:01 AM,10:01,4.4,136\n"
"3-Sep-2019,Tuesday,12:17 PM,12:17,4.2,304\n"
"3-Sep-2019,Tuesday,5:21 PM,17:21,7.8,84\n" 
"3-Sep-2019,Tuesday,6:45 PM,18:45,5,124\n"
"3-Sep-2019,Tuesday,8:49 PM,20:49,6.4,72\n"
"3-Sep-2019,Tuesday,10:01 PM,22:01,10.7,475\n";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  CSV_Parser cp(csv, /*format*/ "ssssff");
date = (char**)cp["Date"];
weekday = (char**)cp["Weekday"];
time12 = (char**)cp["Time"];
time24 = (char**)cp["Time24"];
mmol = (float*)cp["Mmol"];
timeInterval = (float*)cp["TimeInterval"];
startMillis = millis();
startMillis2 = millis();
}

void loop() {
  // put your main code here, to run repeatedly: 
  frames = floor(millis() / 1000);// this determines the rate the value changes at
  frames %= numEntries; 
//  frames2 = floor(millis() / 2000);// this is not working
//  frames2 %= numEntries; 
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  currentMillis2 = millis();
  if (currentMillis - startMillis >= 1000)  //test whether the period has elapsed - this determines when to do something
  {
    Serial.print(mmol[frames]); // why does this only print if timeInterval also prints (if you comment out Serial.println(timeInterval[frames]); then mmol prints as 0.00 
    Serial.println(" ");
    Serial.println(timeInterval[frames]); //in relation to comment above - it actually doesn't even matter what's printed here, as long as there is something mmol[frames] above will also print
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
  }

  //this is not working either
//  if (currentMillis2 - startMillis2 >= 501)  //test whether the period has elapsed - this determines when to do something
//  {
//    Serial.print(timeInterval[frames]);
//    startMillis2 = currentMillis2;  //IMPORTANT to save the start time of the current LED state.
//  }
}
