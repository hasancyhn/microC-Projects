char dutycycle = 0;
char dutycycle1 = 0;
void main() {
     ADCON1 = 0b00000110 // Analog giriþler kapatýldý, tüm giriþler dijital yapýldý.
     TRISB = 0;
     TRISC = 0;
     TRISD = 0b00000011;
     
     PORTB = 0;
     PORTC = 0;
     PORTD = 0;
     
     PWM1_Init(10000); // 1. kanal PWM frekansý 10kHz olarak ayarlandý.
     PWM2_Init(10000); // 2. kanal PWM frekansý 10kHz olarak ayarlandý.
     
     PWM1_Start(); // 1. kanaldan PWM çýkýýþ baþlat.
     PWM2_Start(); // 2. kanaldan PWM çýkýýþ baþlat.
     
     PWM1_Set_Duty(0); // PWM1'in görev cycle'ý 0 olarak ayarlandý.
     PWM2_Set_Duty(); // PWM2'nin görev cycle'ý 0 olarak ayarlandý.
     
     while(1){
              if(PORTD.RD0==1){
                   PORTB.RB0 = 1;
                   PORTB.RB1 = 0;
                   dutycylce = 63;
                   PWM1_Set_Duty(dutycyle);
              }
              if(PORTD.RD1==1){
                   PORTB.RB2 = 1;
                   PORTB.RB3 = 0;
                   dutycycle = 63;
                   PWM2_Set_Duty(dutycycle1);
              }
     }
}