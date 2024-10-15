#ifndef SEARCHING_H
#define SEARCHING_H

#include <iostream>
#include "nodes.h"

// Linear Search Function for Array
void linearSearch(int arr[], int n, int item) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == item) {
            std::cout << "Searching is successful: " << item << " found at index " << i << std::endl;
            return;
        }
    }
    std::cout << "Searching is Unsuccessful: " << item << " not found in the array." << std::endl;
}

// Linear Search Function for Linked List
void linearLS(Node<char>* head, char dataFind) {
    Node<char>* current = head;
    while (current != NULL) {
        if (current->data == dataFind) {
            std::cout << "Searching is successful: " << dataFind << " found." << std::endl;
            return;
        }
        current = current->next;
    }
    std::cout << "Searching is Unsuccessful: " << dataFind << " not found in the linked list." << std::endl;
}

// Get Middle Function for Binary Search
Node<int>* getMiddle(Node<int>* start, Node<int>* last) {
    if (start == NULL) return NULL;
    Node<int>* slow = start;
    Node<int>* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

// Binary Search Function for Linked List
Node<int>* binarySearchLinkedList(Node<int>* head, int item) {
    Node<int>* start = head;
    Node<int>* last = NULL;

    while (start != last) {
        Node<int>* mid = getMiddle(start, last);

        if (mid->data == item) {
            std::cout << "Search element is found in linked list: " << item << std::endl;
            return mid;
        } else if (mid->data < item) {
            start = mid->next;
        } else {
            last = mid;
        }
    }
    std::cout << "Search element is not found in linked list: " << item << std::endl;
    return NULL;
}

#endif // SEARCHING_H
