#include <Joystick.h>

Joystick_ Joystick1(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 32, 2,
                   true, true, true,
                   true, true, true,
                   false, false, false,
                   false, false);

const int pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                    12, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                    41, 42,
                    // Not button pins: 11.
                    43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};

int maxX1, minX1, maxY1, minY1, maxZ1, minZ1, maxRx1, minRx1, maxRy1, minRy1, maxRz1, minRz1 = 512;
// int maxX2, minX2, maxY2, minY2, maxZ2, minZ2, maxRx2, minRx2, maxRy2, minRy2, maxRz2, minRz2 = 512;
void setup()
{

  // Initialize Button Pins
  for (int i = 0; i < 32; i++)
  {
    pinMode(pins[i], INPUT_PULLUP);
  }

  // Initialize Joystick Library
  Joystick1.begin(false);
}

void loop()
{

  for (int i = 0; i < 32; i++)
  {
    Joystick1.setButton(i, !digitalRead(pins[i]));
  }
  Joystick1.sendState();
  //Joystick2.sendState();
  delay(50);
}
