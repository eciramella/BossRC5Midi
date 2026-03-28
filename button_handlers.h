#ifndef BUTTON_HANDLERS_H
#define BUTTON_HANDLERS_H

#include "buttons.h"
#include "displays.h"
#include "midi_controller.h"

bool reverse = false;
bool drums_running = false;
bool startup = true;

void handleButton(int buttonIndex) {
  if (!buttons[buttonIndex].isReleased()) {
    return;
  }

  switch (buttonIndex) {
    case 0: handleMemoryUp(); break;
    case 1: handleMemoryDown(); break;
    case 2: handleRedoUndo(); break;
    case 3: handleReverse(); break;
    case 4: handleTapTempo(); break;
    case 5: handleDrumToggle(); break;
    case 6: handleAllStartStop(); break;
    case 7: handleClear(); break;
  }
}

void handleMemoryUp() {
  if (button_counts[0] != buttons[0].getCount()) {
    sendBasicMidiControl(0);
  }
}

void handleMemoryDown() {
  if (button_counts[1] != buttons[1].getCount()) {
    sendBasicMidiControl(1);
  }
}

void handleRedoUndo() {
  sendBasicMidiControl(2);
}

void handleTapTempo() {
  sendBasicMidiControl(3);
}

void handleDrumToggle() {
  if (!startup) {
    drums_running = !drums_running;
    if (drums_running) {
      Serial.println("button6 pressed starting drums");
      displayMessage(5, "Stop Drums      ");
      sendMidiPulse(MIDI_CC_DRUM_START);
      Serial.println("leaving button6 starting drums");
    } else {
      Serial.println("button6 pressed stopping drums");
      displayMessage(5, "Start Drums     ");
      sendMidiPulse(MIDI_CC_DRUM_STOP);
      Serial.println("leaving button6 stopping drums");
    }
  }
}

void handleAllStartStop() {
  sendBasicMidiControl(6);
}

void handleClear() {
  if (button_counts[7] != buttons[7].getCount()) {
    button_counts[7] = buttons[7].getCount();
    sendBasicMidiControl(7);
  }
}

void sendBasicMidiControl(int buttonIndex) {
  Serial.print("startup is ");
  Serial.println(startup);
  if (!startup) {
    Serial.print("Button number ");
    Serial.print(buttonIndex + 1);
    Serial.println(" was pressed");
    sendMidiPulse(MIDI_CC_NUMBERS[buttonIndex]);
    Serial.print("Leaving ");
    Serial.print(buttonIndex + 1);
    Serial.println(" pressed");
  }
}

void updateButtonLoops() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].loop();
  }
}

void processButtonPresses() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    handleButton(i);
  }
}

void clearStartupFlag() {
  if (startup) {
    Serial.print("From the loop, start up value is ");
    Serial.println(startup);
    startup = false;
  }
}

#endif
