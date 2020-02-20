#ifndef F_CPU
#define F_CPU 16000000UL //16MHz clock speed
#endif


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0xFF; //Make PORT B as Output
    while(1)
    {
        PORTB = 0x20; //Turn on all LEDs
        _delay_ms(1000.0); //1 second delay
        PORTB = 0x00; //Turn off all LEDs
        _delay_ms(1000.0); //1 second delay
    }
}
