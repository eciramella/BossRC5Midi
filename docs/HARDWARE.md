# Hardware Setup

## Components

### Microcontroller
- Arduino (compatible board with sufficient I/O pins and I2C support)

### Input Devices
- **8x Push Buttons** on GPIO pins 13, 12, 11, 10, 9, 6, 5, 4
- Debounce time: 60ms

### Output Devices
- **8x 16×2 LCD Displays** with I2C interface
- I2C addresses: 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20

### Communication
- **MIDI** out to Boss RC-5 looper
- Uses Arduino MIDI library

## Wiring Diagram

### Buttons
```
Pin 13 ──[Button]──┬── GND
Pin 12 ──[Button]──┤
Pin 11 ──[Button]──┤
Pin 10 ──[Button]──┤
Pin 9  ──[Button]──┤
Pin 6  ──[Button]──┤
Pin 5  ──[Button]──┤
Pin 4  ──[Button]──└── GND
```

Each button uses INPUT_PULLUP mode (internal pull-up resistor).

### LCD Displays (I2C)

All 8 LCD displays share the same I2C bus (SDA and SCL lines):

```
          SDA ──────┬─── LCD1 (0x27)
                    ├─── LCD2 (0x26)
          SCL ──────┤     LCD3 (0x25)
                    ├─── LCD4 (0x24)
                    ├─── LCD5 (0x23)
                    ├─── LCD6 (0x22)
                    ├─── LCD7 (0x21)
                    └─── LCD8 (0x20)

         GND ───────────────────┤ (all displays)
         5V  ───────────────────┤ (all displays)
```

SDA and SCL pins depend on your Arduino board:
- Arduino Uno/Nano: SDA=A4, SCL=A5
- Arduino Mega: SDA=20, SCL=21
- Arduino Due: SDA=20, SCL=21

### MIDI Connection

MIDI output connects to the Boss RC-5 looper via standard MIDI connector (DIN-5).

Arduino MIDI library typically uses Serial (TX pin) for output.

## Button-to-Function Mapping

| Pin | Button # | LCD Display | Function |
|-----|----------|-------------|----------|
| 13 | 1 | Display 1 | Track Up |
| 12 | 2 | Display 2 | Track Down |
| 11 | 3 | Display 3 | Redo/Undo |
| 10 | 4 | Display 4 | Clear |
| 9  | 5 | Display 5 | Tap Tempo |
| 6  | 6 | Display 6 | Drum Start |
| 5  | 7 | Display 7 | Drum Stop |
| 4  | 8 | Display 8 | All Start/Stop |

## Libraries Required

Install these in Arduino IDE:

1. **MIDI** - For MIDI communication
2. **ezButton** - For reliable button debouncing
3. **LiquidCrystal_I2C** - For I2C LCD display support

## Assembly Notes

- Use pull-down resistors on button pins if not using INPUT_PULLUP
- Keep I2C bus lines short (preferably under 1 meter)
- Use 4.7kΩ pull-up resistors on SDA and SCL if experiencing I2C issues
- Ensure adequate power supply for all displays and buttons
- Add 100μF capacitor near power supply for stability

## Troubleshooting

### Buttons not responding
- Check GPIO pin connections
- Verify debounce time isn't too long (60ms default)
- Test with Serial output to verify button presses are detected

### LCD displays not showing
- Verify I2C addresses match (use I2C scanner sketch to find actual addresses)
- Check SDA/SCL connections
- Ensure I2C pullup resistors are present
- Adjust LCD contrast potentiometer if installed

### MIDI not working
- Verify MIDI library is installed
- Check serial/MIDI output connection to RC-5
- Test with MIDI monitor software to verify messages are being sent
- Confirm RC-5 is set to receive MIDI on channel 1

### General issues
- Enable serial debug output to diagnose problems
- Check Arduino board specification for I2C and serial pins
- Verify all components are powered correctly
