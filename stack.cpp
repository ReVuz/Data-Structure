#include <iostream>
using namespace std;


class Stack {
	int top, max;
	int array[10];
public:
	Stack() {
		max = 10;
		top = -1;
	}
	void push(int val);
	int pop();
	void print(int num);
};

void Stack::push(int val) {
	if (top >= max) {
		cout << "Stack Overflow" << endl;
		return;
	}
	top++;
	array[top] = val;
}

int Stack::pop() {
	if (top < 0) {
		cout << "Stack Underflow" << endl;
		return 0;
	}
	int pop = array[top];
	top--;
	cout << "Top element popped" << endl;
	return pop;
}
void Stack::print(int num) {
	for (int i = 0; i < num; i++) {
		cout << array[i] << " ";
	}
}
class Node {
public:
	int data;
	Node* link;
public:
	Node() {
		this->link = NULL;
		this->data = 0;
	}
	Node(int val) {
		this->data = val;
		this->link = NULL;
	}
	int getValue() {
		return data;
	}
	void setValue(int val) {
		this->data = val;
		this->link = NULL;
	}
	friend class Stack;
};

class Linked_Stack {
	Node* top;
public:
	Linked_Stack() {
		top = NULL;
	}
	void push(int val);
	void pop();
	void print();
};

void Linked_Stack::push(int val) {
	Node* newNode = new Node(val);
	if (top == NULL) {
		top = newNode;
		return;
	}
	Node* temp = top;
	top = newNode;
	top->link = temp;

}

void Linked_Stack::pop() {
	if (top == NULL) {
		cout << "Stack Underflow" << endl;
	}
	Node* temp = NULL;
	temp = top;
	top = top->link;
	delete temp;
}

void Linked_Stack::print() {
	Node* temp = top;
	cout << "Stack : " << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->link;
	}
}
int main() {
	Stack S;
	Linked_Stack L;
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
				S.print(num);
			}
			else {
				S.pop();
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
					L.push(item);
				}
				L.print();
			}
			else {
				L.pop();
				L.print();
			}
		}
		cout << "\nDo you want to continue?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;


	return 0;
}