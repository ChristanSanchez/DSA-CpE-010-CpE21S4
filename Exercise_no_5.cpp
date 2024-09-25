#include <iostream>
#include <stack>
using namespace std;
#define MAX_SIZE 3

string checkFull(stack<string>& st) {
    if (st.size() == MAX_SIZE) {
        return "Stack is Full";
    } else {
        return "Stack is not Full";
    }
}

string checkEmpty(stack<string>& st) {
    if (st.empty()) {
        return "Stack is Empty";
    } else {
        return "Stack is not Empty";
    }
}

void display(stack<string> st) {
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl << "Stack is Empty" << endl;
}

int main() {
    stack<string> st;

    cout << "==============================" << endl;
    cout << "Push elements into stack" << endl;
    cout << "==============================" << endl << endl;

    st.push("1) C++");
    st.push("2) Python");
    st.push("3) Java");

    cout << checkFull(st) << endl << endl;

    cout << "Stack contents:" << endl;
    display(st);

    cout << "==============================" << endl;
    cout << "After popping all the contents" << endl;
    cout << endl;
    cout << checkEmpty(st) << endl;

    cout << endl;
    cout << "==============================" << endl;

    return 0;
}
