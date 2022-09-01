#include<iostream>
using namespace std;
int n = 10;
class Queue {
private:
    int front;
    int rear;
    int arr[20];

public:
    Queue() {
        front = -1;
        rear = -1;
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }
    void enqueue(int val) {
        if (rear == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else if (front == -1 && rear == -1) {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else {
            rear++;
            arr[rear] = val;
        }

    }

    void dequeue() {
        int val;
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow" << endl;

        }
        else if (rear == front) {
            val = arr[rear];
            rear = -1;
            front = -1;
            cout << "Element deleted : " << val << endl;
            front++;
        }
        else {
            cout << "front value: " << front << endl;
            val = arr[front];
            arr[front] = 0;
            cout << "Element deleted : " << val << endl;

            front++;
        }
    }


    void display() {
        if (front == -1)
        {
            cout << "Queue is empty!!" << endl;

        }
        else
            for (int i = 0; i < n; i++) {
                cout << arr[i] << "  ";
            }
        cout << "\nFront:" << front << endl;
        cout << "Rear:" << rear << endl;
        cout << endl;
    }

};

int main() {
    Queue q1;
    int value, option, ans;

    do {
        cout << "\tQUEUE USING ARRAY\t";
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "Enter your choice : ";

        cin >> option;
        switch (option) {
        case 1:
            cout << "Enter an item to add in the Queue : " << endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            q1.dequeue();
            cout << "An Element has been Dequeued" << endl;
            break;
        case 3:
            cout << "Queue : " << endl;
            q1.display();
            break;
        default:
            cout << "Invalid option!!\n Try again " << endl;
        }
        cout << "Do you want to continue?(1/0) : ";
        cin >> ans;
    } while (ans);

    return 0;
}