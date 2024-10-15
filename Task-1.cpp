#include <iostream>
using namespace std;

class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    void input() {
        cout << "Enter ID: "; cin >> per_id;
        cout << "Enter Name: "; cin.ignore(); getline(cin, per_name);
        cout << "Enter Age: "; cin >> per_age;
    }

    void output() const {
        cout << "\nID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << "\n";
    }
};

class Node {
public:
    Person data;
    Node* next;
    Node(Person p) : data(p), next(nullptr) {}
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() { return front == nullptr; }

    void addQueue(Person p) {
        Node* newNode = new Node(p);
        if (isEmpty()) front = rear = newNode;
        else rear->next = newNode, rear = newNode;
        cout << "Person added to the queue.\n";
    }

    void removeQueue() {
        if (isEmpty()) cout << "Queue is empty.\n";
        else {
            Node* temp = front;
            front = front->next;
            if (!front) rear = nullptr;
            cout << "Removing: "; temp->data.output();
            delete temp;
        }
    }

    void displayQueue() {
        if (isEmpty()) cout << "Queue is empty.\n";
        else for (Node* temp = front; temp; temp = temp->next) temp->data.output();
    }
};

int main() {
    Queue q;
    int choice;
    do {
        cout << "\n1. Add Person\n2. Remove Person\n3. Display Queue\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) { 
            Person p; p.input(); 
            q.addQueue(p);
        }
        else if (choice == 2) q.removeQueue();
        else if (choice == 3) q.displayQueue();
        else if (choice != 4) cout << "Invalid choice!\n";
    } while (choice != 4);

    return 0;
}
