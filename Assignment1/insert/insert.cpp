// Example program
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//prototypes for functions
void insertionSort(int arr[], int length);
void displayArray(int arr[], int length);
void fillArray(int arr[], int length);
int* makeArray(int length);


int main () {
    //create file i/o instance for reading input from file
    fstream infile;
    infile.open("data.txt");

    //check if file was opened correctly. if not, exit with code 1
    if (!infile.is_open()) {
        std::cout << "File could not be opened. Goodbye.";
        exit(1);
    } 

    //create file i/o instance for output file
    fstream outfile; 
    outfile.open("merge.out");
    
    //message to confirm file open, used for debugging
    std::cout << "File opened successfully. \n";

    //iterate through each line of the file. first value read determines the size of a new integer array. loop ends when end of file is reached
    while (!infile.eof()) { 
        int size;

        //use first line value to determine size of array to sort
        infile >> size;

        //allocate memory for new array
        int * arr = makeArray(size);

        //fill array with values from file until the array is full (end of line is reached)
        for (int i = 0; i < size; ++i) {
            infile >> arr[i];
        }

        //display the unsorted array
        std::cout << "Unsorted array: ";
        displayArray(arr, size);

        //run mergeSort on the unsorted array
        insertionSort(arr, size);

        //display the sorted array
        std::cout << "Sorted Array: ";
        displayArray(arr, size);
    }
    //close files and end program
    outfile.close();
    infile.close();
    return 0;
}

/*
displayArray function to display the contents of an array of size "length"
*/
void displayArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i];
        if (i == length - 1) {
            std::cout << "\n";
        } else {
            std::cout << ", ";
        }
    }
    return;
}

/*
allocate memory for a new array of size "length", return a pointer to the newly created array
*/
int* makeArray(int length) {
    int* newArray = new int[length];
    return newArray;
}

/*
Implements the insertion sort algorithm on an array "arr" of size "length"
*/
void insertionSort(int arr[], int length) {
    int key;
    int i;
    for (int j = 1; j < length; ++j) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            --i;
        }
        arr[i + 1] = key;
    }
    return;
}