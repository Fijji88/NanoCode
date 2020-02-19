#ifndef F_CPU
#define F_CPU 16000000UL //16MHz clock speed
#endif


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0xFF; //Make PORTC as Output
    while(1)
    {
        PORTC = 0xFF; //Turn on all LEDs
        _delay_ms(1000.0); //1 second delay
        PORTC = 0x00; //Turn off all LEDs
        _delay_ms(1000.0); //1 second delay
    }
}
