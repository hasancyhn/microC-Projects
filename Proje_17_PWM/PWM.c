char dutyCycle = 0; // 0-255 arasýnda deðiþken oluþturuldu.
void main() {
     TRISB = 0b00000001;  // PORTB'nin 0. pini giriþ yapýldý.
     PORTB = 0;
     CMCON = 7;  // Komparatör giriþleri kapatýldý. Tüm giriþler dijital yapýldý.

     PWM1_Init(1000);   // PWM1 frekansý 1KHz olarak ayarlandý.
     PWM1_Set_Duty(0);  // PWM1'in görev cycle'ý 0 olarak ayarlandý.
     PWM1_Start();      // PWM1 sinyali RB3 pininden verilmeye baþlandý.
     
     while(1){
              if(PORTB.RB0==1){ // Butona basýlýnca.
                   dutycycle = dutycycle + 10;
                   // dutyCycle'ýn deðerini 10'ar 10'ar arttýrýr.
                   // Böylelikle lambanýn parlaklýðý artacak.
                   if(dutycycle > 255){
                         dutycycle = 0;
                   }
                   PWM1_Set_Duty(dutycycle);
                   while(PORTB.RB0);
                   // Elimizi butondan çekene kadar bekle.                
     }
}
