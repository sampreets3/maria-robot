#include "stm32f3xx.h"
#include "adc.h"

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
#include "mcp23s17.h"

/* EXAMPLE IMPLEMENTATION OF SPI:
 * Here we have used a MCP23S17 16-bit SPI based I/O expander to
 * control a LED series on PORTA, based on switch connected to
 * PORTB.
 *
 * TODO: Modify the same for use with motor-control board.
 *
 */
void setup()
{
    begin();                     // This function will configure SPI for communication.

    for (int i=0;i<8;i++)
    {  // set all 8 LED's connected to PORTA to OUTPUT mode.
       mcpPinMode(PORTA,i,OUTPUT);
    }
	// set PORTB.0 pin to INPUT_PULLUP mode.
    mcpPinMode(PORTB, 0, INPUT_PULLUP);
}


int main()
{
	static int portb;

	// call setup function to configure SPI and other peripherals.
	setup();

    while(1)
    {
       // Read PORTB register value. Based on that we will decide direction of chaser.
        portb = readBits(PORTB);
        if(portb == 0)
        {
			       // chaser will move in forward direction.
			          for (int i=0;i<8;i++)
                {
                  mcpDigitalWrite(PORTA, i, HIGH);
                  for(volatile int j = 0; j < 1000000; j++);

                  mcpDigitalWrite(PORTA, i, LOW);
                  for(volatile int j = 0; j < 1000000; j++);
                }
        }
        else
        {
	       // chaser reverses its direction when PB0 is 1.
            for (int i=7;i>=0;i--)
            {
                mcpDigitalWrite(PORTA, i, HIGH);
                for(volatile int j = 0; j < 1000000; j++);

                mcpDigitalWrite(PORTA, i, LOW);
                for(volatile int j = 0; j < 1000000; j++);
            }
        }
	}
}

#ifdef __cplusplus
 }
#endif /* __cplusplus */
