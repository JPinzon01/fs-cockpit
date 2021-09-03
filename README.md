# fs-cockpit
Custom cockpit for MSFS using Arduino Due.
This project will be used in MSFS2020, where I'll configure the inputs using the controls menu.

## Features

- Analog output ased as axes for input such as throttle, mixture, propeller, etc. More axes can be added using another device descriptor (joystick2).
- Digital input as buttons, up to 32. Can be used for buttons or switches.
- Rotary encoders return hat switch values. I intend to use them to control nav/radio frequencies, heading, atlitude, etc, so no need to track position.



This project uses the [Arduino Joytick library](https://github.com/MHeironimus/ArduinoJoystickLibrary) by MHeironimus.
