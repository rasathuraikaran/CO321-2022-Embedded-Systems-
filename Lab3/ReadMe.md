Write a C program to toggle an LED connected to pin 5 of PORTB register (PB5) every 2ms.
Use TIMER0, normal mode, and a suitable pre-scalar to create the delay. Assume XTAL= 16
MHz. What is the selected prescaler? What is the initial counter value? Explain the output.
What is the reason for it?



Exercise 2 :
Try to increase the delay in Exercise 2 to 500ms. Talk to an instructor and explain how this
can be done, or why this cannot be done.


Exercise 3 :
Find out the highest possible countable time interval using TIMER0, normal mode, and a
suitable pre-scalar. Assume XTAL= 16MHz. What is the selected prescaler? What is the
highest countable time interval?
(Complete and show exercises 1 to 3 on the first day of Lab3. Remaining exercises should
be finished before coming to the second day of Lab3)


Exercise 4:
Write a program that toggles an LED connected to PB5 pin every second using TIMER1,
while at the same time operating a Knight Rider style circuit of 4 LEDs (from Lab 1). For the
LED toggle you must use the timer overflow interrupts. For the Knight Rider style circuit
you are allowed use either timer interrupts, polling, software delays or any other method.



Exercise 5:
You found out the maximum interval you can implement using TIMER0 in exercise 4.
However, by using an 8-bit counter variable and interrupts, you can make this interval
much longer. Develop a program to blink an LED with a 100ms interval using TIMER0 .



Exercise 6:
Implement a program to blink two LEDs. One led should blink with an interval of 50 ms
and the other should blink with an interval of 500ms. You must use two timers, and timer
overflow interrupts.
