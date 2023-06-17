// LCD ekranýnda yazýlan yazý 1'er karakter saða doðru hareket edecek
// bütün karakterler LCD ekranýndan çýktýktan sonra bu sefer
// yazýlan yazý 1'er karakter sola doðru hareket edecek.
// LCD pinout settings
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;

// PIN direction
sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D7_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB2_bit;

char i =0;

void main() {
     TRISA = 0;
     TRISB = 0;
     CMCON = 7;
     PORTA = 0;
     PORTB = 0;
     while(1){
              LCD_Init();
              LCD_CMD(_LCD_CLEAR);  // LCD'yi temizledik.
              delay_ms(100);
              LCD_OUT(1, 2, "MicroC");
              LCD_OUT(2, 2, "DevC");
              delay_ms(500);
              for(i=0; i<15; i++){
              Lcd_Cmd(_LCD_SHIFT_RIGHT); // Saða doðru bir karakter kaydýr.
              delay_ms(500);
              }
              for(i=0; i<15; i++){
              Lcd_Cmd(_LCD_sHIFT_LEFT);  // Sola doðru bir karakter kaydýr.
              delay_ms(100);
              }
     }
}