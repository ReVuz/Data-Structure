#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
};
node* front = NULL;
node* rear = NULL;
void enqueue(int item) {
	node* temp = new node();
	temp->data = item;
	temp->next = NULL;
	if (front == NULL)
	{
		front = temp; rear = temp;
		front->next = NULL;
		rear->next = NULL;
		return;
	}
	else {
		rear->next = temp;
		rear = temp;
		return;
	}
}
void dequeue() {
	if (front != NULL) {
		node* ptr = front;
		front = front->next;
		cout << "\nElement Deleted : " << ptr->data << endl;
		delete ptr;
	}
}
void display() {
	node* temp = front;
	if ((front == NULL) && (rear == NULL)) {
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "Queue : ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main() {
    int value, option, ans = 0, num;

    do {
        cout << "\nQUEUE USING LINKED LIST : ";
        cout << "\n1. Enqueue \n2. Dequeue \n0. Exit" << endl;
        cout << "Enter your choice : ";

        cin >> option;

        switch (option) {
        case 1:
                cout << "Enter number of elements of enqueue : ";
                cin >> num;
                cout << "Enter the items : ";
                for (int i = 0; i < num; i++) {
                    cin >> value;
                    enqueue(value);
                }
            break;
        case 2:
                cout << "\nAn Element has been Dequeued" << endl;
                dequeue();
                break;
        case 0:
            break;
        default:
            cout << "\nInvalid Option!" << endl;
            break;
        }
        display();
        cout << "\nDo you want to continue?(1/0) : ";
        cin >> ans;
    } while (ans);
    cout << "Thank You" << endl;
    return 0;
}