// Lcd pinout settings
sbit LCD_RS at RB4_bit; // (Register Select) = RS giriþi "0" olduðu zaman yani topraða baðlandýðý zaman LCD ekranýmýz mikroiþlemciden komut alýr hale gelir.
sbit LCD_EN at RB5_bit; // (Enable) = Enabled LCD'nin açma kapama tuþudur. Ekrana yazý yazacaðýmýz zaman PIC'ten bu bacaða açma kapama sinyali gönderilir.
sbit LCD_D7 at RB3_bit; // DATA (7-14. Bacaklar) = Bu bacaklarý PIC'imizin bir portuna baðlarýz, bu port yazdýðýmýz yazýlarý bu bacaklara iletir.
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

char txt[7]; // intToStr yapacaðýmýz için char txt[7] kalýbýný kullanýrýz.
int okunan = 0;

// ADC okunurken eðer mikroC'nin kendi ADC kütüphanesini kullanacaksak (adc_read, adc_init) sadece ADCON1 registerini
// ayarlamak yeterlidir. PIC çözünürlüðünü ADC kütüphanesi otomarik olarak (10 bit) kendisi ayarlar.
// Yani sadece ADCON1 registeri ile hangi bacaklar analog, hangi bacaklar dijital ve sonuç saða mý yoksa sola mý yaslý olacak
// bunlarý ayarlasak yeterlidir, geri kalan ADCON0 ve ADCON2 register ayarlarýný ADC kütüphanesi bizim için arka planda hallediyor.

void main() {
     ADCON1 = 0b10001110; // Bu komut ile sadece AN0 giriþi analog yapýldý diðerleri dijital 10 bit dönüþümlerde saða yaslý.
     TRISA = 0b00000001;
     PORTA = 0; // Port temizlendi.
     
     ADC_Init();
     LCD_Init();                   // LCD kütüphanesini tanýmladýk.
     LCD_CMD(_LCD_CURSOR_OFF);     // CURSOR'u kapattýk.
     LCD_CMD(_LCD_CLEAR);          // LCD'yi temizledik.
     delay_ms(10);                 // 10 ms'lik gecikme býraktýk.

     // Eðer adc_Read kullanarak programý yazarsak adc_Read hem ADC olayýný baþlatýyor hemde okuyor. Bu da çok fazla güç ve zaman kaybýna neden oluyor.
     // Bunun yerine Adc_init ve adc_Get_sample komutlarýný kullanarak programý yazarsak daha az zanman ve güç kaybý yaþarýz.
     // adc_init ADC olayýný baþlatýr. adc_get_sample ise baþlatýlan ADC iþini okumaya yarar.
     // Aralarýndaki temel fark budur.
     while (1){
           // okunan = Adc_Get_Sample(0); // AN0 kanalýndan deðer okundu ve sonuç integer tipindeki "okunan" deðiþkenine atýldý.
           okunan = Adc_Read(0); // AN0 kanalýndan deðer okundu ve sonuç integer tipindeki "okunan" deðiþkenine atýldý.
           IntToStr(okunan, txt); // okunan deðiþkeninin içeriðini LCD'de yazdýrabilmek için stringe çeviriyoruz ve txt isimli 7 karakterlik diziye aktarýyoruz.
           // okunan1 = (okunan/4);
           // IntToStr(okunan1, txt); Bu iki satýr eðer ekranda 0-255 arasýnda bir deðer görmek istiyorsak kullanýlabilir.
           lcd_out(1,1,txt);
           delay_ms(10);
     }
}
