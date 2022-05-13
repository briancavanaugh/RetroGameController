## Joystick, Button, and Keypad Mappings
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
| Up         | Up        | Joystick and Buttons-A4 | A0         | 5       |
| Down       | Down      | Joystick and Buttons-B4 | A1         | 5       |
| Left       | Left      | Joystick and Buttons-C4 | A2         | 5       |
| Right      | Right     | Joystick and Buttons-D4 | A3         | 5       |
| B (Green)  | Button 1  | Joystick and Buttons-A3 | A0         | 4       |
| A (Red)    | Button 2  | Joystick and Buttons-B3 | A1         | 4       |
| Y (Blue)   | Button 3  | Joystick and Buttons-A2 | A0         | 3       |
| X (Yellow) | Button 4  | Joystick and Buttons-B2 | A1         | 3       |
| L1 (White) | Button 5  | Joystick and Buttons-C3 | A2         | 4       |
| R1 (White) | Button 6  | Joystick and Buttons-D3 | A3         | 4       |
| L2 (Black) | Button 7  | Joystick and Buttons-C2 | A2         | 3       |
| R2 (Black) | Button 8  | Joystick and Buttons-D2 | A3         | 3       |
| Select     | Button 9  | Joystick and Buttons-A1 | A0         | 2       |
| Start      | Button 10 | Joystick and Buttons-B1 | A1         | 2       |
| 1          | Button 11 | Adafruit Keypad-A1      | 6          | 9       |
| 2          | Button 12 | Adafruit Keypad-B1      | 7          | 9       |
| 3          | Button 13 | Adafruit Keypad-C1      | 8          | 9       |
| 4          | Button 14 | Adafruit Keypad-A2      | 6          | 10      |
| 5          | Button 15 | Adafruit Keypad-B2      | 7          | 10      |
| 6          | Button 16 | Adafruit Keypad-C2      | 8          | 10      |
| 7          | Button 17 | Adafruit Keypad-A3      | 6          | 11      |
| 8          | Button 18 | Adafruit Keypad-B3      | 7          | 11      |
| 9          | Button 19 | Adafruit Keypad-C3      | 8          | 11      |
| *          | Button 20 | Adafruit Keypad-A4      | 6          | 12      |
| 0          | Button 21 | Adafruit Keypad-B4      | 7          | 12      |
| #          | Button 22 | Adafruit Keypad-C4      | 8          | 12      |

#### Map Rows and Columns to a single Arduino Pin
| Mapping Row/Column               | Arduino Pin |
|----------------------------------|-------------|
| Joystick and Buttons Column A    | A0          |
| Joystick and Buttons Column B    | A1          |
| Joystick and Buttons Column C    | A2          |
| Joystick and Buttons Column D    | A3          |
| Joystick and Buttons Row 1       | 2           |
| Joystick and Buttons Row 2       | 3           |
| Joystick and Buttons Row 3       | 4           |
| Joystick and Buttons Row 4       | 5           |
| Adafruit Keypad Column A - Pin 1 | 6           |
| Adafruit Keypad Column B - Pin 2 | 7           |
| Adafruit Keypad Column C - Pin 3 | 8           |
| Adafruit Keypad Row 1 - Pin 4    | 9           |
| Adafruit Keypad Row 2 - Pin 5    | 10          |
| Adafruit Keypad Row 3 - Pin 6    | 11          |
| Adafruit Keypad Row 4 - Pin 7    | 12          |
