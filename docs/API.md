# API Reference

## buttons.h

### Constants
- `NUM_BUTTONS` - Total number of buttons (8)
- `DEBOUNCE_TIME` - Debounce time in milliseconds (60ms)
- `BUTTON_PINS[]` - Array of GPIO pins for each button
- `button_counts[]` - Array tracking press counts for each button

### Variables
- `buttons[]` - Array of ezButton objects (8 buttons)

### Functions

#### `void initializeButtons()`
Initializes all buttons with debounce settings.
- Called once in `setup()`
- Sets debounce time for all buttons

---

## displays.h

### Constants
- `NUM_DISPLAYS` - Total number of LCD displays (8)
- `LCD_ADDRESSES[]` - Array of I2C addresses for each display
- `DISPLAY_LABELS[]` - Array of default labels for each display

### Variables
- `displays[]` - Array of LiquidCrystal_I2C objects (8 displays)

### Functions

#### `void initializeDisplays()`
Initializes all LCD displays and shows default labels.
- Called once in `setup()`
- Initializes each display
- Turns on backlight for each display
- Prints default label on each display

#### `void displayMessage(int displayIndex, const char* message)`
Updates the text shown on a specific display.

**Parameters:**
- `displayIndex` - Which display to update (0-7)
- `message` - String to display (16 chars max for typical LCD)

**Example:**
```cpp
displayMessage(3, "Reversing...    ");  // Update display 3
```

---

## midi_controller.h

### Constants
- `MIDI_CC_MEMORY_UP` - CC #80 (Button 1)
- `MIDI_CC_MEMORY_DOWN` - CC #81 (Button 2)
- `MIDI_CC_REDO_UNDO` - CC #82 (Button 3)
- `MIDI_CC_REVERSE` - CC #83 (Button 4)
- `MIDI_CC_DRUM_START` - CC #84 (Button 5)
- `MIDI_CC_DRUM_STOP` - CC #85 (Button 6)
- `MIDI_CC_START_STOP` - CC #86 (Button 7)
- `MIDI_CC_CLEAR` - CC #87 (Button 8)
- `MIDI_CHANNEL` - MIDI channel (1)
- `MIDI_VELOCITY_ON` - Velocity for "on" message (127)
- `MIDI_VELOCITY_OFF` - Velocity for "off" message (0)
- `MIDI_PULSE_DELAY` - Delay between on/off messages (50ms)

### Functions

#### `void sendMidiPulse(int midiNumber)`
Sends a short MIDI control change pulse (on then off).
- Useful for momentary button presses

**Parameters:**
- `midiNumber` - MIDI CC number to send

**Example:**
```cpp
sendMidiPulse(MIDI_CC_MEMORY_UP);  // Send pulse on CC #80
```

#### `void sendMidiValue(int midiNumber, int value)`
Sends a MIDI control change with a specific value.
- Useful for toggle states (on/off)

**Parameters:**
- `midiNumber` - MIDI CC number to send
- `value` - Value to send (0-127)

**Example:**
```cpp
sendMidiValue(MIDI_CC_REVERSE, 127);  // Turn reverse on
sendMidiValue(MIDI_CC_REVERSE, 0);    // Turn reverse off
```

---

## button_handlers.h

### Variables
- `reverse` - Tracks reverse toggle state (bool)
- `drums_running` - Tracks whether drums are currently running (bool)
- `startup` - Tracks first-run flag (bool)
- `last_tap_time` - Timestamp of last tap tempo press (unsigned long)
- `tap_count` - Number of taps detected (int)
- `button_counts[]` - Local tracking of button press counts

### Constants
- `TAP_TEMPO_TIMEOUT` - Reset tap tempo if no tap for 3 seconds (3000ms)
- `MIN_TAP_INTERVAL` - Minimum milliseconds between taps (100ms)

### Functions

#### `void handleButton(int buttonIndex)`
Main dispatcher for button events.
- Called from `loop()` for each button
- Routes to specific button handler

**Parameters:**
- `buttonIndex` - Which button was pressed (0-7)

#### Button-Specific Handlers

Each button has its own handler function:

- `void handleMemoryUp()` - Button 1: Track up
- `void handleMemoryDown()` - Button 2: Track down
- `void handleRedoUndo()` - Button 3: Redo/undo
- `void handleClear()` - Button 4: Clear loop
- `void handleTapTempo()` - Button 5: Send tap tempo signal
- `void handleDrumStart()` - Button 6: Start drums
- `void handleDrumStop()` - Button 7: Stop drums
- `void handleAllStartStop()` - Button 8: Start/stop all recording

#### `void sendBasicMidiControl(int buttonIndex)`
Sends standard MIDI pulse for a button press.
- Respects startup flag (doesn't send during init)
- Prints debug info to serial

**Parameters:**
- `buttonIndex` - Which button (0-7)

#### `void handleTapTempo()`
Detects tempo from tap timing.
- First tap initializes, second and subsequent taps calculate BPM
- Minimum 100ms between taps to avoid false detection
- Resets tap count if no tap for 3 seconds (TAP_TEMPO_TIMEOUT)
- Displays "Tempo Detected" briefly, then returns to "Tap Tempo"
- Prints detected BPM to serial output for debugging
- Sends MIDI pulse when tempo is calculated

#### Utility Functions

- `void updateButtonLoops()` - Updates all button state machines (called in loop)
- `void processButtonPresses()` - Processes all button events (called in loop)
- `void clearStartupFlag()` - Clears startup flag on first loop (called in loop)

---

## BossRC5Midi.ino

### Setup
The `setup()` function:
1. Initializes serial communication (9600 baud)
2. Initializes MIDI
3. Initializes all buttons
4. Initializes all displays
5. Waits 1 second before enabling button processing

### Loop
The `loop()` function:
1. Updates all button state machines
2. Processes button press events
3. Clears startup flag on first iteration

---

## MIDI Control Assignments

All MIDI messages are sent on **channel 1** with the following control changes:

| Button | Function | CC # |
|--------|----------|------|
| 1 | Track Up | 80 |
| 2 | Track Down | 81 |
| 3 | Redo/Undo | 82 |
| 4 | Tap Tempo | 83 |
| 5 | Drum Start/Stop | 84 & 85 |
| 6 | All Start/Stop | 86 |
| 7 | Clear | 87 |

**Button Behaviors:**
- Button 4 (Tap Tempo): Sends MIDI pulse on CC 83 when pressed
- Button 5 (Drum Start/Stop): Toggles between drums off (CC 85 pulse) and drums on (CC 84 pulse)
- Most other buttons send a pulse (on then off)

For details on RC-5 MIDI implementation, see the [Roland RC-5 Reference Manual](https://static.roland.com/assets/media/pdf/RC-5_reference_eng01_W.pdf) (page 14).
