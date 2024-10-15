#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node *front, *rear;
    int size, MAX_SIZE;

public:
    Queue(int maxSize) : front(nullptr), rear(nullptr), size(0), MAX_SIZE(maxSize) {}

    bool isFull() { return size == MAX_SIZE; }
    bool isEmpty() { return size == 0; }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue full! Cannot enqueue.\n";
            return;
        }
        Node* newNode = new Node(val);
        if (isEmpty()) front = rear = newNode;
        else rear->next = newNode, rear = newNode;
        size++;
        cout << "Enqueued: " << val << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue empty! Cannot dequeue.\n";
            return -1;
        }
        Node* temp = front;
        int val = front->data;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        size--;
        cout << "Dequeued: " << val << endl;
        return val;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is empty!\n"; return; }
        for (Node* temp = front; temp; temp = temp->next) cout << temp->data << " ";
        cout << endl;
    }
};

int main() {
    Queue q1(5), q2(5); // Two queues of size 5
    int choice, value;

    while (true) {
        cout << "\n1. Enqueue in Queue 1\n2. Transfer from Queue 1 to Queue 2\n"
             << "3. Dequeue from Queue 2\n4. Display Queue 1\n5. Display Queue 2\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: "; cin >> value; q1.enqueue(value);
        }
        else if (choice == 2) {
            if (!q1.isEmpty()) q2.enqueue(q1.dequeue());
        }
        else if (choice == 3) q2.dequeue();
        else if (choice == 4) q1.display();
        else if (choice == 5) q2.display();
        else if (choice == 6) break;
        else cout << "Invalid choice!\n";
    }
    return 0;
}
