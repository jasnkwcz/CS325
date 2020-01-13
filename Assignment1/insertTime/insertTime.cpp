//Joshua Sienkiewicz
//CS325 - homework 1
//Insertion Sort application

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

//prototypes for functions
void insertionSort(int arr[], int length);
void displayArray(int arr[], int length);
void fillArray(int arr[], int length);
int* makeArray(int length);


int main () {
    int num;
    std::cout << "Please enter the size of the array you'd like to sort: ";
    std::cin >> num;
    int * arr = makeArray(num);
    fillArray(arr, num);
    clock_t start = clock();
    insertionSort(arr, num);
    clock_t end = clock() - start;
    std::cout << "Execution time for array of size " << num << ": " << end << " ticks." << std::endl;
    return 0;
}

/*

*/
void fillArray(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % 10000;
    }
    return;
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