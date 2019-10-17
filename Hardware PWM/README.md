# Hardware PWM
For hardware PWM, an onboard LED is set to 50% of the duty cycle. When an onboard button is pressed, the LEDs duty cycle is 
increasd by 10%. Once the LED reaches 100% duty cycle, it is then reset to 0%. The button will still increase the 
duty cyle of the LED by 10% when pressed after reset. This process will occur as long as the board is recieving 
power. 

## Code
The reason this is Hardware PWM is because the PWM functionality of the timer peripherals are used on the chip. 
There is also another timer used to debounce the button to optimize the accuracy.

## Processors 
- MSP430FR6989
- MSP430G2553

### Differences
The only differences are the pin numbers for the LEDs and the buttons on the boards.