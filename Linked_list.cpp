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
//For sorting the linked list using merge sort algorithm
//Funtion to sort the sublists
node* Sorted(node* A, node* B) {
	node* sorted_list = NULL; // to store the sorted list
	if (A == NULL) {
		return B;		//sorted_list = B
	}
	else if (B == NULL) {
		return A;		//sorted_list = A
	}

	if (A->data > B->data) {
		sorted_list = B;
		sorted_list->next = Sorted(A, B->next);
	}
	else {
		sorted_list = A;
		sorted_list->next = Sorted(A->next, B);
	}
	return sorted_list;
}
// Function to split the List to sub lists
//Using floyd's turtoise algorithm
void mergesplit(node* start, node** A, node** B) {
	node* fast;
	node* slow;
	fast = start->next;
	slow = start;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	//After the loop ends, slow will reach position before the mid-point
	*A = start;
	*B = slow->next;
	slow->next = NULL;

}
//Function to split the list and to sort the list using recursion
void MergeSort(node** head) {
	node* start = *head;
	node* A;
	node* B;
	if (start == NULL || start->next == NULL) {
		return;
	}
	//split the list to sub lists
	mergesplit(start,&A,&B);
	//using recusion to sort the sub lists
	MergeSort(&A);
	MergeSort(&B);
	//Storing the sorted list to head pointer
	*head = Sorted(A, B);
}
void display(node *node) {
	cout << "\nList : ";
	while (node != NULL) {
		cout << node->data<<" ";
		node = node->next;
	}
}
int main() {
	node* head = NULL;
	int option, ans = 1;
	do {
		cout << "Linked list operations : \n1. Insert an element to a sorted list \n2. Search for an element "
			"\n3. Delete an Element \n4. Merge two sorted list to a single sorted list\n0. Exit "
			"\nChoose your option : ";
		cin >> option;
		switch (option)
		{
		case 1:
			int value;
			cout << "Enter the value to insert : ";
			cin >> value;
			insert(&head, value);
			MergeSort(&head);
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
		case 4:
			for (int i = 0; i < 2; i++) {
				cout << "Enter number of elementd for sorted list " << i << " : ";
				int num;
				cin >> num;
				cout << "Enter the elements : ";
				for (int j = 0; j < num; j++) {
					cin >> value;
					insert(&head, value);
					MergeSort(&head);
				}
			}
		default:
			break;
		}
		display(head);
		cout << "\nDo you want to continue ?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;
}