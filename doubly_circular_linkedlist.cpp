__Circular_Doubly_Linked_List
..Insertion and deletion
..Forward and backward traversal
..Searching


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value) {
    Node* newNode = new Node{value, NULL, NULL};

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

void insertBeginning(int value) {
    insertEnd(value);
    head = head->prev;
}

void deleteNode(int value) {
    if (head == NULL) return;

    Node* temp = head;

    do {
        if (temp->data == value) {
            if (temp->next == temp) {
                head = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;
            }

            delete temp;
            return;
        }

        temp = temp->next;
    } while (temp != head);
}

void displayForward() {
    if (head == NULL) return;

    Node* temp = head;

    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to Head)\n";
}

void displayBackward() {
    if (head == NULL) return;

    Node* temp = head->prev;

    do {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    } while (temp != head->prev);

    cout << "(Back to Last)\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "Forward: ";
    displayForward();

    cout << "Backward: ";
    displayBackward();

    insertBeginning(5);
    cout << "After Insertion: ";
    displayForward();

    deleteNode(20);
    cout << "After Deletion: ";
    displayForward();

    return 0;
}
