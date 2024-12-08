#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    char data;
    vector<TreeNode*> children;
    TreeNode(char val) : data(val) {}
};

class GeneralTree {
public:
    TreeNode* root;

    GeneralTree(char rootData) {
        root = new TreeNode(rootData);
    }

    TreeNode* addChild(TreeNode* parent, char childData) {
        TreeNode* child = new TreeNode(childData);
        parent->children.push_back(child);
        return child;
    }

    void preOrder(TreeNode* node) {
        if (!node) return;
        cout << node->data << " ";
        for (TreeNode* child : node->children) {
            preOrder(child);
        }
    }

    void postOrder(TreeNode* node) {
        if (!node) return;
        for (TreeNode* child : node->children) {
            postOrder(child);
        }
        cout << node->data << " ";
    }

    void inOrder(TreeNode* node) {
        if (!node) return;
        if (!node->children.empty()) {
            inOrder(node->children[0]);  // Leftmost child
        }
        cout << node->data << " ";
        for (size_t i = 1; i < node->children.size(); i++) {
            inOrder(node->children[i]);
        }
    }
};

void findData(TreeNode* node, const string& choice, char key) {
    if (choice == "PRE") {
        if (node->data == key) {
            cout << key << " was found!" << endl;
            return;
        }
        for (TreeNode* child : node->children) {
            findData(child, choice, key);
        }
    } else if (choice == "POST") {
        for (TreeNode* child : node->children) {
            findData(child, choice, key);
        }
        if (node->data == key) {
            cout << key << " was found!" << endl;
            return;
        }
    } else if (choice == "IN") {
        if (!node->children.empty()) {
            findData(node->children[0], choice, key);
        }
        if (node->data == key) {
            cout << key << " was found!" << endl;
            return;
        }
        for (size_t i = 1; i < node->children.size(); i++) {
            findData(node->children[i], choice, key);
        }
    }
};

int main() {
    GeneralTree tree('A');
    TreeNode* B = tree.addChild(tree.root, 'B');
    TreeNode* C = tree.addChild(tree.root, 'C');
    TreeNode* D = tree.addChild(tree.root, 'D');
    TreeNode* E = tree.addChild(tree.root, 'E');
    TreeNode* F = tree.addChild(tree.root, 'F');
    TreeNode* G = tree.addChild(tree.root, 'G');

    tree.addChild(D, 'H');

    tree.addChild(E, 'I');
    tree.addChild(E, 'J');
    TreeNode* P = tree.addChild(E, 'P');
    TreeNode* Q = tree.addChild(E, 'Q');

    tree.addChild(F, 'K');
    tree.addChild(F, 'L');
    tree.addChild(F, 'M');

    tree.addChild(G, 'N');

    cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Finding 'M' with pre-order traversal:" << endl;
    findData(tree.root, "PRE", 'M');
    cout << "Finding 'L' with post-order traversal:" << endl;
    findData(tree.root, "POST", 'L');
    cout << "Finding 'K' with in-order traversal:" << endl;
    findData(tree.root, "IN", 'K');
    return 0;
}
