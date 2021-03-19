float frames = 0;

//change adder to affect the framerate
float adder = 0.1;
const float data[] = {11, 9.2, 4.4, 4.2, 7.8, 5};

int dataLength;
int index;

//based on Arduino built-in Fade example
//nb on Arduino Uno 13 is not PWM (
int fan = 3;
int fanSpeed = 0;

void setup() {
  // put your setup code here, to run once:
  dataLength = sizeof(data)/ sizeof(data[0]);
  Serial.begin(9600);
  pinMode(fan, OUTPUT);
}

void loop() {
  
  //check against the current index. if changed, display
  
  
  if ((int)frames != index) {
    //set the variable 
    index = (int)frames;
    Serial.println("success");
    //print the information
    Serial.print(index);
    Serial.print(" ");
    Serial.println(data[index]);

    //write pulsewidth to the fan pin
    float fanOutput = data[index] * 10;
    fanOutput = constrain(fanOutput, 230, 255);//fan can't seem to run below 200...ask Charles about this (inertia? limits of DC motor?)
    analogWrite(fan, fanOutput);
  
  }
  
  frames += adder; 
  if (frames > dataLength) frames = 0;

  //quick fix before we put the timer in. 
  //we were trying to avoid a delay, 
  //but at least we can set multiple streams of information running within this rate
  delay(200);
}
