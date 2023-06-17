// Lcd pinout settings
sbit LCD_RS at RB4_bit; // (Register Select) = RS giri�i "0" oldu�u zaman yani topra�a ba�land��� zaman LCD ekran�m�z mikroi�lemciden komut al�r hale gelir.
sbit LCD_EN at RB5_bit; // (Enable) = Enabled LCD'nin a�ma kapama tu�udur. Ekrana yaz� yazaca��m�z zaman PIC'ten bu baca�a a�ma kapama sinyali g�nderilir.
sbit LCD_D7 at RB3_bit; // DATA (7-14. Bacaklar) = Bu bacaklar� PIC'imizin bir portuna ba�lar�z, bu port yazd���m�z yaz�lar� bu bacaklara iletir.
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;

// Pin direction
sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D7_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB0_bit;

char txt[7]; // intToStr yapaca��m�z i�in char txt[7] kal�b�n� kullan�r�z.
int okunan = 0;

// ADC okunurken e�er mikroC'nin kendi ADC k�t�phanesini kullanacaksak (adc_read, adc_init) sadece ADCON1 registerini
// ayarlamak yeterlidir. PIC ��z�n�rl���n� ADC k�t�phanesi otomarik olarak (10 bit) kendisi ayarlar.
// Yani sadece ADCON1 registeri ile hangi bacaklar analog, hangi bacaklar dijital ve sonu� sa�a m� yoksa sola m� yasl� olacak
// bunlar� ayarlasak yeterlidir, geri kalan ADCON0 ve ADCON2 register ayarlar�n� ADC k�t�phanesi bizim i�in arka planda hallediyor.

void main() {
     ADCON1 = 0b10001110; // Bu komut ile sadece AN0 giri�i analog yap�ld� di�erleri dijital 10 bit d�n���mlerde sa�a yasl�.
     TRISA = 0b00000001;
     PORTA = 0; // Port temizlendi.
     
     ADC_Init();
     LCD_Init();                   // LCD k�t�phanesini tan�mlad�k.
     LCD_CMD(_LCD_CURSOR_OFF);     // CURSOR'u kapatt�k.
     LCD_CMD(_LCD_CLEAR);          // LCD'yi temizledik.
     delay_ms(10);                 // 10 ms'lik gecikme b�rakt�k.

     // E�er adc_Read kullanarak program� yazarsak adc_Read hem ADC olay�n� ba�lat�yor hemde okuyor. Bu da �ok fazla g�� ve zaman kayb�na neden oluyor.
     // Bunun yerine Adc_init ve adc_Get_sample komutlar�n� kullanarak program� yazarsak daha az zanman ve g�� kayb� ya�ar�z.
     // adc_init ADC olay�n� ba�lat�r. adc_get_sample ise ba�lat�lan ADC i�ini okumaya yarar.
     // Aralar�ndaki temel fark budur.
     while (1){
           // okunan = Adc_Get_Sample(0); // AN0 kanal�ndan de�er okundu ve sonu� integer tipindeki "okunan" de�i�kenine at�ld�.
           okunan = Adc_Read(0); // AN0 kanal�ndan de�er okundu ve sonu� integer tipindeki "okunan" de�i�kenine at�ld�.
           IntToStr(okunan, txt); // okunan de�i�keninin i�eri�ini LCD'de yazd�rabilmek i�in stringe �eviriyoruz ve txt isimli 7 karakterlik diziye aktar�yoruz.
           // okunan1 = (okunan/4);
           // IntToStr(okunan1, txt); Bu iki sat�r e�er ekranda 0-255 aras�nda bir de�er g�rmek istiyorsak kullan�labilir.
           lcd_out(1,1,txt);
           delay_ms(10);
     }
}
