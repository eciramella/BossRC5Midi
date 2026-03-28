# References and Resources

## Official Documentation

### Boss RC-5 Looper
- **[Official RC-5 Reference Manual](https://static.roland.com/assets/media/pdf/RC-5_reference_eng01_W.pdf)**
  - Pages 1-13: General operation
  - **Page 14: MIDI Control Assignments** ← Most relevant for this project
  - Pages 15+: Advanced features

### Arduino
- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [Arduino Getting Started Guide](https://www.arduino.cc/en/Guide)
- [Serial Communication](https://www.arduino.cc/en/Reference/Serial)

### MIDI Specification
- [MIDI Specification (Basic)](https://www.midi.org/)
- [MIDI Control Change (CC) Messages](https://en.wikipedia.org/wiki/MIDI#Status_bytes)

## Libraries Used

### MIDI Library
- **Library Name:** MIDI
- **Author:** Forty Seven Effects
- **GitHub:** [FortySevenEffects/arduino_midi_library](https://github.com/FortySevenEffects/arduino_midi_library)
- **Purpose:** Simplifies MIDI communication over Serial

### ezButton Library
- **Library Name:** ezButton
- **Author:** ArduinoGetStarted
- **GitHub:** [ArduinoGetStarted/ezButton](https://github.com/ArduinoGetStarted/ezButton)
- **Purpose:** Reliable button debouncing with state tracking

### LiquidCrystal_I2C Library
- **Library Name:** LiquidCrystal I2C
- **Author:** Frank de Brabander
- **GitHub:** [johnwasser/LiquidCrystal_I2C](https://github.com/johnwasser/LiquidCrystal_I2C)
- **Purpose:** Controls 16×2 LCD displays over I2C

## Community Resources

### Guitar Pedal Communities
- **[r/guitarpedals on Reddit](https://www.reddit.com/r/guitarpedals/)**
  - Useful discussions about MIDI controllers
  - [Thread: Boss RC-5 MIDI Control Assignments](https://www.reddit.com/r/guitarpedals/comments/jz014d/does_anyone_have_the_midi_control_assignments/)

### Video Resources
- **[YouTube: DIY MIDI Controller Example](https://www.youtube.com/watch?v=ydvE6gHhRGA)**
  - Demonstrates building a MIDI controller with Arduino

## MIDI Control Numbers Quick Reference

RC-5 MIDI Control Changes (from page 14 of manual):

| CC # | Function |
|------|----------|
| 80 | Memory Up |
| 81 | Memory Down |
| 82 | Redo/Undo |
| 83 | Reverse |
| 84 | Drum Start |
| 85 | Drum Stop |
| 86 | Start/Stop |
| 87 | Clear |

## Troubleshooting Resources

### MIDI Debugging
- Use free MIDI monitor software to verify messages:
  - **Windows:** MIDI Monitor (included in some DAWs)
  - **macOS:** MIDI Monitor (built-in), or free alternatives
  - **Linux:** amidi, alsamixer
- Connect Arduino to computer and monitor MIDI output

### Arduino Debugging
- Use Serial Monitor to view debug output
- Enable Serial output in sketch for diagnostics
- Use Arduino IDE's built-in examples to test components

### Button/GPIO Issues
- Test with LED blink sketch to verify pin functionality
- Use multimeter to check continuity and voltage
- Verify pull-up/pull-down resistor configuration

### I2C Bus Issues
- Use I2C scanner sketch to identify connected devices and addresses
- Check voltage levels on SDA/SCL lines
- Verify pull-up resistor values (typically 4.7kΩ)
- Use oscilloscope to diagnose signal integrity issues

## Related Projects

### Similar MIDI Controllers
- Search GitHub for "Arduino MIDI controller"
- Look for projects using Boss RC-500 or RC-5 for reference

### Arduino Projects
- Arduino Music and Sound Library
- Arduino MIDI Shield projects
- Homemade pedalboard MIDI controller projects

## Learning Resources

### MIDI Basics
- [MIDI for Musicians](https://en.wikipedia.org/wiki/MIDI)
- [Understanding Control Change Messages](https://www.soundonsound.com/techniques/the-specifics-of-midi)

### Arduino Development
- [Arduino Project Hub](https://create.arduino.cc/projecthub)
- [Arduino Forums](https://forum.arduino.cc/)
- [Arduino Subreddit](https://www.reddit.com/r/arduino/)

## Contributing

If you find broken links or outdated information, please open an issue on the GitHub repository.
