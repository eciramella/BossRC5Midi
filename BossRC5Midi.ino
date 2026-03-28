#include <MIDI.h>
#include <Arduino.h>
#include "buttons.h"
#include "displays.h"
#include "midi_controller.h"
#include "button_handlers.h"

MIDI_CREATE_DEFAULT_INSTANCE();

// https://static.roland.com/assets/media/pdf/RC-5_reference_eng01_W.pdf

void setup() {
  Serial.begin(9600);
  
  MIDI.begin(1);
  initializeButtons();
  initializeDisplays();
  
  delay(1000);
}

void loop() {
  updateButtonLoops();
  processButtonPresses();
  clearStartupFlag();
}