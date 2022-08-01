# TrueRandom-D6-for-stm32_f446re-
Using a Nucleo Board integrated with an stm32f446re to generate a random number between 1~6 and showing the result using 7 LEDs arranged to look like a common dice.
The original goal was to use the library Time.h to generate a time-based seed to the random number generator, as it proved to be a very dificult task since the stm32f446re doesn't have a internal RTC, it would have to be added externally, instead I decided to use one of the internal counters which would also add way too much complexity to the software, then I ultimately decided to use a more simple for loop with a integer-type variable up to 20000 which most certainly can't be calculated nor eyeballed to achieve certain result on the D6 dice, since the point which the variable will be stopped is completely random, thats my best approach to a true-random number generator.

*I'd like to remind that this is a school project and being such it is full of garbage and all the knowlage came from the voices in my head, please don't take this as a seriou project nor apply any of this "code" to any project/work you care about.

*also, first time publishing anything to github! 

*next change will be purely grammar correction.
