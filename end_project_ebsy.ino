#include <LiquidCrystal_I2C.h>
#include <Wire.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
const int JOYSTICK_X_PIN = A0;
const int JOYSTICK_Y_PIN = A1;
const int LCD_SDA_PIN = A2;
const int LCD_SCL_PIN = A3;
const int JOYSTICK_BTN_PIN = 2;
 
int xValue = 0;
int yValue = 0;
int btnState = 0;
 
void setup() {
  lcd.init();
  lcd.backlight();
 
  pinMode(JOYSTICK_BTN_PIN, INPUT_PULLUP);
 
  lcd.setCursor(0, 0);
  lcd.print("Joystick Demo");
  delay(2000);
 
  Serial.begin(9600);
}
 
void loop() {
  xValue = analogRead(JOYSTICK_X_PIN);
  yValue = analogRead(JOYSTICK_Y_PIN);
  btnState = digitalRead(JOYSTICK_BTN_PIN);

  lcd.clear();
 
  // Display the X and Y values
  lcd.setCursor(0, 0);
  lcd.print("X: ");
  lcd.print(xValue);
 
  lcd.setCursor(0, 1);  // Move to second row
  lcd.print("Y: ");
  lcd.print(yValue);
 
  // Display the button state (pressed or not pressed)
  lcd.setCursor(0, 2);
  lcd.print("Button: ");
  if (btnState == LOW) {
    lcd.print("Pressed");
  } else {
    lcd.print("Not Pressed");
  }
 
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(", Y: ");
  Serial.print(yValue);
  Serial.print(", Button: ");
 
  if (btnState == LOW) {
    Serial.println("Pressed");
  } else {
    Serial.println("Not Pressed");
  }
 
  delay(500);
}