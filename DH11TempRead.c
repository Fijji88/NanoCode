#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000UL //16MHz clock speed
#endif


int extraTime = 0;

int main(void)
{
    DDRB = 0xFF;
    TCCR0A = (1 << WGM01); //set CTC bit
    OCR0A = 195;
    TIMSK0 = (1 << OCIE0A);
    
    sei();

    TCCR0B = (1 << CS02) | (1 << CS00); //start at 1024 prescalar

    while(1)
    {
        
    }
}

ISR(TIMER0_COMPA_vect)
{
    extraTime++;
    if(extraTime > 100)
    {
        PORTB ^= (1 << PORTB5);
        extraTime = 0;
    }
}
