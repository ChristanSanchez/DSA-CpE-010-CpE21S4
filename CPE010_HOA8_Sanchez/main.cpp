#include <iostream>
#include <cstdlib>
#include <ctime>
#include "shellSort.h"
#include "mergeSort.h"
#include "quickSort.h"

#define SIZE 100


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    srand(time(0));


    int arr[SIZE], shellArr[SIZE], mergeArr[SIZE], quickArr[SIZE];

    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000; 
    }


    copyArray(arr, shellArr, SIZE);
    copyArray(arr, mergeArr, SIZE);
    copyArray(arr, quickArr, SIZE);


    std::cout << "Unsorted Array: ";
    printArray(arr, SIZE);
    
std::cout<< std::endl;

    // Sorting using Shell Sort
    shellSort(shellArr, SIZE);
    std::cout << "Array after Shell Sort: ";
    printArray(shellArr, SIZE);
    
std::cout<< std::endl;

    // Sorting using Merge Sort
    mergeSort(mergeArr, 0, SIZE - 1);
    std::cout << "Array after Merge Sort: ";
    printArray(mergeArr, SIZE);
    
std::cout<< std::endl;

    // Sorting using Quick Sort
    quickSort(quickArr, 0, SIZE - 1);
    std::cout << "Array after Quick Sort: ";
    printArray(quickArr, SIZE);

    return 0;
}

