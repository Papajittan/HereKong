#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27 , 16, 2);

const int redLED = 2; const int blueLED = 3; const int greenLED = 4; const int yellowLED = 5; const int redButton = 9; const int blueButton = 8; const int greenButton = 7; const int yellowButton = 6; unsigned long Time = millis(); int over = 2000; bool overr = false;bool start = false;int score = 0;bool rediff = false; 

void setup()
{
  pinMode(2, OUTPUT); pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT); pinMode(9, INPUT_PULLUP); pinMode(8, INPUT_PULLUP); pinMode(7, INPUT_PULLUP); pinMode(6, INPUT_PULLUP);
}

void loop() {
  score = 0;
  overr = false;
  if(start == false && rediff == false){
    lcd.init();
    lcd.backlight();
    lcd.print("Select Difficulty!");
    while(true){
    digitalWrite(blueLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    delay(500);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    delay(500);
    if (digitalRead(blueButton) == LOW) {
    digitalWrite(blueLED, HIGH);
    over = 500;
    lcd.init();
    lcd.backlight();
    lcd.setCursor(2, 0);
    lcd.print("Difficulty:");
    lcd.setCursor(6, 1);
    lcd.print("HARD");
    delay(2000);
    digitalWrite(blueLED, LOW);
      start = true;
      break;
  } else if (digitalRead(greenButton) == LOW) {
    digitalWrite(greenLED, HIGH);
    over = 1000;
    lcd.init();
    lcd.backlight();
    lcd.setCursor(2, 0);
    lcd.print("Difficulty:");
    lcd.setCursor(5, 1);
    lcd.print("NORMAL");
    delay(2000);
    digitalWrite(greenLED, LOW);
      start = true;
      break;
  } else if (digitalRead(yellowButton) == LOW) {
    digitalWrite(yellowLED, HIGH);
    over = 2000;
    lcd.init();
    lcd.backlight();
    lcd.setCursor(2, 0);
    lcd.print("Difficulty:");
    lcd.setCursor(6, 1);
    lcd.print("EASY");
    delay(2000);
    digitalWrite(yellowLED, LOW);
      start = true;
      break;
  }
    }
 }
  rediff = false;
  lcd.init();
  lcd.backlight();
  lcd.print("Hold the button");
  lcd.setCursor(3, 1);
  lcd.print("to begin");
  while (true) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    delay(500);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    delay(500);
    if (digitalRead(redButton) == LOW || digitalRead(yellowButton) == LOW) {
      break;
    }
  }
  if(digitalRead(yellowButton) == LOW ){
      digitalWrite(yellowLED, HIGH);
      delay(2000);
      digitalWrite(yellowLED, LOW);
      start = false;
  }
    if (digitalRead(redButton) == LOW) {
    lcd.init();
    lcd.backlight();
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    lcd.print("Starting...");
    delay(2000);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    lcd.init();
    lcd.backlight();
    lcd.print("Score:");
    lcd.setCursor(7, 0);
    lcd.print(score);
    while(true)
    {
      if (overr == true) {
        break;
      }
      digitalWrite(random(2, 6), HIGH);
      Time = millis();
      while (digitalRead(redLED) == HIGH || digitalRead(blueLED) == HIGH || digitalRead(greenLED) == HIGH || digitalRead(yellowLED) == HIGH)
      {
        if ((millis() - Time) > over) {
          overr = true;
          Serial.println(millis());
          Serial.println(Time);
          break;
        }
        if (digitalRead(redLED) == HIGH)
        {
          if (digitalRead(redButton) == LOW)
          {
            while(digitalRead(redButton) == LOW);
            digitalWrite(redLED, LOW);
            lcd.setCursor(7, 0);
            score++;
            lcd.print(score);
          } else if (digitalRead(blueButton) == LOW || digitalRead(greenButton) == LOW || digitalRead(yellowButton) == LOW) {
            overr = true;
            break;
          }
        }

        if (digitalRead(blueLED) == HIGH)
        {
          if (digitalRead(blueButton) == LOW)
          {
            while(digitalRead(blueButton) == LOW);
            digitalWrite(blueLED, LOW);
            lcd.setCursor(7, 0);
            score++;
            lcd.print(score);
          } else if (digitalRead(redButton) == LOW || digitalRead(greenButton) == LOW || digitalRead(yellowButton) == LOW) {
            overr = true;
            break;
          }
        }

        if (digitalRead(greenLED) == HIGH)
        {
          if (digitalRead(greenButton) == LOW)
          {
            while(digitalRead(greenButton) == LOW);
            digitalWrite(greenLED, LOW);
            lcd.setCursor(7, 0);
            score++;
            lcd.print(score);
          } else if (digitalRead(redButton) == LOW || digitalRead(blueButton) == LOW || digitalRead(yellowButton) == LOW) {
            overr = true;
            break;
          }
        }

        if (digitalRead(yellowLED) == HIGH)
        {
          if (digitalRead(yellowButton) == LOW)
          {
            while(digitalRead(yellowButton) == LOW);
            digitalWrite(yellowLED, LOW);
            lcd.setCursor(7, 0);
            score++;
            lcd.print(score);
            
          } else if (digitalRead(redButton) == LOW || digitalRead(blueButton) == LOW || digitalRead(greenButton) == LOW) {
            overr = true;
            break;
          }
        }
        delay(100);
      }

    }
    if(overr == true){
    for (int i = 0; i < 3; i++) {
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, HIGH);
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, HIGH);

      delay(500);

      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);

      delay(500);
    }
    }
    if (overr == true) {
      lcd.init();
      lcd.backlight();
      lcd.setCursor(3, 0);
      lcd.print("GAME OVER!");
      lcd.setCursor(0, 1);
      lcd.print("Your score: ");
      lcd.print(score);
      overr = false;
      while(true){
        digitalWrite(redLED, HIGH);
        digitalWrite(yellowLED, HIGH);
        delay(500);
        digitalWrite(redLED, LOW);
        digitalWrite(yellowLED, LOW);
        delay(500);
        if(digitalRead(redButton) == LOW){
          start = false;3
          break;
        }else if(digitalRead(yellowButton) == LOW){
          rediff = true;
          start = false;
          break;
        }
      }
    }
//    } else {
//      lcd.init();
//      lcd.backlight();
//      lcd.setCursor(4, 0);
//      lcd.print("YOU WON!");
//      lcd.setCursor(0, 1);
//      lcd.print("Your score: ");
//      lcd.print(score);
//      overr = false;
//      start = false;
//      while(true){
//        digitalWrite(redLED, HIGH);
//        delay(500);
//        digitalWrite(redLED, LOW);
//        delay(500);
//        if(digitalRead(redButton) == LOW){
//          break;
//        }
//      }
    }
  }
