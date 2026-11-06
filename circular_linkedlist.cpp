---Circular_Singly_Linked_List
..Insertion and deletion
..Traversal
..Searching


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void insertBeginning(int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void deleteNode(int value) {
    if (head == NULL) return;

    Node *temp = head, *prev = NULL;

    do {
        if (temp->data == value) {
            if (temp->next == temp) {
                head = NULL;
            } else {
                if (temp == head) {
                    Node* last = head;
                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;
                } else {
                    prev->next = temp->next;
                }
            }

            delete temp;
            return;
        }

        prev = temp;
        temp = temp->next;
    } while (temp != head);
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to Head)\n";
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "Circular Linked List: ";
    display();

    insertBeginning(5);
    cout << "After Insertion: ";
    display();

    deleteNode(20);
    cout << "After Deletion: ";
    display();

    return 0;
}
