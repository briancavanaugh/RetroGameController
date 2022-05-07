# Retro Game Controller
Code for making an Arduino Leonardo act as a Custom Game Controller

## To Dos
- Split out parts of this read me into separate files
- Link to pictures
- Rename repo to Retro Game Controller

## Backstory
For several years now, I've been getting into retro gaming. Playing 
video games from when I was a kid and into college.  This 
essentially covers the 80s and early 90s.  Growing up, I 
had several friends who had the Atari 2600.  I of course 
had the Intellivision.  That was a great system that had a unique
controllers.  This means that no controller today can function
the way that one did.

This project was born from wanting to play all those games from when
I was a kid using one controller.  What makes this controller
different of course is the keypad.

## Lessons Learned from Version 1
Version 1 of this was big, clunky, and not well-made, kind of
like everything else from the 80s.  My woodworking skills were
subpar at best and now they're, well, still not great, but I'm
getting better. Version 1 also had a major functional defect. The
infamous button ghosting problem. For those not familiar, this is
the problem where you press a certain combination of buttons
and then a seemingly other random button gets pressed all on it's
own.  I've addressed this by adding diodes to my physical build
of the controller.  Unfortunately, the keypad that I've used
still has this issue. Apparently, there are no built-in diodes
within that physical module. The good news is that the Intellivision
system really never needed you to press more than 1 of those buttons
at a time unless you were trying to pause the game (1 and 9). All
that said, on to this, version 2.

## References
- Joystick Library
  - This is a project from [MHeironimus/ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary) 
  on GitHub that does most of the hard work for you. Great examples 
  to follow and easy to implement!
- Keypad Library
  - This is a project from [Chris--A/Keypad](https://github.com/Chris--A/Keypad)
  on GitHub. Not as well documented as the Joystick Library, but
  some really easy to follow examples. The one that helped me the
  most was the MultiKey example.
- I decided not to use the [Adafruit Keypad Library](https://github.com/adafruit/Adafruit_Keypad)
  - I tried to go with this keypad library first since the actual
  keypads I used were from Adafruit. I decided against it though
  since I was having trouble getting the multi-key press to work.

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
