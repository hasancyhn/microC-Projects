char dutyCycle = 0; // 0-255 aras�nda de�i�ken olu�turuldu.
void main() {
     TRISB = 0b00000001;  // PORTB'nin 0. pini giri� yap�ld�.
     PORTB = 0;
     CMCON = 7;  // Komparat�r giri�leri kapat�ld�. T�m giri�ler dijital yap�ld�.

     PWM1_Init(1000);   // PWM1 frekans� 1KHz olarak ayarland�.
     PWM1_Set_Duty(0);  // PWM1'in g�rev cycle'� 0 olarak ayarland�.
     PWM1_Start();      // PWM1 sinyali RB3 pininden verilmeye ba�land�.
     
     while(1){
              if(PORTB.RB0==1){ // Butona bas�l�nca.
                   dutycycle = dutycycle + 10;
                   // dutyCycle'�n de�erini 10'ar 10'ar artt�r�r.
                   // B�ylelikle lamban�n parlakl��� artacak.
                   if(dutycycle > 255){
                         dutycycle = 0;
                   }
                   PWM1_Set_Duty(dutycycle);
                   while(PORTB.RB0);
                   // Elimizi butondan �ekene kadar bekle.                
     }
}
