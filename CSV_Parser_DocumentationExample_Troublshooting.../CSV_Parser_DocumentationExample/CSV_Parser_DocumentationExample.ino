/*  Basic usage example for: https://github.com/michalmonday/CSV-Parser-for-Arduino  */

#include <CSV_Parser.h>

/*
This code prints:
Accessing values by column name:
0. String = hello
0. Number = 5
1. String = world
1. Number = 10
Accessing values by column number:
0. String = hello
0. Number = 5
1. String = world
1. Number = 10
 */
 
void setup() {
  Serial.begin(115200);
  delay(5000);
// my current theory is that there is a memory limitation that is result in nonsense being printed if I try and parse any more than this:
  char * csv_str = "Date, Weekday,Time,Time24,Mmol,TimeInterval,Extra\n" 
"3-Sep-2019,Tuesday,4:11 AM,4:11,11,226,Test\n"
"3-Sep-2019,Tuesday,7:57 AM,7:57,9.2,124,Test\n"
"3-Sep-2019,Tuesday,7:57 AM,7:57,9.2,124,Test\n"
//"3-Sep-2019,Tuesday,7:57 AM,7:57,9.2,124,Test\n"
//"3-Sep-2019,Tuesday,7:57 AM,7:57,9.2,124\n"
//"3-Sep-2019,Tuesday,7:57 AM,7:57,9.2,124\n"
//"3-Sep-2019,Tuesday,7:57 AM,7:57,9.2,124\n"
"3-Sep-2019,Tuesday,7:57 AM,7:57,9.2,124,Test\n";
                 
  CSV_Parser cp(csv_str, /*format*/ "ssssfLs");
cp.print();
  /* 
    If we wanted to just check if the csv was parsed properly we could use:
    cp.print();
    (assumming that "Serial.begin(baud_rate)" was previously called. Because "cp.print()" is using "Serial" object)
  */
}

void loop() {

}
