CO321 Embedded Systems - 2022
Lab 2 - Interrupts
AVR Interrupt Programming in C


Exercises:

1. PD7 pin is connected to a push button. Write a program that uses 6 LEDs connected to
PORTB (6 LSBs) to display the number of times the push button is pressed, as a binary
number. Implement without using external interrupts. (i.e. Use polling)

2. Write a program that toggles pin PB0 (show using a connected LED) whenever the push
button is released, using external interrupts.

3. Extend the program in part 2, so that the number of times the push button was released
is displayed as a binary number on a set of LEDs connected to PORTB.

4. Connect two push buttons (A and B) to two external interrupt pins. Connect 6 LEDs to
a GPIO port. Write a program where a user can input a binary number using the two
push buttons (press A to input a '0', press B to input a '1') through external interrupts,
and display that number using the LEDs. The number must be updated and displayed
every time one of the buttons are pressed.
