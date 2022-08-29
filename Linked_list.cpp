#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
};
void insert(node** head_ref, int new_data)
{

    node* temp = new node();
    node* temp1 = *head_ref;
    temp->data = new_data;
    temp->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = temp;
        return;
    }
	else {
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
		return;
	}
}
void search(node** head, int item) {
	node* loc = *head;
	int flag = 0,count = 0;
	while (loc != NULL) {
		count++;
		if (loc->data == item) {
			cout << "The item is in the position : " << count << endl;
			flag = 1;
			break;
		}
		loc = loc->next;
	}
	if (flag == 0) {
		cout << "Item not found" << endl;
	}
}
void del(node** head, int item) {
	node* loc = *head;
	node* prev = NULL;
	int flag = 0, count = 0;
	if (loc->data == item) {
		*head = loc->next;
		delete loc;
		flag = 1;
		cout << "Element deleted from list" << endl;
	}
	else {
		while (loc != NULL) {
			count++;
			if (loc->data == item) {
				prev->next = loc->next;
				delete loc;
				flag = 1;
				cout << "Element deleted from list" << endl;
				break;
			}
			prev = loc;
			loc = loc->next;
		}
	}
	if (flag == 0) {
		cout << "Item not found" << endl;
	}
}
void display(node *node) {
	cout << "List : ";
	while (node != NULL) {
		cout << node->data<<" ";
		node = node->next;
	}
}
int main() {
	node* head = NULL;
	int option, ans = 1;
	do {
		cout << "Linked list operations : \n1. Insert an element \n2. Search for an element "
			"\n3. Delete an Element\n0. Exit "
			"\nChoose your option : ";
		cin >> option;
		switch (option)
		{
		case 1:
			int value;
			cout << "Enter the value to insert : ";
			cin >> value;
			insert(&head, value);
			break;
		case 2:
			cout << "Enter the element to search : ";
			int item;
			cin >> item;
			search(&head, item);
			break;
		case 3 :
			cout << "Enter the element to delete : ";
			cin >> item;
			del(&head, item);
		default:
			break;
		}
		display(head);
		cout << "\nDo you want to continue ?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;
}