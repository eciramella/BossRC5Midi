#ifndef BUTTON_HANDLERS_H
#define BUTTON_HANDLERS_H

#include "buttons.h"
#include "displays.h"
#include "midi_controller.h"

bool startup = true;

void handleButton(int buttonIndex) {
  if (!buttons[buttonIndex].isReleased()) {
    return;
  }

  switch (buttonIndex) {
    case 0: handleMemoryUp(); break;
    case 1: handleMemoryDown(); break;
    case 2: handleRedoUndo(); break;
    case 3: handleClear(); break;
    case 4: handleTapTempo(); break;
    case 5: handleDrumStart(); break;
    case 6: handleDrumStop(); break;
    case 7: handleAllStartStop(); break;
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
  sendBasicMidiControl(4);
}

void handleDrumStart() {
  sendBasicMidiControl(5);
}

void handleDrumStop() {
  sendBasicMidiControl(6);
}

void handleAllStartStop() {
  sendBasicMidiControl(7);
}

void handleClear() {
  if (button_counts[3] != buttons[3].getCount()) {
    button_counts[3] = buttons[3].getCount();
    sendBasicMidiControl(3);
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
