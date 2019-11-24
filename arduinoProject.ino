#include <SoftwareSerial.h>// import the serial library

SoftwareSerial bluetooth(2, 3); // RX, TX

int BluetoothData; // the data given from computer
int ledPin[] = {7,8,9,10,11,12};
int old_poten = 0;
int potPin = A5;
int value;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
    for (int i =0;i<6;i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(A5, OUTPUT);
 
}

void loop() {
  value = analogRead(potPin);
  int poten = map(value, 0, 1023, 0, 255);
if (poten != old_poten){
 old_poten = poten;  // save the changed value
 bluetooth.print(poten);  // send it out
 delay(500);
}
   if (bluetooth.available()){
BluetoothData=bluetooth.read();
  switch (BluetoothData) {
    case '1':
    lightOnRum1();
      break;
    case '2':
       lightOffRum1();
      break;
      case '3':
         lightOnRum2();
      break;
      case '4':
      lightOffRum2();
      break;
      case '5':
      lightOnRum3();
      break;
       case '6':
    lightOffRum3();
      break;
       case '7':
      lightOnRum4();
      break;
       case '8':
      lightOffRum4();
      break;
          case '9':
      lightAllRoomsOn();
      break;
       case '0':
      lightAllRoomsOff();
      break;
      case 'o':
      openWindow();
      break;
      case 'f':
      closeWindow();
      break;
      case 'l':
      larmetOn();
      break;
      case 'a':
      larmetOff();
      break;
    default:
      break;
  }
   }
   }
   void lightOnRum1(){ // light up
  digitalWrite(ledPin[0], HIGH);   // turn the LED on (HIGH is the voltage level) 
  bluetooth.write("1");
   }
   void lightOffRum1(){
    digitalWrite(ledPin[0], LOW);
   }
    void lightOnRum2(){ // light up
  digitalWrite(ledPin[1], HIGH);   // turn the LED on (HIGH is the voltage level) 
   }
   void lightOffRum2(){
    digitalWrite(ledPin[1], LOW);
   }
    void lightOnRum3(){ // light up
  digitalWrite(ledPin[2], HIGH);   // turn the LED on (HIGH is the voltage level) 
   }
   void lightOffRum3(){
    digitalWrite(ledPin[2], LOW);
   }
    void lightOnRum4(){ // light up
  digitalWrite(ledPin[3], HIGH);   // turn the LED on (HIGH is the voltage level) 
   }
   void lightOffRum4(){
    digitalWrite(ledPin[3], LOW);
   }
   void lightAllRoomsOn(){
   for (int i =0;i<4;i++)
  {
    digitalWrite(ledPin[i], HIGH);
  }
   }
  
void lightAllRoomsOff(){
   for (int i =0;i<4;i++)
  {
    digitalWrite(ledPin[i], LOW);
  }
}
  void openWindow(){
    bluetooth.write("r");
    digitalWrite(ledPin[4], HIGH);
  }
  void closeWindow(){
    bluetooth.write("s");
    digitalWrite(ledPin[4], LOW);
  }
  void larmetOn(){
    bluetooth.write("o");
    digitalWrite(ledPin[5], HIGH);
  }
  void larmetOff(){
    digitalWrite(ledPin[5], LOW);
    bluetooth.write("f");
  }
 

 

