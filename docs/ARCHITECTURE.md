# Architecture

## Overview

The BossRC5Midi project is organized as a modular Arduino sketch that controls a Boss RC-5 looper using MIDI over a custom controller with buttons and LCD displays.

## Project Structure

```
BossRC5Midi/
├── BossRC5Midi.ino           # Main sketch - orchestrates all modules
├── buttons.h                 # Button configuration and management
├── displays.h                # LCD display management
├── midi_controller.h         # MIDI communication functions
├── button_handlers.h         # Button press event handlers
└── docs/
    ├── ARCHITECTURE.md       # This file
    ├── HARDWARE.md           # Hardware setup and connections
    ├── API.md                # Function reference and API
    └── REFERENCES.md         # External resources and documentation
```

## Core Modules

### buttons.h
Manages the 8 physical buttons used for control.
- Button pin definitions
- Debounce settings
- Button state tracking via arrays
- Initialization function

### displays.h
Controls the 8 LCD displays (one per button) showing current function.
- I2C address configuration
- Display labels
- Helper functions for updating displays
- Initialization function

### midi_controller.h
Handles all MIDI communication with the Boss RC-5.
- MIDI CC number definitions (mapping to RC-5 functions)
- Helper functions for sending MIDI control changes
- Centralized MIDI configuration

### button_handlers.h
Processes button press events and triggers appropriate actions.
- Individual handler functions for each button
- Logic for toggling states (e.g., reverse mode)
- Integration with MIDI and display modules

### BossRC5Midi.ino
The main sketch that ties everything together.
- Initializes hardware
- Main loop that processes button events
- Minimal logic - mostly orchestration

## Design Patterns

### DRY (Don't Repeat Yourself)
- Uses arrays instead of 8 individual variables
- Centralized configuration in header files
- Reusable helper functions

### Separation of Concerns
- Each module has a single responsibility
- Minimal dependencies between modules
- Easy to test and modify individual components

### Modular Initialization
- Each module provides an `initialize*()` function
- Main sketch calls these in `setup()`
- Easy to add/remove hardware

## Data Flow

```
Button Press → button_handlers.h → MIDI CC sent → midi_controller.h
                                              ↓
                            LCD updated via displays.h
```

1. User presses button
2. Button state detected in `loop()`
3. Appropriate handler function called
4. Handler sends MIDI message to Boss RC-5
5. Handler updates LCD display to show current state
