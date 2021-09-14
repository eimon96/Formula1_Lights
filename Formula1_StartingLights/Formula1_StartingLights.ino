// author eimon

#include <LiquidCrystal.h>

// LEDs
int s5 = 13;
int s4 = 12;
int s3 = 11;
int s2 = 10;
int s1 = 9 ;

// Buzzer
int buz = 8;

// Button
int butt = 2;
int buttPressed;

// For the LCD countdown
int counter;

// LCD
// Parameters: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd = LiquidCrystal(A0, 3, 4, 5, 6, 7);

void setup() 
{
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(s4, OUTPUT);
  pinMode(s5, OUTPUT);

  pinMode(buz, OUTPUT);
  pinMode(butt, INPUT_PULLUP);

  lcd.begin(16, 2);
}

void loop()
{
  turn_all_off();
  show_msg(1, 0, "Howdy eimon xD");
  show_msg(1, 1, "               ");
  
  buttPressed= digitalRead(butt);

  // When button is not pressed -> 1 
  // When button is pressed -> 0
  if (buttPressed == 0)
    countdown();
}

void countdown()
{
  show_msg(0, 0, "   Get ready!  ");
  counter = 5;
  
  turnOn(s1);
  turnOn(s2);
  turnOn(s3);
  turnOn(s4);
  turnOn(s5);

  delay(2000);

  turnOff(s1);
  turnOff(s2);
  turnOff(s3);
  turnOff(s4);
  turnOff(s5);
  tone(buz, 3000, 1200);
  show_msg(6, 1, "GO!");

  delay(2000); 
}

void turnOn(int pin)
{
  digitalWrite(pin, LOW);
  tone(buz, 3000, 10);
  if (counter!=0)
  {
    show_msg(7, 1, (String)counter);
    counter--;
  }
  
  delay(1000);
}

void turnOff(int pin)
{
  digitalWrite(pin, HIGH);
}

void turn_all_off()
{
  turnOff(s1);
  turnOff(s2);
  turnOff(s3);
  turnOff(s4);
  turnOff(s5);
}

void show_msg(int col, int row, String msg)
{
  lcd.setCursor(col, row);
  lcd.print(msg); 
}
