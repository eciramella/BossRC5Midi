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

int dbTime = 60;
bool reverse = false;
//boolean start = false;
bool startup = true;
int button1_count = 0;
int button2_count = 0;
int button3_count = 0;
int button4_count = 0;
int button5_count = 0;
int button6_count = 0;
int button7_count = 0;
int button8_count = 0;

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

/*
  Serial.println("INPUT_PULLUP is ");
  Serial.println(INPUT_PULLUP);
  Serial.println("INTERNAL_PULLUP is ");
  Serial.println(INTERNAL_PULLUP);
*/

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

  if(button1.isReleased()) // Memory up one
  {
    if(button1_count != button1.getCount())
    {
      basic_midi_controll(80, 1);
    }
  }

  if(button2.isReleased()) // Memory down one
  {
    if(button2_count != button2.getCount())
    {
      basic_midi_controll(81, 2);
    }
  }

  if(button3.isReleased()) // Redo/Undo
  {
    basic_midi_controll(82, 3);
  }

  if(button4.isReleased()) // Reverse
  {
    if (!startup)
    {
      reverse = !reverse;
      if (reverse)
      {
        Serial.println("button4 pressed reversing");
        lcd4.clear();
        lcd4.print("Reversing...    ");
        MIDI.sendControlChange(83, 127, 1);
        delay(50);
        Serial.println("leaving button4 pressed reversing");
      } 
      else
      {
        Serial.println("button4 pressed going forward");
        lcd4.clear();
        lcd4.print("Forward.....    ");
        MIDI.sendControlChange(83, 0, 1);
        delay(50);
        Serial.println("leaving button4 pressed going forward");
      }
    }
  }

  if (button5.isReleased()) // Start Rhythm
  {
    if(button5_count != button5.getCount())
    {
      basic_midi_controll(84, 5);
    }
  }

  if (button6.isReleased()) // Stop Rhythm
  {
    basic_midi_controll(85, 6);
  }

  if (button7.isReleased()) // Start/stop
  {
    basic_midi_controll(86, 7);
  }

  if (button8.isReleased()) // Clear
  {
    if(button8_count != button8.getCount())
    {
      button8_count = button8.getCount();
      basic_midi_controll(87, 8);
    }
  }
  
  if(startup)
  {
    Serial.print("From the loop, start up value is ");
    Serial.println(startup);
    startup = false;
  }
}

void basic_midi_controll(int midi_number, int button_number)
{
  Serial.print("startup is ");
  Serial.println(startup);
  if(!startup)
  {
    Serial.print("Button number ");
    Serial.print(button_number);
    Serial.println(" was pressed");
    MIDI.sendControlChange(midi_number, 127, 1);
    delay(50);
    MIDI.sendControlChange(midi_number, 0, 1);
    Serial.print("Leaving ");
    Serial.print(button_number);
    Serial.println(" pressed");
  }
}