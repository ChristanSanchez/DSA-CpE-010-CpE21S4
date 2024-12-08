#include <iostream>
#include <iomanip>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

    // Insert function
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    // Display function (in-order visual representation)
    void display(TreeNode* node, int space = 0, int indent = 5) {
        if (node == nullptr) return;
        space += indent;
        display(node->right, space);
        cout << setw(space) << node->data << endl;
        display(node->left, space);
    }

    // Traversal functions
    void inOrder(TreeNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void preOrder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(TreeNode* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BinarySearchTree bst;
    int values[] = {2, 3, 9, 18, 0, 1, 4, 5};

    for (int val : values) {
        bst.insert(val);
    }

    cout << "Binary Search Tree Structure:\n";
    bst.display(bst.root);

   

    return 0;
}
