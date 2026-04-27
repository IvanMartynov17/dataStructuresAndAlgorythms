#include <iostream>
#include <string>

using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = nullptr;


Node *createNode(int value) {
    Node *node = new Node;
    node->value = value;
    node->next = nullptr;
    return node;
}

void push(int value) {
    int size = 0;
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    size++;
}

void print() {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }
    Node* current = head;
    cout << "List: ";
     while (current != nullptr) {
         cout << current->value << " ";
         current = current->next;
     }
    cout << endl;
}

double average()
{
    int size = 0, sum = 0;

    if (size == 0)
        return 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->value;
        current = current->next;
        size++;
    }
    cout << "Average: " << (double)sum / size << endl;
}

void clearMemory()
    {
    Node* temp = head;
    while (head != nullptr)
        Node* temp = head;
    head = head->next;
    delete temp;
}
int main() {
    int n;
    cout << "Enter count of marks: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        {
        int grade;
        cout << "Enter grade: " << i + 1 << ": ";
        cin >> grade;
        push(grade);
    }
    print();
    average();
    clearMemory();
}