#include <CSV_Parser.h>

int frames = 0;
int numEntries = 2;
char **strings;
int32_t *numbers;
unsigned long startMillis;
unsigned long currentMillis;

char * csv_str = "my_strings,my_numbers\n"
                   "hello,5\n"
                   "world,10\n";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(5000);


                 
  CSV_Parser cp(csv_str, /*format*/ "sL");
  strings = (char**)cp["my_strings"];
  numbers = (int32_t*)cp["my_numbers"];

}

void loop() {
 // put your main code here, to run repeatedly: 
  frames = floor(millis() / 1000);// this determines the rate the value changes at
  frames %= numEntries;
  currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
  if (currentMillis - startMillis >= 1000)  //test whether the period has elapsed - this determines when to do something
  {
    Serial.print(strings[frames]);// this is not printing....  
    Serial.println(" ");
    Serial.println(numbers[frames]);//this does not print the 5 (could have to do with the frames index...)
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
  }

}
