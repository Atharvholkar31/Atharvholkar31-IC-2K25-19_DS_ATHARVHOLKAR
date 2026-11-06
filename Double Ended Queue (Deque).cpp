3)Double Ended Queue (Deque)
..Insert from front
..Insert from rear
..Delete from front
..Delete from rear


#include <iostream>
using namespace std;

#define SIZE 5

int dq[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) ||
           (front == rear + 1);
}

bool isEmpty() {
    return front == -1;
}

void insertFront(int value) {
    if (isFull()) {
        cout << "Deque Overflow\n";
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else if (front == 0)
        front = SIZE - 1;
    else
        front--;

    dq[front] = value;
}

void insertRear(int value) {
    if (isFull()) {
        cout << "Deque Overflow\n";
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;

    dq[rear] = value;
}

void deleteFront() {
    if (isEmpty()) {
        cout << "Deque Underflow\n";
        return;
    }

    cout << "Deleted: " << dq[front] << endl;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void deleteRear() {
    if (isEmpty()) {
        cout << "Deque Underflow\n";
        return;
    }

    cout << "Deleted: " << dq[rear] << endl;

    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + SIZE) % SIZE;
}

void display() {
    if (isEmpty()) {
        cout << "Deque is empty\n";
        return;
    }

    int i = front;

    while (true) {
        cout << dq[i] << " ";

        if (i == rear) break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
