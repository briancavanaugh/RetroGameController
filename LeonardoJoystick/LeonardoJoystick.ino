// Leonardo Joystick Controller for Retro Gaming
// 
// Configure logical joystick using Joystick library
// Configure joystick/button matrix using Keypad library
// Configure Adafruit keypad matrix using Adafruit_Keypad library
//
// Include the needed libraries
#include <Joystick.h>
#include <Keypad.h>
#include <Adafruit_Keypad.h>

// Joystick Config
const byte NUMBUTTONS = 22;

// Keypad Config
const byte KEYPADROWS = 4;
const byte KEYPADCOLS = 4;

byte keypad_buttons[KEYPADROWS][KEYPADCOLS] = {
  {1,2,3,4},
  {5,6,7,8},
  {9,10,11,12},
  {13,14,15,16}
};

byte keypad_rowPins[KEYPADROWS] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte keypad_colPins[KEYPADCOLS] = {2,3,4,5}; //connect to the column pinouts of the keypad

// Adafruit Keypad Config
const byte ADAFRUITROWS = 4; // rows
const byte ADAFRUITCOLS = 3; // columns
// define the symbols on the buttons of the keypad
byte adafruitKeys[ADAFRUITROWS][ADAFRUITCOLS] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10,11,12}
};

byte adafruitRowPins[ADAFRUITROWS] = {A0,A1,A2,A3}; // connect to the row pinouts of the keypad
byte adafruitColPins[ADAFRUITCOLS] = {10,11,12}; // connect to the column pinouts of the keypad

//initialize an instance of Keypad
Keypad keypad_physical_buttons = Keypad(makeKeymap(keypad_buttons), 
  keypad_colPins, 
  keypad_rowPins, 
  KEYPADCOLS, 
  KEYPADROWS); 

//initialize an instance of Adafruit_Keypad
Adafruit_Keypad adafruitKeypad = Adafruit_Keypad(makeKeymap(adafruitKeys),
  adafruitRowPins,
  adafruitColPins,
  ADAFRUITROWS,
  ADAFRUITCOLS);

//initialize an instance of Joystick with 22 buttons and an XY joystick;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 
  NUMBUTTONS, 0,        // Button Count, Hat Switch Count
  true, true, false,    // X and Y, but no Z Axis
  false, false, false,  // No Rx, Ry, or Rz
  false, false, false,  // No rudder or throttle
  false, false);        // No accelerator, brake, or steering

void setup() {
  // put your setup code here, to run once:
  adafruitKeypad.begin();
  Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  CheckKeypadButtons();
  CheckAdafruitButtons();
  delay(10);
}

void CheckKeypadButtons(void) {
  if (keypad_physical_buttons.getKeys())
  {
    //TODO Scan appropriately for buttons mapped to XY Axis
    for (int i=4; i<=13; i++)  // Scan the whole key list.
    {
      if (keypad_physical_buttons.key[i].stateChanged)  // Only find keys that have changed state.
      {
        switch (keypad_physical_buttons.key[i].kstate)
        {
          // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
          case PRESSED:
          case HOLD:
            Joystick.setButton(keypad_physical_buttons.key[i].kchar-1, 1);
            break;
          case RELEASED:
          case IDLE:
            Joystick.setButton(keypad_physical_buttons.key[i].kchar-1, 0);
            break;
        }
      }
    }
  }
}

void CheckAdafruitButtons() {
  adafruitKeypad.tick();
  
  for (int i = 14; i <= 25; i++)
  {
    if (adafruitKeypad.isPressed(i))
    {
      Joystick.setButton(i-1, 1);
    } 
    else
    {
      Joystick.setButton(i-1, 0);
    }
  }
}
