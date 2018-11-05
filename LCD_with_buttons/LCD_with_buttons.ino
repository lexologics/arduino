#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int serial_in;

void setup() {
  lcd.begin(16,2);
  /*  uncomment for test 1
  lcd.print("lexologics.nl");
  lcd.setCursor(0,1);
  lcd.print("TEST LCD");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  */

  // uncomment for button test
  lcd.setCursor(0,0);
  lcd.print("LCD Key Shield");
  lcd.setCursor(0,1);
  lcd.print("Press A key: ");
  Serial.begin(9600);
}


void loop() {
  /* test 1
  for(int lcd_cursor=0; lcd_cursor<32; lcd_cursor++) {
    if (lcd_cursor == 15) lcd.setCursor(0,1);
    else if (lcd_cursor == 31) lcd.home();
    while(!Serial.available());
    serial_in = Serial.read();
    lcd.write(serial_in);
    */       

    int x;
    int intUp;
    x = analogRead(0);
    lcd.setCursor(0,1);

    if (x < 99) {
      lcd.print("Pressed Right   ");
      Serial.print("A0 (Right key) = ");
      Serial.println(x,DEC);
    }
    else if (x < 100) {
      intUp = intUp + 1;
      lcd.print("Pressed Up      ");
      Serial.print("A0 (Up key) = ");
      Serial.println(x,DEC);
      Serial.println(intUp);
    }    
    else if (x < 400) {
      lcd.print("Pressed Down     ");
      Serial.print("A0 (Down key) = ");
      Serial.println(x,DEC);
    }       
    else if (x < 600) {
      lcd.print("Pressed Left     ");
      Serial.print("A0 (Left key) = ");
      Serial.println(x,DEC);
    }       
    else if (x < 800) {
      lcd.print("Pressed Select    ");
      Serial.print("A0 (Select key) = ");
      Serial.println(x,DEC);
    }   
    /*
    
    else if (x = 639) {
      lcd.print("Select");
      Serial.print("Select Key is pressed. (A0 = ");
      Serial.print(x,DEC);
      Serial.println(")");
    }
    */
  
}
