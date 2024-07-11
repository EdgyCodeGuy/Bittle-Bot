#include <IRremote.hpp>
#define IR_RECEIVE_PIN 6 

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;

void setup()
{
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver

  //set up Serial Monitor
  Serial.begin(19200);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);



  //NOTE: the output is less than a volt, not nearly enough to power the motor alone
  
} 

void loop() {
  if (IrReceiver.decode()) {
    //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
    //IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
    //IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
    //Serial.println(IrReceiver.decodedIRData.decodedRawData);

    //We need to use a "long" as an integer is not big enough to hold the decoded key value 
    unsigned long key = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(key);

    switch(key){
      case 3108437760://Go forward
        Serial.println(key);
        driveForward();
        break;
        
      case 3141861120://Go left
        Serial.println(key);
        driveLeft();
        break;
        
      case 3208707840://STOP
        Serial.println(key);
        STOP();
        break;
        
      case 3158572800://Go right
        Serial.println(key);
        driveRight();
        break;
        
      case 3927310080://Go back
        Serial.println(key);
        driveBack();
        break;
      
      case 3125149440://K.O CONDITION
        Serial.println(key);
        KO();
        break;
      
      case 3091726080://RESET CONDITION
        Serial.println(key);
        RESET();
        break;
    }
        
    IrReceiver.resume(); // Enable receiving of the next value
    
  }
}

void driveForward(){
  Serial.println("GOING FORWARD");
  //GOING FORWARD
  //Motor 1
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  //Motor 2
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
}

void driveLeft(){
  Serial.println("GOING LEFT");
  //Motor 1
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  //Motor 2
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void STOP(){
  Serial.println("STOPPING");
  //STOPPING
  //Motor 1
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  //Motor 2
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void driveRight(){
  Serial.println("GOING RIGHT");
  //Motor 1
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  //Motor 2
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  
}

void driveBack(){
  Serial.println("GOING BACK");
  //GOING BACK
  //Motor 1
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  //Motor 2
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  
}

void KO(){
  Serial.println("K.O");
}

void RESET(){
  Serial.println("RESET");
  /*
  digitalWrite(8, LOW); // Turn off LED
  digitalWrite(10, HIGH); //ENABLE bottom motor
  digitalWrite(11, HIGH); //ENABLE top motor
  */
}
