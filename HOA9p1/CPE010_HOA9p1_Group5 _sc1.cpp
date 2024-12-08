#include <iostream>
#include <vector>
using namespace std;

// TreeNode represents each node in the general tree.
struct TreeNode {
    char data; // Character data for each node (e.g., 'A', 'B', etc.)
    vector<TreeNode*> children; // List of child nodes

    // Constructor to initialize a node with a given character.
    TreeNode(char val) : data(val) {}
};

// Function to add a child node to a parent node.
void addChild(TreeNode* parent, TreeNode* child) {
    parent->children.push_back(child);
}

// Recursive function to print the tree in a structured way.
void printTree(TreeNode* root, int depth = 0) {
    if (!root) return;
    // Print indentation for each level
    for (int i = 0; i < depth; ++i) cout << "  ";
    cout << root->data << endl;
    for (TreeNode* child : root->children) {
        printTree(child, depth + 1);
    }
}

int main() {
    // Creating nodes for each character in the tree
    TreeNode* A = new TreeNode('A');
    TreeNode* B = new TreeNode('B');
    TreeNode* C = new TreeNode('C');
    TreeNode* D = new TreeNode('D');
    TreeNode* E = new TreeNode('E');
    TreeNode* F = new TreeNode('F');
    TreeNode* G = new TreeNode('G');
    TreeNode* H = new TreeNode('H');
    TreeNode* I = new TreeNode('I');
    TreeNode* J = new TreeNode('J');
    TreeNode* K = new TreeNode('K');
    TreeNode* L = new TreeNode('L');
    TreeNode* M = new TreeNode('M');
    TreeNode* N = new TreeNode('N');
    TreeNode* P = new TreeNode('P');
    TreeNode* Q = new TreeNode('Q');

    // Constructing the tree structure
    addChild(A, B);
    addChild(A, C);
    addChild(A, D);
    addChild(A, E);
    addChild(A, F);
    addChild(A, G);

    addChild(D, H);

    addChild(E, I);
    addChild(E, J);
    addChild(E, P);
    addChild(E, Q);

    addChild(F, K);
    addChild(F, L);
    addChild(F, M);

    addChild(G, N);

    // Print the tree starting from the root node
    printTree(A);

    

    return 0;
}


