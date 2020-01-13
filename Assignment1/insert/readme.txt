Joshua Sienkiewicz
CS325 - Homework 1
Insertion Sort Application

This program takes input from a file named "data.txt" which is formatted as a space-separated list of integers. Each line will be read as a new array with the first integer on the line being used to determine the size of the array. The remaining characters on the line are read in and copied to the new array. The new array is sorted using the Insertion Sort algorithm, and the sorted array is written to the output file "merge.out". Please note that the contents written to the output file are not appended, so "merge.out" is overwritten each time the executable is run.

To compile and run this program, from inside the program directory, run the following shell commmands:

    g++ insert.cpp -o insert.out {this compiles the program using g++ and sets the output destinaton to the file "merge.out"}
    ./insert.out {runs the program executable file}