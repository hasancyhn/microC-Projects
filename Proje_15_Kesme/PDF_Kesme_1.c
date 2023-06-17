//interrupt initiallisation
int i = 0;
void init_interrupt(){
     option_reg.intedg=0; 	//select Interrupt on falling edge of INT0 pin
     intcon.inte=1; 		//enable port INT0 external interrupt
     intcon.PEIE=1; 		//Enables all unmasked peripheral interrupts
     intcon.gie=1; 			//enable global interrupts
}
//INT0 isr
void interrupt(){
     if(intcon.intf==1){ 	// INT0 kesintisi meydana gelirse
          portd.b0 = ~portd.b0; // toggle pin D0 (toggle komutu lojik de�erini de�i�tirir 1'se 0 yapar, 0'sa 1 yapar.
          						// �rne�in; bir led yan�yorsa kapat�r veyahut yanm�yorsa yakar.
          for(i = 0; i < 100; i++){
               porte = i;
               delay_ms(300);
          }
          intcon.intf=0; 	//reset INT0 flag mutlka s�f�rlamal�y�z
     }
}
void main(){
     init_interrupt(); 		//iterrupt initiallisation
     trisb.b0=1;			//INT0 pin as input
     trisd = 0; portd = 0; 	// D port as output
     trise = 0; porte = 0; 	// E port as output
     for(i = 0; i < 100; i++){
          portd = i;
          delay_ms(300);
     }
     while(1){
          asm sleep;
     }
}
