/*

Q2.
Try to increase the delay in Exercise 2 to 500ms. Talk to an instructor and explain how this
can be done, or why this cannot be done.





---->take prescaler as 1:1024 

prescaler=1:1024
TCounterClock=1024 * 1/16
            =64microsec
conter increaments needed=500 000 /64 = 7812.5
Initial counter value=1+255-7812.5
                      =it is inappropiraite



                      */