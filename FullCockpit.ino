#include <Joystick.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 32, 2,
                    true, true, true,
                    true, true, true,
                    false, false, false,
                    false, false);

void setup() {
  
  // Initialize Button Pins
  for (int index = 4; index < 12; index++)
  {
    pinMode(index, INPUT_PULLUP);
  }

  // Initialize Joystick Library
  Joystick.begin(false);
}

// Last state of the pins
int lastButtonState[2][4] = {{0,0,0,0}, {0,0,0,0}};

void loop() {

  bool valueChanged[2] = {false, false};
  int currentPin = 4;

  // Read pin values
  for (int hatSwitch = 0; hatSwitch < 2; hatSwitch++)
  {
    for (int index = 0; index < 4; index++)
    {
      int currentButtonState = !digitalRead(currentPin++);
      if (currentButtonState != lastButtonState[hatSwitch][index])
      {
        valueChanged[hatSwitch] = true;
        lastButtonStategitg
    }
  }

  for (int hatSwitch = 0; hatSwitch < 2; hatSwitch++)
  {
    if (valueChanged[hatSwitch]) {
      
      if ((lastButtonState[hatSwitch][0] == 0)
        && (lastButtonState[hatSwitch][1] == 0)
        && (lastButtonState[hatSwitch][2] == 0)
        && (lastButtonState[hatSwitch][3] == 0)) {
          Joystick.setHatSwitch(hatSwitch, -1);
      }
      if (lastButtonState[hatSwitch][0] == 1) {
        Joystick.setHatSwitch(hatSwitch, 0);
      }
      if (lastButtonState[hatSwitch][1] == 1) {
        Joystick.setHatSwitch(hatSwitch, 90);
      }
      if (lastButtonState[hatSwitch][2] == 1) {
        Joystick.setHatSwitch(hatSwitch, 180);
      }
      if (lastButtonState[hatSwitch][3] == 1) {
        Joystick.setHatSwitch(hatSwitch, 270);
      }
      
    } // if the value changed
    
  } // for each hat switch
  Joystick.sendState();
  delay(50);
}
