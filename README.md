ArduinoServer
============

This project allows you to send custom command strings to the Arduino via the virtual serial port.

By default, commands are terminated by an LF (line-feed) and/or CR (carriage-return), but you can specify any other delimiter with a minor change in the code and to the serial monitor (or terminal program).

I have only tested this project under Windows XP, with version 1.0.1 of the Arduino IDE, on an Arduino UNO R3.

There are other ways of accomplishing this (Firmata, cmdMessenger...), but the goals for this project are simplicity, small size (under 10KB for the demo) and readability.

The sample project consists of four files:
ArduinoServer.ino
ArduinoServer.h
MY_ServerApp.h
README.md

ArduinoServer.ino:
A sample Arduino sketch containing the setup() and loop() methods.  Configure the Serial Monitor to send a 'Newline' when the [Enter] key is pressed or the 'Send' button is clicked, and set the rate to 115200 baud.

ArduinoServer.h:
This is the generic server module that contains the getCommand() and runCommand() procedures; the server splash and help screens.  The getCommand() procedure retrieves the command string from the serial buffer.

Pass the command to the runCommand() parser to have it matched against a list of strings, assigned to commands (defined in the application module).

MY_ServerApp.h:
An example server application containing some custom commands (procedures called by the runCommand() parser).

README.md:
This file.