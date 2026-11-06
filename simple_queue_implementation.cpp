01 – Simple Queue
- Insertion (Enqueue)
- Deletion (Dequeue)
- Display
- Peek / Front

#include <iostream>
using namespace std;

#define SIZE 5

int queueArr[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1)
        front = 0;

    queueArr[++rear] = value;
    cout << value << " inserted\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return;
    }

    cout << "Deleted: " << queueArr[front++] << endl;

    if (front > rear)
        front = rear = -1;
}

void peek() {
    if (front == -1)
        cout << "Queue is empty\n";
    else
        cout << "Front: " << queueArr[front] << endl;
}

void display() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }

    for (int i = front; i <= rear; i++)
        cout << queueArr[i] << " ";

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
