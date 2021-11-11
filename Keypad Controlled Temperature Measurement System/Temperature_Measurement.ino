#include <LiquidCrystal.h>
#include <Keypad.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4;
const byte COLS = 3;
char Keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {14,15,16,17};
byte colPins[COLS] = {8,9,10};
Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS);

void setup() {
  analogReference(INTERNAL);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(1, 0);
  lcd.print("* Welcome to our arduino project *");
  for(int counter = 0 ; counter < 25; counter++)
  {
    lcd.scrollDisplayLeft();
    delay(150);
  }
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Press - 1");
  lcd.setCursor(1, 1);
  lcd.print("for room temp");
  char customKey;
  customKey = customKeypad.waitForKey();
  lcd.clear();
  if (customKey == '1'){
    lcd.setCursor(1, 0);
    lcd.print("Select Unit - ");
    lcd.setCursor(1, 1);
    lcd.print("1-C 2-F 3-K");

    customKey = customKeypad.waitForKey();
    lcd.clear();
    float temp =(float)100*(1.1/1023)*analogRead(A4);
    if( customKey == '1')
    {
      lcd.setCursor(0, 1);
      lcd.print("Press 0 to exit.");
      lcd.setCursor(0, 0);
      lcd.print("Room tem : ");
      lcd.setCursor(9, 0);
      lcd.print(temp,2);
      lcd.print(" C");
      Serial.print("Room temperature : ");
      Serial.print(temp,2);
      Serial.println(" deg C");
      while( customKey != '0')
      { customKey = customKeypad.waitForKey(); }
      lcd.clear();
    }
    if( customKey == '2')
    {
      temp = (float) 32 + (temp*9)/5;
      lcd.setCursor(0, 1);
      lcd.print("Press 0 to exit.");
      lcd.setCursor(0, 0);
      lcd.print("Room tem : ");
      lcd.setCursor(9, 0);
      lcd.print(temp,2);
      lcd.print(" F");
      Serial.print("Room temperature : ");
      Serial.print(temp,2);
      Serial.println(" deg F");
      while( customKey != '0')
      { customKey = customKeypad.waitForKey(); }
      lcd.clear();
    }
    if( customKey == '3')
    {
      temp = (float) 273 + temp;
      lcd.setCursor(0, 1);
      lcd.print("Press 0 to exit.");
      lcd.setCursor(0, 0);
      lcd.print("Room tem : ");
      lcd.setCursor(9, 0);
      lcd.print(temp,2);
      lcd.print(" K");
      Serial.print("Room temperature : ");
      Serial.print(temp,2);
      Serial.println(" K");
      while( customKey != '0')
      { customKey = customKeypad.waitForKey(); }
      lcd.clear();
    }
    
    
    
  }
}
