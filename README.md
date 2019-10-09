# polynomial.cpp

This program accepts input from a file and uses a list to store and 
manipulate the terms of a polynomial with integer coefficients.

The input file contains pairs of coefficients and exponents 
corresponding to the terms of a polynomial of degree d. Only those 
terms with non-zero coefficients will be represented. 

The coefficient of the degree-d term will always be non-zero. 
For example, the input for the polynomial 0 + 3x + 0x^2 + 5x^3 + 7x^4 
will appear in the input as 4 3 1 5 3 7 4, where the leftmost number 
indicates the degree d of the polynomial. 

After reading in each polynomial and storing them in a list, 
this program creates and prints two new lists: one that holds 
the derivative of the input polynomial and one that holds a new 
polynomial obtained by subtracting the derivative polynomial 
from the original polynomial.
