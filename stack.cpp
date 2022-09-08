#include <iostream>
using namespace std;
int n = 20;
class Stack {
	int arr[20] = {0};
	int top = 0;
public:
	void push(int val) {
		if (top > n) {
			cout << "Stack Overflow" << endl;
		}
		else {
			top++;
			arr[top] = val;
		}
	}
	void pop() {
		if (top == 0) {
			cout << "Stack Underflow" << endl;
		}
		else {
			cout << "Element popped : " << arr[top] << endl;
			top--;
		}
	}
	void print() {
		if (top == 0) {
			cout << "Stack is Empty" << endl;
		}
		else {
			cout << "Stack : ";
			for (int i = top; i > 0; i--) {
				cout << arr[i] << " ";
			}
		}
	}
};
class node {
public:
	int data;
	node* next;
};
node* top = NULL;
void push(int val) {
	node* ptr = new node();
	ptr->data = val;
	ptr->next = top;
	top = ptr;
}
void pop() {
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
	}
	else {
		cout << "Element popped : " << top->data << endl;
		node* ptr = top;
		top = top->next;
		delete ptr;
	}
}
void print() {
	if (top == NULL) {
		cout << "Stack is Empty" << endl;
	}
	else {
		node* ptr = top;
		cout << "Stack : ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
}
int main() {
	Stack S;
	int ans = 0;
	do {
		cout << "Stack Operations Using : \n1. Array \n2. Linked List \nChoose your option : ";
		int option;
		cin >> option;
		cout << "\n1. Push \n2. Pop : ";
		int z;
		int num;
		cin >> z;
		if (option == 1) {
			if (z == 1) {
				cout << "Enter number of elements to push : ";
				int item;
				cin >> num;
				cout << "Enter the element to push : ";
				for (int i = 0; i < num; i++) {
					cin >> item;
					S.push(item);
				}
				S.print();
			}
			else {
				S.pop();
				S.print();
			}
		}
		else if (option == 2) {
			if (z == 1) {
				cout << "Enter number of elements to push : ";
				int item;
				cin >> num;
				cout << "Enter the element to push : ";
				for (int i = 0; i < num; i++) {
					cin >> item;
					push(item);
				}
				print();
			}
			else {
				pop();
				print();
			}
		}
		cout << "\nDo you want to continue?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;


	return 0;
}