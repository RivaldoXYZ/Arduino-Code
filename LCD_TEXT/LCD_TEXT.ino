#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int col = 16;
const int row = 4;
LiquidCrystal_I2C lcd(0x27, col, row); // Alamat I2C dan ukuran LCD (disesuaikan jika diperlukan)

int position = 0;

void setup() {
  lcd.init();
  lcd.backlight(); 
  lcd.clear();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);        
  lcd.print("SELAMAT DATANG  ");
  lcd.setCursor(0, 1);        
  lcd.print("Nomor Antrian Anda adalah : 02 ");
                                  
  delay(1000);  
}
