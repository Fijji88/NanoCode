#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 20000000UL //16MHz clock speed
#endif
void readTemp();

int extraTime = 0;

int main(void)
{
    // setup for rising edge interupt
    EICRA = (1 << ISC00) | (1 << ISC01); //External interupt Control register A. Set to rising edge on pin INT0.
    
    //---------------------------------
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
void readTemp()
{
/*
FUnction:
1. Make pin low for XXms.
2. Make pin input and wait for rising edge interupt.
3. Sample pin status every 50ms and save data in 1st 40bit array.
4. Sample pin status every 50ms and save data in 2st 40bit array.

*/
    DDRD = (1 << DDD3);
    EIMSK = (1 << INT1); // Enable external interupt on pin INT1.
    PORTD = (1 << PORTD3);
    PIND = (1 << PIND3);
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
