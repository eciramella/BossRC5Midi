#ifndef BUTTONS_H
#define BUTTONS_H

#include <ezButton.h>

const int NUM_BUTTONS = 8;
const int DEBOUNCE_TIME = 60;

const int BUTTON_PINS[NUM_BUTTONS] = {13, 12, 11, 10, 9, 6, 5, 4};
ezButton buttons[NUM_BUTTONS] = {
  ezButton(BUTTON_PINS[0], INPUT_PULLUP),
  ezButton(BUTTON_PINS[1], INPUT_PULLUP),
  ezButton(BUTTON_PINS[2], INPUT_PULLUP),
  ezButton(BUTTON_PINS[3], INPUT_PULLUP),
  ezButton(BUTTON_PINS[4], INPUT_PULLUP),
  ezButton(BUTTON_PINS[5], INPUT_PULLUP),
  ezButton(BUTTON_PINS[6], INPUT_PULLUP),
  ezButton(BUTTON_PINS[7], INPUT_PULLUP)
};

int button_counts[NUM_BUTTONS] = {0};

void initializeButtons() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    buttons[i].setDebounceTime(DEBOUNCE_TIME);
  }
}

#endif
