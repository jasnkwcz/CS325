//Joshua Sienkiewicz
//CS325 - homework 1
//Merge Sort application

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


//function prototypes
void merge (int arr[], int p, int q, int r);
void mergeSort (int arr[], int p, int r);
void displayArray (int arr[], int length);
int* makeArray(int length);
void mergeSort(int arr[], int first, int last);
void merge(int arr[], int p, int q, int r);

int main () {
    //create file i/o instance for reading input from file
    fstream infile;
    infile.open("data.txt");

    //check if file was opened correctly. if not, exit with code 1
    if (!infile.is_open()) {
        cout << "File could not be opened. Goodbye.";
        exit(1);
    } 
    
    //check if file open successful; if not, exit with code 1

    //create file i/o instance for output file
    fstream outfile; 
    outfile.open("merge.out");
    
    //message to confirm file open, used for debugging
    cout << "File opened successfully." << endl;

    //iterate through each line of the file. first value read determines the size of a new integer array. loop ends when end of file is reached
    while (!infile.eof()) { 
        int size;

        //use first line value to determine size of array to sort
        infile >> size;

        //allocate memory for new array
        int * arr = new int [size];

        //fill array with values from file until the array is full (end of line is reached)
        for (int i = 0; i < size; ++i) {
            infile >> arr[i];
        }

        //display the unsorted array
        cout << "Unsorted array: ";
        displayArray(arr, size);

        //run mergeSort on the unsorted array
        mergeSort(arr, 0, size - 1);

        //display the sorted array
        cout << "Sorted Array: ";
        displayArray(arr, size);
    }
    //close files and end program
    outfile.close();
    infile.close();
    return 0;
}

/*
mergeSort recursively calls itself to sort the array passed in the first argument. If first and last are equal (indicating a trivially sorted array of 
    length 1), then function call terminates without doing anything. otherwise, calculate the middle index "middle" of the array and recursively calls
    itself on arr[0,middle] and arr[middle+1,last], splitting the array and then sorting each half of the array, then merging both halves together in the merge
    subroutine
*/
void mergeSort(int arr[], int first, int last) {
    if (first < last) {
        int middle = (first + last) / 2;
        mergeSort(arr, first, middle);
        mergeSort(arr, middle + 1, last);
        merge(arr, first, middle, last);
    }
    return;
}


/*
merge subroutine for the mergeSort function. copies arr into two smaller already sorted subarrays, then merges them into a single sorted array
*/
void merge(int arr[], int p, int q, int r) {

    
    int m = q - p + 1; //length of the left array
    int n = r - q; //length of the right array

    //initialize iterating variables
    int i = 0; 
    int j = 0;
    int k = 0;

    //allocate memory for subarrays
    int * left = makeArray(m);
    int * right = makeArray(n);

    //copy values from the left half of arr into the left array
    for (i = 0; i < m; ++i) { 
        left[i] = arr[p + i];
    }
    //copy values from the right half of arr into the right array
    for (j = 0; j < n; ++j) {
        right[j] = arr[q + j + 1];
    }

    //reset the iterative variables to zero to begin iteration through each of the subarrays
    i = 0; 
    j = 0;
    k = p;

    //compares the contents of each sorted subarray and inserts the smaller value back into the original array
    while (i < m && j < n) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    //copy any leftover contents of the left and right subarrays back into the original array. assumes that only one of the subarrays will be nonempty
    while (i < m) {
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while (j < n) {
        arr[k] = right[j];
        ++j;
        ++k;
    }

    return;
}


/*
displayArray function to display the contents of an array of size "length"
*/
void displayArray (int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << arr[i] << ", ";
        if (i == length-1) {
            cout << "\n";
        }
    }
}

/*
allocate memory for a new array of size "length", return a pointer to the newly created array
*/
int* makeArray(int length) {
    int* newArray = new int[length];
    return newArray;
}