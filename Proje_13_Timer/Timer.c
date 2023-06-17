// birden fazla zaman 1. iþlem 2 saniye,
// 2. iþlem 4 saniye
// 3. iþlem 1 saniye
// 4. iþlem 5 saniye
// zamanlayýcýlar == sayaç

int sayac0 = 0;
int sayac1 = 0;
int sayac2 = 0;

void Timer0Ayar (){
// Timer 0 ayarý 10 ms
     OPTION_REG.T0CS = 0;
     OPTION_REG.PSA = 0;

     OPTION_REG.PS2 = 1;
     OPTION_REG.PS1 = 0;
     OPTION_REG.PS0 = 1;

     TMR0 = 99; //Bizim bulduðumuz deðer

     INTCON.TMR0IE = 1;
     INTCON.PEIE = 1;
     INTCON.GIE = 1;
}
// INTCON.TMR0IF == 1
void Interrupt (){
	if(INTCON.TMR0IF == 1){
		sayac0++;
		sayac1++;
		sayac2++;
		INTCON.TMR0IF == 0;
		TMR0 = 99;
		//Komutlar yazýlýr. ( Komutlar 10ms'de bir gerçekleþir.)
		if (sayac0 == 100){  // 1 saniye
			sayac0 = 0;
			PORTB = ~PORTB;
		}
		if (sayac1 == 200){ // 2 saniye
			sayac1 = 0;
			PORTC = ~PORTC;
		}
		if (sayac2 == 300){ // 3 saniye
			sayac2 = 0;
			PORTD = ~PORTD;
		}
	}
}
void main() {
	Timer0Ayar ();
    TRISB = 0;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
}