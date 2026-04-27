#include <iostream>
#include <string>

using namespace std;

struct Node
    {
    int data;
    Node* left;
    Node* right;
    };

Node* createNode(int value)
{
    Node* node = new Node;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insertInTree(Node* root, int value)
{
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertInTree(root->left, value);
    }
    else
        if (value > root->data)
    {
        root->right = insertInTree(root->right, value);
    }
    return root;
}

void inOrder(Node* root) {
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

bool search(Node* root, int value) {
    if (root == nullptr)
        return false;
    if (value == root->data)
        return true;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

void freeMemory (Node* root)
{
    if (root == nullptr)
        return;
    freeMemory(root->left);
    freeMemory(root->right);
    delete root;
}

void buildEvenOddTree(Node* root, Node*& evenTree, Node*& oddTree) {
    if (root == nullptr)
        return;
    if (root->data % 2 == 0) {
        evenTree = insertInTree(evenTree, root->data);
    }
    else {
        oddTree = insertInTree(oddTree, root->data);
    }
    buildEvenOddTree(root->left, evenTree, oddTree);
    buildEvenOddTree(root->right, evenTree, oddTree);
}


int main() {
srand(time(NULL));

    int n;
    cout << "Enter the number of elements in the tree: ";
    cin >> n;
    if (n < 0) {
        cerr << "Error: The number of elements in the tree must be positive." << endl;
    }

    int mode;
    cout << "Enter the enter mode"
    << "1 - keyboard" << "2 - random: ";
    cin >> mode;

    Node* root = nullptr;

    if (mode == 1) {
        cout << "Enter the elements of the tree: ";
        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            root = insertInTree(root, value);
        }
    }
    else {
        int leftSide, rightSide;
        cout << "Enter a left side of tree: " << endl;
        cin >> leftSide;
        cout << "Enter a right side of tree: " << endl;
        cin >> rightSide;

        if (leftSide > rightSide) {
            cerr << "Error: The left side of the tree must be less than the right side." << endl;
        }
        if (n > (rightSide - leftSide)) {
            cerr << "Error: The number of elements in the tree must be less than the difference of the left and right sides." << endl;
        }

        for (int i = 0; i < n; i++) {
            int value;
            value = leftSide - rand() % (rightSide - leftSide + 1);
            root = insertInTree(root, value);
        }
    }

    cout << "The tree is: " << endl;
    inOrder(root);
    cout << endl;

   int value;
    cout << "Enter the value to search: ";
    cin >> value;

    if (search(root, value))
        cout << "The value is in the tree." << endl;
    else
        cout << "The value is not in the tree." << endl;

    Node* evenTree = nullptr;
    Node* oddTree = nullptr;
    buildEvenOddTree(root, evenTree, oddTree);

    cout << "The even tree is: " << endl;
    inOrder(evenTree);
    cout << endl;

    cout << "The odd tree is: " << endl;
    inOrder(oddTree);

    freeMemory(root);
    freeMemory(evenTree);
    freeMemory(oddTree);

}