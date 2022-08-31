#include<iostream>
using namespace std;
class node {
public: 
	int coef;
	int expo;
	node* next;
};
node* insert(node* head_ref, int value, int exp);
void print_array(int arr[], int deg);
void print_list(node* node);
void list_add(node* head1, node* head2) {
	node* ptr1 = head1;
	node* ptr2 = head2;
	node* head3 = NULL;
	while (ptr1 != NULL && ptr2 != NULL) {
		if (ptr1->expo == ptr2->expo) {
			head3 = insert(head3, ptr1->coef + ptr2->coef, ptr1->expo);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if (ptr1->expo > ptr2->expo) {
			head3 = insert(head3, ptr1->coef, ptr1->expo);
			ptr1 = ptr1->next;
		}
		else if (ptr1->expo < ptr2->expo) {
			head3 = insert(head3, ptr2->coef, ptr2->expo);
			ptr2 = ptr2->next;
		}
		
			while (ptr1 != NULL && ptr2 == NULL) {
				head3 = insert(head3, ptr1->coef, ptr1->expo);
				ptr1 = ptr1->next;
			}
			while (ptr1 == NULL && ptr2 != NULL) {
				head3 = insert(head3, ptr2->coef, ptr2->expo);
				ptr2 = ptr2->next;
			}
	}
	cout << "\nSum of the two polynomials  : ";
	print_list(head3);
}
node* insert(node* head_ref, int value,int exp)
{

	node* temp = new node();
	node* temp1 = head_ref;
	temp->coef = value;
	temp->expo = exp;
	temp->next = NULL;
	if (head_ref == NULL)
	{
		head_ref = temp;
	}
	else {
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	return head_ref;
}
//node* create_node(node* head_ref, int value, int exp) {
void array_addn(int arr1[], int arr2[], int deg1, int deg2) {
	int deg3;
	deg3 = deg1 > deg2 ? deg1 : deg2;
	int* sum = new int[deg3];
	for (int i = 0; i < deg3; i++) {
		sum[i] = 0;
	}
	for (int i = 0; i < deg1; i++) {
		sum[i] += arr1[i];
	}
	for (int i = 0; i < deg2; i++) {
		sum[i] += arr2[i];
	}
	cout<<"\n\nSum of the two polynomials : ";
	print_array(sum, deg3);
}
//void list_addn();
void print_array(int arr[],int deg) {
	for (int i = 0; i < deg; i++) {
		if (arr[i] != 0) {
			if (i == deg) {
				cout << arr[i] << "x^" << i+1;
			}
			else if (i == 0) {
				cout << arr[i] << "x";
			}
			else {
				cout << " + " << arr[i] << "x^" << i+1;
			}
		}
	}
}
void print_list(node* node) {
	cout << "\nPolynomial : ";
	while (node != NULL) {
		cout << node->coef << "x^"<<node->expo;
		node = node->next;
		if (node != NULL) {
			cout << " + ";
		}
		else {
			cout << endl;
		}
	}
}
int main() {
	node* head1 = NULL;
	node* head2 = NULL;
	int option, ans = 0;
	do {
		cout << "\nPolynomial addition Using : \n1. Array \n2. Linked List \n0. Exit \nChoose your option : ";
		cin >> option;
		if (option == 1) {
			cout << "Enter the highest degree of the polynomial : ";
			int degree1;
			cin >> degree1;
			int* A = new int[degree1];
			cout << "Enter the coeficients : ";
			for (int i = 0; i < degree1; i++) {
				cin >> A[i];
			}
			cout << "\nFirst polynomial : ";
			print_array(A, degree1);
			cout << "\n\nEnter the highest degree of the second polynomial : ";
			int degree2;
			cin >> degree2;
			int* B = new int[degree2];
			cout << "Enter the coeficients : ";
			for (int i = 0; i < degree2; i++) {
				cin >> B[i];
			}
			cout << "\nSecond polynomial : ";
			print_array(B, degree2);
			array_addn(A, B, degree1, degree2);
		}
		else if (option == 2) {
			cout << "Enter the highest degree of the first polynomial : ";
			int coeff, degree;
			cin >> degree;
			cout << "Enter the coeficients : ";
			for (int i = 1; i <= degree; i++) {
				cin >> coeff;
				head1 = insert(head1, coeff, i);
			}
			print_list(head1);
			cout << "Enter the highest degree of the second polynomial : ";
			cin >> degree;
			cout << "Enter the coeficients : ";
			for (int i = 1; i <= degree; i++) {
				cin >> coeff;
				head2 = insert(head2, coeff, i);
			}
			print_list(head2);
			list_add(head1, head2);
		}
		else
			break;
		cout << "\nDo you want to continue?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;
}