void main() {
     TRISB.RB0 = 0;	//TRISB.F0 = 0;
     TRISB.F1 = 1;
/*   PORTB.RB0 = 1;
     delay_ms(1000);
     PORTB.RB0 = 0;  */

while(1){
     PORTB.RB0 = 1;
     delay_ms(1000);
     PORTB.RB0 = 0;
     delay_ms(1000);
     }
// Eðer while'ý kullanmaycaksan
// while'ý yorum satýrýna al.
// Eðer while'ý kullanacaksan
// void içinden itibaren
// 3,4 ve 5. satýrlarý yoruma al.
}
// BU FONKSÝYON SADECE TEK PIN'IN RENGÝNÝ
// 1 SN ARALIKLARLA KIRMIZI YAPIYOR.
