Joshua Sienkiewicz
CS325 - Homework 1, problem 5
Insertion sort application

This application implements the insertion sort algorithm. The program takes user input to determine the size of array to sort. Once the user enters the number of elements they want to sort, the program sorts the array and prints the execution time of the algorithm to the console in the number of ticks of the clock. Note that there is no data validation for the user's input, due to time constraints. The user must enter a nonnegative integer as input; if not, the program will terminate before sorting.

In order to run this program, the user should input the following shell commands in the program directory:

    g++ insertTime.cpp {compiles the program using g++}
    ./a.out {runs the program executable file}