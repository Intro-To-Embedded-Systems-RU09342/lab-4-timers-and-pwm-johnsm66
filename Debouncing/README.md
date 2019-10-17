# Software Debouncing
In the real world, a mechanical button when pressed, appears as multiple presses. This is do to the mechanical 
spring that causes the button to "bounce" back and forth once pressed. As the button is oscilating it is acting
like it is being pressed mutliple times. Using a button interrupt and a timer, there is a delay set before the 
button can be pressed again. This delay cancels the oscilation or bounce of the button.

## Processors
- MSP430FR6989
- MSP430G2553

### Differences
The only difference is the pin numbers on the two board for the LEDs and button.