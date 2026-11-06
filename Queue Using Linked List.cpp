05 – Queue Using Linked List
..Enqueue
..Dequeue
..Display
..Peek


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = new Node{value, NULL};

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " inserted\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = front;

    cout << "Deleted: " << temp->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void peek() {
    if (front == NULL)
        cout << "Queue is empty\n";
    else
        cout << "Front element: " << front->data << endl;
}

void display() {
    Node* temp = front;

    if (temp == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    peek();

    dequeue();

    display();

    return 0;
}
