#include <MIDI.h>
#include <ezButton.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

MIDI_CREATE_DEFAULT_INSTANCE();

ezButton button1(13, INPUT_PULLUP);
ezButton button2(12, INPUT_PULLUP);
ezButton button3(11, INPUT_PULLUP);
ezButton button4(10, INPUT_PULLUP);
ezButton button5(9, INPUT_PULLUP);
ezButton button6(6, INPUT_PULLUP);
ezButton button7(5, INPUT_PULLUP);
ezButton button8(4, INPUT_PULLUP);

int dbTime = 50;
boolean reverse = false;
boolean start = false;

LiquidCrystal_I2C lcd1 (0x27, 16, 2);
LiquidCrystal_I2C lcd2 (0x26, 16, 2);
LiquidCrystal_I2C lcd3 (0x25, 16, 2);
LiquidCrystal_I2C lcd4 (0x24, 16, 2);
LiquidCrystal_I2C lcd5 (0x23, 16, 2);
LiquidCrystal_I2C lcd6 (0x22, 16, 2);
LiquidCrystal_I2C lcd7 (0x21, 16, 2);
LiquidCrystal_I2C lcd8 (0x20, 16, 2);

void setup()
{
  Serial.begin(9600);

  MIDI.begin(1);
  button1.setDebounceTime(dbTime);
  button2.setDebounceTime(dbTime);
  button3.setDebounceTime(dbTime);
  button4.setDebounceTime(dbTime);
  button5.setDebounceTime(dbTime);
  button6.setDebounceTime(dbTime);
  button7.setDebounceTime(dbTime);
  button8.setDebounceTime(dbTime);

  lcd1.init();
  lcd1.backlight();

  lcd2.init();
  lcd2.backlight();

  lcd3.init();
  lcd3.backlight();

  lcd4.init();
  lcd4.backlight();

  lcd5.init();
  lcd5.backlight();

  lcd6.init();
  lcd6.backlight();

  lcd7.init();
  lcd7.backlight();

  lcd8.init();
  lcd8.backlight();

  lcd1.setCursor(0,0);
  lcd2.setCursor(0,0);
  lcd3.setCursor(0,0);
  lcd4.setCursor(0,0);
  lcd5.setCursor(0,0);
  lcd6.setCursor(0,0);
  lcd7.setCursor(0,0);
  lcd8.setCursor(0,0);

  lcd1.print("Track Up        ");
  lcd2.print("Track Down      ");
  lcd3.print("Redo/Undo       ");
  lcd4.print("Forward.....    ");
  lcd5.print("Drum Start      ");
  lcd6.print("Drum Stop       ");
  lcd7.print("Start/Stop      ");
  lcd8.print("Clear           ");


  Serial.println("INPUT_PULLUP is ");
  Serial.println(INPUT_PULLUP);
  Serial.println("INTERNAL_PULLUP is ");
  Serial.println(INTERNAL_PULLUP);
  

  delay(1000);
}

// https://static.roland.com/assets/media/pdf/RC-5_reference_eng01_W.pdf
void loop()
{

  button1.loop();
  button2.loop();
  button3.loop();
  button4.loop();
  button5.loop();
  button6.loop();
  button7.loop();
  button8.loop();

  // should I use button1.isReleased() here instead?
  if (button1.isPressed()) // Memory up one
  {
    Serial.println("button1 pressed");
    MIDI.sendControlChange(80, 127, 1);
    delay(50);
    MIDI.sendControlChange(80, 0, 1);
    Serial.println("leaving button1 pressed");
  }

  if (button2.isPressed()) // Memory down one
  {
    Serial.println("button2 pressed");
    MIDI.sendControlChange(81, 127, 1);
    delay(50);
    MIDI.sendControlChange(81, 0, 1);
    Serial.println("leaving button2 pressed");
  }

  if (button3.isPressed()) // Redo/Undo
  {
    MIDI.sendControlChange(82, 127, 1);
    delay(50);
    MIDI.sendControlChange(82, 0, 1);
  }

  if (button4.isPressed()) // Reverse
  {
    reverse = !reverse;
    if (reverse)
    {
      lcd4.clear();
      lcd4.print("Reversing...    ");
      MIDI.sendControlChange(83, 127, 1);
      delay(50);
    } 
    else
    {
      lcd4.clear();
      lcd4.print("Forward.....    ");
      MIDI.sendControlChange(83, 0, 1);
      delay(50);
    }
  }

  if (button5.isPressed()) // Start Rhythm
  {
    MIDI.sendControlChange(84, 127, 1);
    delay(50);
    MIDI.sendControlChange(84, 0, 1);
  }

  if (button6.isPressed()) // Stop Rhythm
  {
    MIDI.sendControlChange(85, 127, 1);
    delay(50);
    MIDI.sendControlChange(85, 0, 1);
  }

  if (button7.isPressed()) // Start/stop
  {
    start = !start;
    if (start)
    {
      MIDI.sendControlChange(86, 127, 1);
      delay(50);
    }
    else 
    {
      MIDI.sendControlChange(86, 0, 1);
      delay(50);
    }
  }

  if (button8.isPressed()) // Clear
  {
    MIDI.sendControlChange(87, 127, 1);
    delay(50);
    MIDI.sendControlChange(87, 0, 1);
  }
}