#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* prev;
	node* next;
};
void insert(node**head,int item) {
	node* temp = new node();
	temp->data = item;
	temp->next = NULL;
	if (*head == NULL) {
		temp->prev = NULL;
		*head = temp;
	}
	else {
		node* ptr = *head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->prev = ptr;
	}
}
node* del(node* head, int pos) {		//directly delete element from given position
	node* temp = head;
	if (pos == 1) {
		if (head->next == NULL) {
			head = NULL;
		}
		else {
			head = head->next;
		}
		delete temp;
		return head;
	}
	else {
		for (int i = 1; i < pos && head != NULL; i++)
		{
			temp = temp->next;
		}
		if (temp->next != NULL)
		{
			temp->prev->next = temp->next;   // Assign the next pointer of node to be deleted to its previous node's prev pointer
			temp->next->prev = temp->prev;   // Assign the prev pointer of the node to be deleted to its next node's next pointer
			delete temp;
			return head;
		}
		else
		{
			temp->prev->next = NULL;
			delete temp;
			return head;
		}
	}
}
bool search(node*head,int* item) {		//if element found is true delete the element
	int count = 1, flag = 0;
	node* temp = head;
	//case 1 : head is the item
	if (head->data == *item) {
		*item = count;
		return true;
		flag = 1;
	}
	else {
		while (temp != NULL) {
			if (temp->data == *item) {
				*item = count;
				return true;
				flag = 1;
			}
			else {
				temp = temp->next;
				count++;
			}
		}
	}
	if (flag == 0) {
		return false;
	}
}
void display(node*head) {
	node* temp=head;
	cout << "List : ";
	if (head == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}
int main() {
	node* head = NULL;
	int ans = 0, item;
	bool check = false;
	do {
		cout << "\nDoubly Linked List Operations : "
			"\n1. Insert Node \n2. Delete Node \n3. Search Node \n0. Exit"
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
			check = search(head,&item);
			if (check == true) {
				head = del(head,item);
			}
			else {
				cout << "Element not found" << endl;
			}
			break;
		case 3:
			cout << "Enter the element to search : ";
			cin >> item;
			check = search(head, &item);
			if (check == true) {
				cout << "Element found at position : " << item << endl;
			}
			else {
				cout << "Element not found" << endl;
			}
			break;
		default:
			break;
		}
		display(head);
		cout << "\nDo you want to continue ? (1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank You" << endl;
}