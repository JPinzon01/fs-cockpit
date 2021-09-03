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

void readJoystickAxes(Joystick_ *joy1)
{
  int axisRead = 0;
  axisRead = analogRead(A0);
  if (axisRead > maxX1)
    maxX1 = axisRead;
  else if (axisRead < minX1)
    minX1 = axisRead;
  joy1->setXAxis(axisRead);
  axisRead = analogRead(A1);
  if (axisRead > maxY1)
    maxY1 = axisRead;
  else if (axisRead < minY1)
    minY1 = axisRead;
  joy1->setYAxis(axisRead);
  axisRead = analogRead(A2);
  if (axisRead > maxZ1)
    maxZ1 = axisRead;
  else if (axisRead < minZ1)
    minZ1 = axisRead;
  joy1->setZAxis(analogRead(A2));
  axisRead = analogRead(A3);
  if (axisRead > maxRx1)
    maxRx1 = axisRead;
  else if (axisRead < minRx1)
    minRx1 = axisRead;
  joy1->setRxAxis(analogRead(A3));
  axisRead = analogRead(A4);
  if (axisRead > maxRy1)
    maxRy1 = axisRead;
  else if (axisRead < minRy1)
    minRy1 = axisRead;
  joy1->setRyAxis(analogRead(A4));
  axisRead = analogRead(A5);
  if (axisRead > maxRz1)
    maxRz1 = axisRead;
  else if (axisRead < minRz1)
    minRz1 = axisRead;
  joy1->setRzAxis(axisRead);

  // axisRead = analogRead(A6);
  // if (axisRead > maxX2)
  //   maxX2 = axisRead;
  // else if (axisRead < minX2)
  //   minX2 = axisRead;
  // joy2->setXAxis(axisRead);
  // axisRead = analogRead(A7);
  // if (axisRead > maxY2)
  //   maxY2 = axisRead;
  // else if (axisRead < minY2)
  //   minY2 = axisRead;
  // joy2->setYAxis(axisRead);
  // axisRead = analogRead(A8);
  // if (axisRead > maxZ2)
  //   maxZ2 = axisRead;
  // else if (axisRead < minZ2)
  //   minZ2 = axisRead;
  // joy2->setZAxis(analogRead(A2));
  // axisRead = analogRead(A9);
  // if (axisRead > maxRx2)
  //   maxRx2 = axisRead;
  // else if (axisRead < minRx2)
  //   minRx2 = axisRead;
  // joy2->setRxAxis(analogRead(A3));
  // axisRead = analogRead(A10);
  // if (axisRead > maxRy2)
  //   maxRy2 = axisRead;
  // else if (axisRead < minRy2)
  //   minRy2 = axisRead;
  // joy2->setRyAxis(analogRead(A4));
  // axisRead = analogRead(A11);
  // if (axisRead > maxRz2)
  //   maxRz2 = axisRead;
  // else if (axisRead < minRz2)
  //   minRz2 = axisRead;
  // joy2->setRzAxis(axisRead);
}
void setup()
{

  // Initialize Button Pins
  for (int i = 0; i < 32; i++)
  {
    pinMode(pins[i], INPUT_PULLUP);
  }

  // Set axes range Values
  Joystick1.setXAxisRange(0, 1023);
  Joystick1.setYAxisRange(0, 1023);
  Joystick1.setZAxisRange(0, 1023);
  Joystick1.setRxAxisRange(0, 1023);
  Joystick1.setRyAxisRange(0, 1023);
  Joystick1.setRzAxisRange(0, 1023);

  //Joystick2.setXAxisRange(0, 1023);
  //Joystick2.setYAxisRange(0, 1023);
  //Joystick2.setZAxisRange(0, 1023);
  //Joystick2.setRxAxisRange(0, 1023);
  //Joystick2.setRyAxisRange(0, 1023);
  //Joystick2.setRzAxisRange(0, 1023);

  Joystick1.begin(false);
  //Joystick2.begin(false);
  // Initialize Joystick Library
  Joystick1.begin(false);
}

void loop()
{
  // Buttons
  for (int i = 0; i < 32; i++)
  {
    Joystick1.setButton(i, !digitalRead(pins[i]));
  }

  // Axes
  readJoystickAxes(&Joystick1);
  Joystick1.sendState();
  //Joystick2.sendState();
  delay(50);
}
