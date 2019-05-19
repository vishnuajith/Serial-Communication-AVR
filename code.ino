#define CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#define BAUD 9600
uint16_t ubrr=CPU/16/BAUD-1;

int writefn(unsigned char x)
{
  while ((UCSR0A &(1<<UDRE0)) == 0){}
  UDR0=x;
}

int main()
{
  //serial communication
  UCSR0C=(3<<UCSZ00)|(1<<USBS0);
  UCSR0B=(1<<TXEN0);
 
  //sei();
   
  //set baud rate
  UBRR0L=ubrr;
  UBRR0H=(ubrr>>8); 
  
  DDRB=0x20; //Declared as output
  
  while (1)
  {
    PORTB|=0x20;
    unsigned char i='a';
    writefn(i);
    _delay_ms(500);
    PORTB=0x00;
    _delay_ms(500);
    
  }
}
