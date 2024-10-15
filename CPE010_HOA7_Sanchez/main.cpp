#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"

void createRandomArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Random values between 0 and 99
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 100;
    int arr[size];
    
    // Create random array
    createRandomArray(arr, size);
    std::cout << "Original Array: ";
    printArray(arr, size);
    
    // Bubble Sort
    {
        int bubbleArr[size];
        std::copy(arr, arr + size, bubbleArr); // Copy original array
        bubbleSort(bubbleArr, size);
        std::cout << "Bubble Sorted Array: ";
        printArray(bubbleArr, size);
    }

    // Selection Sort
    {
        int selectionArr[size];
        std::copy(arr, arr + size, selectionArr); // Copy original array
        selectionSort(selectionArr, size);
        std::cout << "Selection Sorted Array: ";
        printArray(selectionArr, size);
    }

    // Insertion Sort
    {
        int insertionArr[size];
        std::copy(arr, arr + size, insertionArr); // Copy original array
        insertionSort(insertionArr, size);
        std::cout << "Insertion Sorted Array: ";
        printArray(insertionArr, size);
    }

    return 0;
}
