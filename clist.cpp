#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
};
node* insert(node* end, int item) {
	node* temp = new node();
	temp->data = item;
	if (end == NULL) {
		end = temp;
		end->next = end;
		return end;
	}
	else {
		temp->next = end->next;
		end->next = temp;
		end = temp;
		return end;
	}
}
node* del(node* end, int item) {
	node* temp = end->next;
	node* temp1 = end->next;
	if (end == NULL) {
		cout << "List is already empty" << endl;
	}
	else if (end->data == item && end->next == NULL) {
		delete end;
		end = NULL;
		return end;
	}
	else if(end->data == item){
		while(end->next!=end){
			end = end->next;
		}
		end->next = temp1->next;
		delete temp;
	}
	else if (end->next->data == item) {
		temp = end->next;
		end->next = temp->next;
		delete temp;
		return end;
	}
	else {
		cout << "No item found" << endl;
	}
	return end;
}
void print(node* end) {
	node* temp;
	if (end == NULL) {
		cout << "List is Empty" << endl;
	}
	//Pointing to first node
	temp = end->next;
	cout << "List : ";
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while (temp != end->next);

}
int main() {
	node* end = NULL;
	int ans = 0;
	do {
		cout << "Enter the element to insert : ";
		int item;
		cin >> item;
		end = insert(end, item);
		print(end);
		cout << "Enter the element to delete : ";
		cin >> item;
		end = del(end, item);
		print(end);
		cout << "\nDo you want to start over?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;
}


