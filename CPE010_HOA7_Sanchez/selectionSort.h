#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>

template <typename T>
int Routine_Smallest(T arr[], int K, const int arrSize) {
    int position = K;
    T smallestElem = arr[K];

    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallestElem) {
            smallestElem = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
void selectionSort(T arr[], const int N) {
    for (int i = 0; i < N - 1; i++) {
        int POS = Routine_Smallest(arr, i, N);
        std::swap(arr[i], arr[POS]);
    }
}

#endif // SELECTIONSORT_H
