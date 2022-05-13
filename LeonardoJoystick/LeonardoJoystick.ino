// Leonardo Joystick Controller for Retro Gaming
// 
// Configure joystick/button matrix using Keypad library
// Configure Adafruit keypad matrix using Keypad library
// Configure logical joystick using Joystick library
//

// Include the needed libraries
#include "Joystick.h"
#include "Keypad.h"

// Button Matrix Config
const byte BUTTON_MATRIX_ROWS = 4;
const byte BUTTON_MATRIX_COLS = 4;

// Define the symbols in the joystick/button matrix
char button_matrix_buttons[BUTTON_MATRIX_ROWS][BUTTON_MATRIX_COLS] = {
  {8,9,33,33},      // Select     , Start     , Empty     , Empty
  {2,3,6,7},        // Y (Blue)   , X (Yellow), L2 (Black), R2 (Black)
  {0,1,4,5},        // B (Green)  , A (Red)   , L1 (White), R1 (White)
  {'U','D','L','R'} // Joystick Up, Down      , Left      , Right
};

// Connect to the row and column pinouts of the joystick/button matrix
byte button_matrix_row_pins[BUTTON_MATRIX_ROWS] = {2,3,4,5};
byte button_matrix_col_pins[BUTTON_MATRIX_COLS] = {A0,A1,A2,A3};

// Initialize an instance of Keypad for the joystick/button Matrix
Keypad button_matrix_keypad = Keypad(makeKeymap(button_matrix_buttons), 
  button_matrix_row_pins, 
  button_matrix_col_pins, 
  BUTTON_MATRIX_ROWS, 
  BUTTON_MATRIX_COLS); 

// Adafruit Keypad Config
const byte ADAFRUIT_KEYPAD_ROWS = 4;
const byte ADAFRUIT_KEYPAD_COLS = 3;

// Define the symbols on the buttons of the keypad
char adafruit_keypad_keys[ADAFRUIT_KEYPAD_ROWS][ADAFRUIT_KEYPAD_COLS] = {
    {10,11,12}, //1, 2, 3
    {13,14,15}, //4, 5, 6
    {16,17,18}, //7, 8, 9
    {19,20,21}  //*, 0, #
};

// Connect to the row and column pinouts of the keypad
byte adafruit_keypad_row_pins[ADAFRUIT_KEYPAD_ROWS] = {9,10,11,12};
byte adafruit_keypad_col_pins[ADAFRUIT_KEYPAD_COLS] = {6,7,8};

// Initialize an instance of Keypad for the Adafruit Keypad
Keypad adafruit_keypad = Keypad(makeKeymap(adafruit_keypad_keys),
  adafruit_keypad_row_pins,
  adafruit_keypad_col_pins,
  ADAFRUIT_KEYPAD_ROWS,
  ADAFRUIT_KEYPAD_COLS);

// Joystick Config
const byte JOYSTICK_BUTTON_COUNT = 22;
const bool HAS_X_AXIS = true;
const bool HAS_Y_AXIS = true; 

// Initialize an instance of Joystick with 22 buttons and an XY joystick;
//JOYSTICK_DEFAULT_REPORT_ID = 0x03  //Player 1
//JOYSTICK_DEFAULT_REPORT_ID = 0x04  //Player 2
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 
  JOYSTICK_BUTTON_COUNT, 0,       // Button Count, Hat Switch Count
  HAS_X_AXIS, HAS_Y_AXIS, false,  // X and Y, but no Z Axis
  false, false, false,            // No Rx, Ry, or Rz
  false, false, false,            // No rudder, throttle, or accelerator
  false, false);                  // No brake or steering

bool upIsPressed = false;
bool downIsPressed = false;
bool leftIsPressed = false;
bool rightIsPressed = false;


void setup() {
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
}

void loop() {
  CheckButtonMatrixKeypad();
  CheckAdafruitKeypad();
  delay(10);
}

void CheckButtonMatrixKeypad() {
  // Fills kpd.key[ ] array with up-to 10 active keys.
  // Returns true if there are ANY active keys.
  if (button_matrix_keypad.getKeys())
  {    
    for (int i=0; i<LIST_MAX; i++)  // Scan the whole key list.
    {
      if (button_matrix_keypad.key[i].stateChanged)  // Only find keys that have changed state.
      {
        switch (button_matrix_keypad.key[i].kstate)
        {
          // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
          case PRESSED:
          case HOLD:
            if (button_matrix_keypad.key[i].kchar == 'U'){
              upIsPressed = true;
            } else if (button_matrix_keypad.key[i].kchar == 'D'){
              downIsPressed = true;
            } else if (button_matrix_keypad.key[i].kchar == 'L'){
              leftIsPressed = true;
            } else if (button_matrix_keypad.key[i].kchar == 'R'){
              rightIsPressed = true;
            } else {
              Joystick.setButton(button_matrix_keypad.key[i].kchar, 1);
            }
            break;
          case RELEASED:
          case IDLE:
            if (button_matrix_keypad.key[i].kchar == 'U'){
              upIsPressed = false;
            } else if (button_matrix_keypad.key[i].kchar == 'D'){
              downIsPressed = false;
            } else if (button_matrix_keypad.key[i].kchar == 'L'){
              leftIsPressed = false;
            } else if (button_matrix_keypad.key[i].kchar == 'R'){
              rightIsPressed = false;
            } else {
              Joystick.setButton(button_matrix_keypad.key[i].kchar, 0);
            }
            break;
        }
      }
    }

    if(upIsPressed){
      Joystick.setYAxis(-1);
    } else if(downIsPressed){
      Joystick.setYAxis(1);
    } else{
      Joystick.setYAxis(0);
    }
    
    if(leftIsPressed){
      Joystick.setXAxis(-1);
    } else if(rightIsPressed){
      Joystick.setXAxis(1);
    } else{
      Joystick.setXAxis(0);
    }
  }
}

void CheckAdafruitKeypad() {
  // Fills kpd.key[ ] array with up-to 10 active keys.
  // Returns true if there are ANY active keys.
  if (adafruit_keypad.getKeys())
  {    
    for (int i=0; i<LIST_MAX; i++)  // Scan the whole key list.
    {
      if (adafruit_keypad.key[i].stateChanged)  // Only find keys that have changed state.
      {
        switch (adafruit_keypad.key[i].kstate)
        {
          // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
          case PRESSED:
          case HOLD:
            Joystick.setButton(adafruit_keypad.key[i].kchar, 1);
            break;
          case RELEASED:
          case IDLE:
            Joystick.setButton(adafruit_keypad.key[i].kchar, 0);
            break;
        }
      }
    }
  }
}
