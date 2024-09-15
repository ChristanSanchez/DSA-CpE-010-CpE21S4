#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
};

int main() {
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;
    Node* four = NULL;
    Node* five = NULL;
   
    one= new Node();
    two=new Node();
    three=new Node();
    four=new Node();
    five=new Node();
   
    one->value=1;
    two->value=2;
    three->value=3;
    four->value=4;
    five->value=5;
   
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    five->next=NULL;
   
    head=one;
    while(head!=NULL){
        cout<<head->value;
        head = head -> next;
    }
}