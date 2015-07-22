# team1
Odometer class having methods to get Previous, next and also the difference between 2 given odometer values is implemented 
in odometer.cpp.

Logic to calculate the prev value
  Starting from the rightmost digit of the number, the algorithm goes till the leftmost digit of the number to find a correct 
  position to decrement the digit. 

Logic to calculate the next value
  Starting from the rightmost digit of the number, the algorithm goes till the beginning of the number to find a correct position to increment the number
  and handle the exception case where the last number of the Odometer is given as the input, the algorithm returns the first n 
  digits combined as a string
  
Difference:
  Find the least number and find the number of next numbers till the next number which uses next() method
