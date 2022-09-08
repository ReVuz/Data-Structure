#include<iostream>
using namespace std;
int n = 10;
class Queue_array {
    int front = 0;
    int rear = 0;
    int arr[10] = { 0 };
public:
    int check() {
        int n = 0;
        if (rear == n) { n = 1; }
        else if (front == rear) { n = 2;}
        return n;  
    }
    void enqueue(int val) {
        rear++;
        arr[rear] = val;
    }

    void dequeue() {
        int val=arr[1];
        for (int i = 0; i < rear; i++) {
                arr[i] = arr[i + 1];  
        }
        rear--;
        cout << "Element deleted : " << val << endl;
    }


    void display() {
        if (front == rear)
        {
            cout << "Queue is empty!!" << endl;

        }
        else
            cout << "Queue : ";
            for (int i = rear; i > front; i--) {
                cout << arr[i] << "  ";
            }
    }
};
int main() {
    Queue_array queue;
    int value, option, ans = 0, num, c = 2;

    do {
        cout << "QUEUE USING ARRAY\t";
        cout << "\n1. Enqueue \n2. Dequeue \n0. Exit" << endl;
        cout << "Enter your choice : ";

        cin >> option;

        switch (option) {
        case 1:
            if (c == 1) {
                cout << "Queue Overflow" << endl;
            }
            else {
                cout << "Enter number of elements of enqueue : ";
                cin >> num;
                cout << "Enter the items : ";
                for (int i = 0; i < num; i++) {
                    cin >> value;
                    queue.enqueue(value);
                }
            }
            break;
        case 2:
            if (c == 2) {
                cout << "Queue Underflow" << endl;
            }
            else {
                cout << "An Element has been Dequeued" << endl;
                queue.dequeue();
            }
            break;
        case 0:
            break;
        default:
            cout << "\nInvalid Option!" << endl;
            break;
        }
        c = queue.check();
        queue.display();
        cout << "\nDo you want to continue?(1/0) : ";
        cin >> ans;
    } while (ans);
    cout << "Thank You" << endl;

    return 0;
}