#include <iostream>
#include <cstdlib>
#include <ctime>
#include "nodes.h"
#include "searching.h"

int main() {
    // Part 1: Generate Random Dataset
    const int max_size = 50;
    int dataset[max_size];
    
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
    }

    // Part 2: Linear Search in Array
    int itemToSearchArray = dataset[10]; // Example item from dataset
    linearSearch(dataset, max_size, itemToSearchArray);

    // Part 3: Create a Linked List for Linear Search
    Node<char>* name1 = new_node('R');
    Node<char>* name2 = new_node('o');
    Node<char>* name3 = new_node('m');
    Node<char>* name4 = new_node('a');
    Node<char>* name5 = new_node('n');
    
    // Linking nodes
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = NULL;

    // Linear Search in Linked List
    linearLS(name1, 'n');

    // Part 4: Create an Ordered Linked List for Binary Search
    Node<int>* head = NULL;
    Node<int>* temp = NULL;
    Node<int>* node = NULL;
    int newData;
    char choice = 'y';
    int count = 0;

    while (choice == 'y') {
        std::cout << "Enter data: ";
        std::cin >> newData;

        if (count == 0) {
            head = new_node(newData);
            std::cout << "Successfully added " << head->data << " to the list." << std::endl;
            count++;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            node = new_node(newData);
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list." << std::endl;
            count++;
        }

        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
    }

    // Display linked list
    temp = head;
    std::cout << "Linked List: ";
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Part 5: Binary Search in Linked List
    int itemToSearchLinkedList = 5; // Example item to search in linked list
    binarySearchLinkedList(head, itemToSearchLinkedList);

    return 0;
}
