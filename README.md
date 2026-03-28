# BossRC5Midi

A custom MIDI controller for the Boss RC-5 looper, built with Arduino. This project provides an 8-button control interface with LCD displays showing the current function of each button.

## Project Overview

**BossRC5Midi** is a modular Arduino sketch that lets you control a Boss RC-5 looper pedal via MIDI. It features:

- 🔘 **8 Programmable Buttons** - Control looper functions with tactile feedback
- 🖥️ **8 LCD Displays** - One display per button shows the current function
- 📡 **MIDI Communication** - Sends control change messages to the RC-5
- 🏗️ **Modular Architecture** - Clean separation of concerns with header files
- 🔧 **Easy to Modify** - Change button assignments, MIDI mappings, or add new features

## Quick Start

1. **Hardware Setup** - See [Hardware Documentation](docs/HARDWARE.md) for wiring diagrams and component list
2. **Installation** - Install required Arduino libraries (MIDI, ezButton, LiquidCrystal_I2C)
3. **Upload** - Upload `BossRC5Midi.ino` to your Arduino board
4. **Control** - Press buttons to control your RC-5 looper

## Documentation

### [Architecture](docs/ARCHITECTURE.md)
Understand the project structure, design patterns, and how modules interact.

### [API Reference](docs/API.md)
Complete reference for all functions, constants, and MIDI control assignments.

### [Hardware Setup](docs/HARDWARE.md)
Wiring diagrams, component list, GPIO pin mappings, and troubleshooting.

### [References](docs/REFERENCES.md)
External resources, library documentation, and helpful links.

## Button Functions

| Button | Function | MIDI CC |
|--------|----------|---------|
| 1 | Track Up | 80 |
| 2 | Track Down | 81 |
| 3 | Redo/Undo | 82 |
| 4 | Reverse (Toggle) | 83 |
| 5 | Drums (Toggle) | 84 & 85 |
| 6 | Start/Stop | 86 |
| 7 | Clear | 87 |
| 8 | (unused) | - |

**Drum Toggle (Button 5):** Press once to start, press again to stop. Displays "Start Drums" when stopped and "Stop Drums" when running.

For complete MIDI mapping details, see page 14 of the [Boss RC-5 Reference Manual](https://static.roland.com/assets/media/pdf/RC-5_reference_eng01_W.pdf).

## Project Structure

```
BossRC5Midi/
├── BossRC5Midi.ino           # Main sketch - setup and loop
├── buttons.h                 # Button configuration and management
├── displays.h                # LCD display control
├── midi_controller.h         # MIDI communication
├── button_handlers.h         # Button press event handlers
├── README.md                 # This file
└── docs/
    ├── ARCHITECTURE.md       # Project structure and design
    ├── API.md                # Complete function reference
    ├── HARDWARE.md           # Wiring and components
    └── REFERENCES.md         # External resources
```

## Key Features

### Modular Design
- Separate header files for buttons, displays, MIDI, and handlers
- Uses arrays instead of individual variables (DRY principle)
- Easy to add/remove buttons or displays

### Reliable Button Handling
- 60ms debounce time
- State tracking to prevent multiple triggers
- Startup flag prevents spurious MIDI messages during initialization

### LCD Feedback
- Real-time display of button functions
- Toggle states (like reverse mode) are shown on the display
- Custom message function for updating displays

### MIDI Integration
- Sends standard MIDI control change messages on channel 1
- Support for momentary buttons (pulse) and toggle buttons
- Configurable MIDI CC numbers for easy remapping

## Dependencies

Install these libraries in Arduino IDE:

1. **MIDI** - For MIDI communication
2. **ezButton** - For button debouncing
3. **LiquidCrystal_I2C** - For LCD control

See [Hardware Setup](docs/HARDWARE.md#libraries-required) for installation instructions.

## Getting Help

- Check the [Hardware Setup](docs/HARDWARE.md#troubleshooting) troubleshooting section
- Review the [API Reference](docs/API.md) for function documentation
- Consult the [References](docs/REFERENCES.md) for external resources
- Open an issue on GitHub

## Resources

**Original Project Materials:**

Things I found useful:

- https://www.reddit.com/r/guitarpedals/comments/jz014d/does_anyone_have_the_midi_control_assignments/
- Page 14 of this file in particular: https://static.roland.com/assets/media/pdf/RC-5_reference_eng01_W.pdf
- Someone's example: https://www.youtube.com/watch?v=ydvE6gHhRGA&list=LL&index=31&t=9s

For more resources, see [References](docs/REFERENCES.md).

## License

This project is provided as-is. Feel free to modify and use for your own projects.

## Contributing

Found an issue? Have a suggestion? Feel free to open an issue or pull request!
