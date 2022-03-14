# Retro Game Controller
Code for making an Arduino Leonardo act as a Custom Game Controller

## To Dos
- Add Pictures
- Add Backstory
- Add Lessons Learned from version 1.0
- Rename repo to Retro Game Controller

## Backstory

## Lessons Learned from Version 1

## References
- Joystick Library
- Keypad Library
- Adafruit Keypad Library (reason for not listing)

## Joystick, Button, and Keypad Layout
#### Joystick and Buttons
| Row/Column | A         | B          | C          | D          |
|------------|-----------|------------|------------|------------|
| 1          | Select    | Start      | Unused     | Unused     |
| 2          | Y (Blue)  | X (Yellow) | L2 (Black) | R2 (Black) |
| 3          | B (Green) | A (Red)    | L1 (White) | R1 (White) |
| 4          | Up        | Down       | Left       | Right      |
  
#### Keypad
| Row/Column | A   | B   | C   |
|------------|-----|-----|-----|
| 1          | 1   | 2   | 3   |
| 2          | 4   | 5   | 6   |
| 3          | 7   | 8   | 9   |
| 4          | *   | 0   | #   |

#### Physical to Logical Mapping
| Physical   | Logical   | Mapping Name            | Column Pin | Row Pin |
|------------|-----------|-------------------------|------------|---------|
| Up         | Up        | Joystick and Buttons-A4 | 2          | 9       |
| Down       | Down      | Joystick and Buttons-B4 | 3          | 9       |
| Left       | Left      | Joystick and Buttons-C4 | 4          | 9       |
| Right      | Right     | Joystick and Buttons-D4 | 5          | 9       |
| B (Green)  | Button 1  | Joystick and Buttons-A3 | 2          | 8       |
| A (Red)    | Button 2  | Joystick and Buttons-B3 | 3          | 8       |
| Y (Blue)   | Button 3  | Joystick and Buttons-A2 | 2          | 7       |
| X (Yellow) | Button 4  | Joystick and Buttons-B2 | 3          | 7       |
| L1 (White) | Button 5  | Joystick and Buttons-C3 | 4          | 8       |
| R1 (White) | Button 6  | Joystick and Buttons-D3 | 5          | 8       |
| L2 (Black) | Button 7  | Joystick and Buttons-C2 | 4          | 7       |
| R2 (Black) | Button 8  | Joystick and Buttons-D2 | 5          | 7       |
| Select     | Button 9  | Joystick and Buttons-A1 | 2          | 6       |
| Start      | Button 10 | Joystick and Buttons-B1 | 3          | 6       |
| 1          | Button 11 | Adafruit Keypad-A1      | 10         | A0      |
| 2          | Button 12 | Adafruit Keypad-B1      | 11         | A0      |
| 3          | Button 13 | Adafruit Keypad-C1      | 12         | A0      |
| 4          | Button 14 | Adafruit Keypad-A2      | 10         | A1      |
| 5          | Button 15 | Adafruit Keypad-B2      | 11         | A1      |
| 6          | Button 16 | Adafruit Keypad-C2      | 12         | A1      |
| 7          | Button 17 | Adafruit Keypad-A3      | 10         | A2      |
| 8          | Button 18 | Adafruit Keypad-B3      | 11         | A2      |
| 9          | Button 19 | Adafruit Keypad-C3      | 12         | A2      |
| *          | Button 20 | Adafruit Keypad-A4      | 10         | A3      |
| 0          | Button 21 | Adafruit Keypad-B4      | 11         | A3      |
| #          | Button 22 | Adafruit Keypad-C4      | 12         | A3      |

####Map Rows and Columns to a single Arduino Pin
| Mapping Row/Column               | Arduino Pin |
|----------------------------------|-------------|
| Joystick and Buttons Column A    | 2           |
| Joystick and Buttons Column B    | 3           |
| Joystick and Buttons Column C    | 4           |
| Joystick and Buttons Column D    | 5           |
| Joystick and Buttons Row 1       | 6           |
| Joystick and Buttons Row 2       | 7           |
| Joystick and Buttons Row 3       | 8           |
| Joystick and Buttons Row 4       | 9           |
| Adafruit Keypad Column A - Pin 1 | 10          |
| Adafruit Keypad Column B - Pin 2 | 11          |
| Adafruit Keypad Column C - Pin 3 | 12          |
| Adafruit Keypad Row 1 - Pin 4    | A0          |
| Adafruit Keypad Row 2 - Pin 5    | A1          |
| Adafruit Keypad Row 3 - Pin 6    | A2          |
| Adafruit Keypad Row 4 - Pin 7    | A3          |

## Materials Used
| Quantity | Item                                  |
|----------|---------------------------------------|
| 1        | 1/2" x 2' x 4' MDF                    |
| 1        | Black Spray Paint                     |
| 1        | Finishing Paste Wax                   |
| 2        | Roller latch w/screws                 |
| 4        | Hinge w/screws                        |
| 2        | Adafruit 12 button keypad             |
| 8        | Keypad screws                         |
| 8        | Controller card standoff              |
| 8        | Controller card screw                 |
| 2        | Arduino Leonardo microcontroller      |
| 2        | Micro USB cable                       |
| 1        | 4	M/F wire leads                      |
| 2        | Joystick w/4 switches                 |
| 2        | Player 1 arcade button w/switch       |
| 2        | Player 2 arcade button w/switch       |
| 2        | Red arcade button w/switch            |
| 2        | Blue arcade button w/switch           |
| 2        | Yellow arcade button w/switch         |
| 2        | Green arcade button w/switch          |
| 4        | White arcade button w/switch          |
| 4        | Black arcade button w/switch          |
| 2        | Arduino UNO/Leonardo Prototype shield |
| 28       | 1N4148 Diodes                         |
|          | 22 Gauge Wire Solid Core              |
|          | 22 Gauge Wire Stranded                |
|          | Heat shrink tubing                    |
