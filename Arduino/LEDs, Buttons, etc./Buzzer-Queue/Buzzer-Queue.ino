#include "Buzzer.h"
#include "PushButton.h"

const uint8_t buzzerPin = 13;
const uint8_t buttonPin = 2;

PushButton button = {buttonPin};
Buzzer buzzer = {buzzerPin};

void setup() {
  buzzer.begin();
  button.begin();
  delay(1000);
  buzzer.queueBeep(200, 200);
  buzzer.queueBeep(200, 200);
  buzzer.queueBeep(800, 200);
}

void loop() {
  if (button.isPressed()) {
    buzzer.queueBeep(500, 500);
  }
  buzzer.refresh();
}

/*
    If the button is pressed once, the buzzer will beep for 500ms.
    If the button is pressed twice, the buzzer will beep for 500ms, 
      then it will turn off for 500ms, then beep again for 500ms.
    If the button is pressed n times, the buzzer will beep n times, 
      each beep lasts 500ms, and there are 500ms between the beeps.
*/

