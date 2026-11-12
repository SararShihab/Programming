#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Set Pin 13 (PB5) as OUTPUT
    DDRB |= (1 << PB5);

    while (1) {
        PORTB ^= (1 << PB5);   // Invert Pin 13 state (HIGH <-> LOW)
        _delay_ms(500);        // Wait 500 ms
    }

    return 0;
}