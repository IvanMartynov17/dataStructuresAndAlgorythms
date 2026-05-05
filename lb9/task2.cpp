#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

struct Node  {
    int productCode;
    string productName;
    double productPrice;
    Node* left;
    Node* right;

};

Node* CreateNode(int productCode, string& productName, double productPrice) {
Node* node = new Node();
    node->productCode = productCode;
    node->productName = productName;
    node->productPrice = productPrice;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insertInTree(Node* root, int productCode, string& productName, double productPrice) {
    if (root == nullptr) {
        return CreateNode(productCode, productName, productPrice);
    }
    if (productCode < root->productCode) {
    root->right = insertInTree(root->left, productCode, productName, productPrice);
    }
    else {
        if (productCode > root->productCode) {
            root->right = insertInTree(root->right, productCode, productName, productPrice);
        }
    }
    return root;
}

int getDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}
void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->productCode << " " << root->productName << " " << root->productPrice << endl;
    printTree(root->right);
}

void calculateSum(Node* root, double& sum, double& count) {
    if (root == nullptr) {
        return;
    }
    sum += root->productPrice;
    count++;
    calculateSum(root->left, sum, count);
    calculateSum(root->right, sum, count);
}

double getAverage(Node* root) {
    double sum = 0;
    double average = 0;
    double count = 0;
   calculateSum(root, sum, count);
    average = sum / count;
    cout << "Average: " << average << endl;
    return average;
}

int countAtLevel(Node* root, int level) {
    if (root == nullptr) {
        return 0;
    }
    if (level == 0) {
        return 1;
    }
   return countAtLevel(root->left, level - 1)
    + countAtLevel(root->right, level - 1);
}

void printLevelCounts(Node* root) {
    if (root == nullptr) {
        return;
    }
    int totalDepth = 0;
    totalDepth = getDepth(root);
    for (int lvl = 0; lvl < totalDepth; lvl++) {
        cout << "Level " << lvl << ": " << countAtLevel(root, lvl) << " nodes" << endl;
    }

}

void freeTreeMemory(Node* root) {
    if (root == nullptr) {
        return;
    }
    freeTreeMemory(root->left);
    freeTreeMemory(root->right);
    delete root;
}

Node* searchNode (Node* root, int productCode) {
    if (root == nullptr) {
        return nullptr;
    }
    if (productCode == root->productCode) {
        return root;
    }
    if (productCode < root->productCode) {
        return searchNode(root->left, productCode);
    }
    return searchNode(root->right, productCode);
}

Node* deleteTreesChildren(Node* root, int productCode) {
    if (root == nullptr) {
        return nullptr;
    }
   if (productCode < root->productCode) {
       root->left = deleteTreesChildren(root->left, productCode);
    }
    else if (productCode > root->productCode) {
        root->right = deleteTreesChildren(root->right, productCode);
    }
    else {
       freeTreeMemory(root->left);
        freeTreeMemory(root->right);
        root->left = nullptr;
        root->right = nullptr;
        cout << "Node " << productCode << " deleted" << endl;
        }
    return root;
    }

int main() {
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error, can't open the file.. returning" << endl;
        return 1;
    }

    Node* root = nullptr;
    int productCode;
    string productName;
    double productPrice;

    while (file >> productCode >> productName >> productPrice) {
        root = insertInTree(root, productCode, productName, productPrice);
    }
    file.close();

    if (root == nullptr) {
        cerr << "Error, file is empty.. " << endl;
        return 1;
    }

    cout << "\tCreated tree: " << endl;
    printTree(root);

    cout << "\tAverage price: " << getAverage(root) << endl;

    cout << "\tLevel counts: " << endl;
    printLevelCounts(root);

    cout << "\tSearching for node: " << endl;
    int searchCode;
    cin >> searchCode;

    Node* foundNode = searchNode(root, searchCode);
    if (foundNode == nullptr) {
        cout << "Node with code " << searchCode << " not found" << endl;
    }
    else {
        cout << "Found node: " << foundNode->productCode
        << " "  << "Name: " << foundNode->productName
        << " " << "Price: " << foundNode->productPrice << " grn" << endl;
    }

    char answer;
    cout << "Delete node? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        root = deleteTreesChildren(root, searchCode);
        cout << "\tNew tree: " << endl;
        printTree(root);
    }

    freeTreeMemory(root);
    cout << "Memory is deleted, exit from program.. " << endl;

    return 0;
}