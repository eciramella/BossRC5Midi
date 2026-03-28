#ifndef DISPLAYS_H
#define DISPLAYS_H

#include <LiquidCrystal_I2C.h>

const int NUM_DISPLAYS = 8;

const int LCD_ADDRESSES[NUM_DISPLAYS] = {0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20};
const char* DISPLAY_LABELS[NUM_DISPLAYS] = {
  "Track Up        ",
  "Track Down      ",
  "Redo/Undo       ",
  "Clear           ",
  "Tap Tempo       ",
  "Drum Start      ",
  "Drum Stop       ",
  "All Start/Stop  "
};

LiquidCrystal_I2C displays[NUM_DISPLAYS] = {
  LiquidCrystal_I2C(LCD_ADDRESSES[0], 16, 2),
  LiquidCrystal_I2C(LCD_ADDRESSES[1], 16, 2),
  LiquidCrystal_I2C(LCD_ADDRESSES[2], 16, 2),
  LiquidCrystal_I2C(LCD_ADDRESSES[3], 16, 2),
  LiquidCrystal_I2C(LCD_ADDRESSES[4], 16, 2),
  LiquidCrystal_I2C(LCD_ADDRESSES[5], 16, 2),
  LiquidCrystal_I2C(LCD_ADDRESSES[6], 16, 2),
  LiquidCrystal_I2C(LCD_ADDRESSES[7], 16, 2)
};

void initializeDisplays() {
  for (int i = 0; i < NUM_DISPLAYS; i++) {
    displays[i].init();
    displays[i].backlight();
    displays[i].setCursor(0, 0);
    displays[i].print(DISPLAY_LABELS[i]);
  }
}

void displayMessage(int displayIndex, const char* message) {
  if (displayIndex >= 0 && displayIndex < NUM_DISPLAYS) {
    displays[displayIndex].clear();
    displays[displayIndex].print(message);
  }
}

#endif
