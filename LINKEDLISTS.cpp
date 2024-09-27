#include<iostream>
#include<utility>
using namespace std;

// Define the Node class
class Node {
public:
	char data;
	Node* next;
};

// Function to insert a node at the head
void insertAtHead(Node** head_ref, char new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

// Function to insert a node at the end (tail)
void insertAtEnd(Node** head_ref, char new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = nullptr;

	if (*head_ref == nullptr) {
		*head_ref = new_node;
		return;
	}

	Node* last = *head_ref;
	while (last->next != nullptr) {
		last = last->next;
	}

	last->next = new_node;
}

// Function to insert a node after a given node
void insertAfter(Node* prev_node, char new_data) {
	if (prev_node == nullptr) {
		cout << "Previous node cannot be null." << endl;
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

// Function to delete a node by value
void deleteNode(Node** head_ref, char key) {
	Node* temp = *head_ref;
	Node* prev = nullptr;

	if (temp != nullptr && temp->data == key) {
		*head_ref = temp->next;
		delete temp;
		return;
	}

	while (temp != nullptr && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == nullptr) return;

	prev->next = temp->next;
	delete temp;
}

// Function to traverse and print the linked list
void ListTraversal(Node* n) {
	while (n != nullptr) {
		cout << n->data;
		n = n->next;
	}
	cout << endl;
}

int main() {
	// Step 1: Initialize the nodes
	Node *head = nullptr;
	Node *second = nullptr;
	Node *third = nullptr;
	Node *fourth = nullptr;
	Node *fifth = nullptr;
	Node *last = nullptr;

	// Step 2: Allocate memory for each node
	head = new Node;
	second = new Node;
	third = new Node;
	fourth = new Node;
	fifth = new Node;
	last = new Node;

	// Step 3: Set data and link the nodes
	head->data = 'C';
	head->next = second;

	second->data = 'P';
	second->next = third;

	third->data = 'E';
	third->next = fourth;

	fourth->data = '1';
	fourth->next = fifth;

	fifth->data = '0';
	fifth->next = last;

	last->data = '1';
	last->next = nullptr;

	// Task a: Traverse and display the initial list
	cout << "Initial linked list: ";
	ListTraversal(head);

	// Task b: Insert 'G' at the head
	insertAtHead(&head, 'G');
	cout << "After inserting 'G' at the start: ";
	ListTraversal(head);  // Output: GCPE101

	// Task c: Insert 'E' after 'P'
	insertAfter(second, 'E');
	cout << "After inserting 'E' after 'P': ";
	ListTraversal(head);  // Output: GCPEE101

	// Task d: Delete node containing 'C'
	deleteNode(&head, 'C');
	cout << "After deleting 'C': ";
	ListTraversal(head);  // Output: GPEE101

	// Task e: Delete node containing 'P'
	deleteNode(&head, 'P');
	cout << "After deleting 'P': ";
	ListTraversal(head);  // Output: GEE101

	// Task f: Final display of the linked list
	cout << "Final linked list: ";
	ListTraversal(head);  // Output: GEE101

	return 0;
}
