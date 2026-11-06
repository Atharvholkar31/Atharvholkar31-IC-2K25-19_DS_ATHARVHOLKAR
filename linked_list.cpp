01_Singly_Linked_List

- Insertion at beginning
- Insertion at end
- Insertion at a position
- Deletion from beginning
- Deletion from end
- Deletion by value
- Searching and traversal
- Reversing a linked list


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void insertEnd(int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteNode(int value) {
    if (head == NULL) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL &&
           temp->next->data != value)
        temp = temp->next;

    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void search(int value) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Element not found\n";
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void reverseList() {
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "Original List: ";
    display();

    insertBeginning(5);
    cout << "After Insertion: ";
    display();

    deleteNode(20);
    cout << "After Deletion: ";
    display();

    search(30);

    reverseList();
    cout << "Reversed List: ";
    display();

    return 0;
}
