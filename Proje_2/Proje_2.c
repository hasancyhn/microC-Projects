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
// E�er while'� kullanmaycaksan
// while'� yorum sat�r�na al.
// E�er while'� kullanacaksan
// void i�inden itibaren
// 3,4 ve 5. sat�rlar� yoruma al.
}
// BU FONKS�YON SADECE TEK PIN'IN RENG�N�
// 1 SN ARALIKLARLA KIRMIZI YAPIYOR.
