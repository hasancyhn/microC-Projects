// birden fazla zaman 1. i�lem 2 saniye,
// 2. i�lem 4 saniye
// 3. i�lem 1 saniye
// 4. i�lem 5 saniye
// zamanlay�c�lar == saya�

int sayac0 = 0;
int sayac1 = 0;
int sayac2 = 0;

void Timer0Ayar (){
// Timer 0 ayar� 10 ms
     OPTION_REG.T0CS = 0;
     OPTION_REG.PSA = 0;

     OPTION_REG.PS2 = 1;
     OPTION_REG.PS1 = 0;
     OPTION_REG.PS0 = 1;

     TMR0 = 99; //Bizim buldu�umuz de�er

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
		//Komutlar yaz�l�r. ( Komutlar 10ms'de bir ger�ekle�ir.)
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