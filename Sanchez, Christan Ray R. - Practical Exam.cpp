#include <iostream>
#include <array>
using namespace std;

/*Write a C++ program to create an array of 10 integers and display the array items. Access individual elements through indexes and compute for the sum*/


int main() {
	int array[10]; // Array of the 10 integers
	int sum = 0;


	cout << "Enter 10 integers:" << endl;
	//To input the 10 integers and then stored in the array
	for (int i = 0; i < 10; i++) {
		cin >> array[i];
	}

	cout << "Array items at their specific index :" << endl;

	//accessing their individual elements thorugh indexes and to compute for their sum.
	for (int i = 0; i < 10; i++) {
		cout << "Element at index " << i << ": " << array[i] << endl;
		sum += array[i];
	}
	cout << "The Sum of the elements in the array: " << sum << endl;

	return 0;
}
