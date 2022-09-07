#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
};
void insert(node** head, int item) {
	node* temp = new node();
	temp->data = item;
	temp->next = *head;
	if (*head != NULL) {
		node* temp1 = *head;
		while (temp1->next != *head) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	else {
		temp->next = temp;
		*head = temp;
	}
}
node* del(node* head, int item) {
	int flag = 0;
	//case 1 : no node
	if (head == NULL) {
		cout << "List is Empty" << endl;
		return head;
		flag = 1;
	}
	//case 2 : only one node
	else if (head->next == head) {
		if (head->data == item) {
			head = NULL;
			delete head;
			cout << "Element deleted" << endl;
			flag = 1;
		}return head;
	}
	//case 3 : more than one node
	else {
		node* temp = head;
		node* ptr;
		//case  3.1 : head has to be deleted
		if(head->data == item){
			while (temp->next != head) {
				temp = temp->next;
			}
			temp->next = head->next;
			delete head;
			head = temp->next;
			return head;
		}
		else {
			while (temp->next != head && temp->next->data != item) {
				temp = temp->next;
			}
			//case 4 : if element is found somewhere
			//from the list other than head
			if (temp->next->data == item) {
				ptr = temp->next;
				temp->next = ptr->next;
				delete ptr;
				return head;
			}
		}flag = 1;


	}
	if (flag == 0) {
		cout << "Element not found" << endl;
	}return head;
}
void print(node* head){
	cout << "List : ";
	if (head == NULL) {
		cout << "List is Empty" << endl;
	}
	else {
		node* temp = head;
		/*while (temp->next != head) {	
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << " ";*/
		do {
			cout << temp->data <<" ";
			temp = temp->next;
		} while (temp != head);
	}
}
int main() {
	node* head = NULL;
	int ans = 0, item;
	do {
		cout << "\nCircular Header List Operations : "
			"\n1. Insert Node \n2. Delete Node \n0. Exit"
			"\nChoose Your Option : ";
		int option;
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter number of elements to insert : ";
			int num;
			cin >> num;
			cout << "Enter the elements : ";
			for (int i = 0; i < num; i++) {
				cin >> item;
				insert(&head, item);
				//cout << "Element added" << endl;
			}
			break;
		case 2:
			cout << "Enter the element to delete : ";
			cin >> item;
			head = del(head, item);
			break;
		default:
			break;
		}
		print(head);
		cout << "\nDo you want to continue ? (1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank You" << endl;
}