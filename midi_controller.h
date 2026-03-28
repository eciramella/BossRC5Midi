#ifndef MIDI_CONTROLLER_H
#define MIDI_CONTROLLER_H

#include <MIDI.h>

const int MIDI_CC_MEMORY_UP = 80;
const int MIDI_CC_MEMORY_DOWN = 81;
const int MIDI_CC_REDO_UNDO = 82;
const int MIDI_CC_REVERSE = 83;
const int MIDI_CC_DRUM_START = 84;
const int MIDI_CC_DRUM_STOP = 85;
const int MIDI_CC_START_STOP = 86;
const int MIDI_CC_CLEAR = 87;

const int MIDI_CC_NUMBERS[8] = {
  MIDI_CC_MEMORY_UP,
  MIDI_CC_MEMORY_DOWN,
  MIDI_CC_REDO_UNDO,
  MIDI_CC_REVERSE,
  MIDI_CC_DRUM_START,
  MIDI_CC_DRUM_STOP,
  MIDI_CC_START_STOP,
  MIDI_CC_CLEAR
};

const int MIDI_CHANNEL = 1;
const int MIDI_VELOCITY_ON = 127;
const int MIDI_VELOCITY_OFF = 0;
const int MIDI_PULSE_DELAY = 50;

void sendMidiPulse(int midiNumber) {
  MIDI.sendControlChange(midiNumber, MIDI_VELOCITY_ON, MIDI_CHANNEL);
  delay(MIDI_PULSE_DELAY);
  MIDI.sendControlChange(midiNumber, MIDI_VELOCITY_OFF, MIDI_CHANNEL);
}

void sendMidiValue(int midiNumber, int value) {
  MIDI.sendControlChange(midiNumber, value, MIDI_CHANNEL);
  delay(MIDI_PULSE_DELAY);
}

#endif
