void main() {
     int i=0;
     int gelen_deger = 0;
     TRISB = 0;
     PORTB = 0;
     TRISD.rd0 = 1;
     PORTD.rd0 = 0;
while(1){
     gelen_deger = PORTD.rd0;
     PORTB = i;
     delay_ms(100);
     i++;
     delay_ms(100);
     }
}

