#include<iostream>
using namespace std;
class node {
	int data;
	node* next;
};
int* array_addn(int a[], int an, int bn, int b[]) {
	int c = an ? an >= bn : bn;
	int* sum = new int[c];
	for (int i = 0; i < an; i++) {
		sum[i] = a[i];
	}
	for (int i = 0; i < bn; i++) {
		sum[i] += b[i];
	}
	return sum;
}
void print_array(int arr[], int length) {
	for (int i = length - 1; i >= 0; i--) {
		cout << arr[length - i - 1] << "x^" << i;
		if (i != 0) {
			cout << " + ";
		}
	}
}
int main() {
	cout << "Enter the highest degree of the polynomial : ";
	int degree1;
	cin >> degree1;
	int* A = new int[degree1];
	cout << "Enter the coeficients : ";
	for (int i = 0; i < degree1; i++) {
		cin >> A[i];
	}
	cout << "Enter the highest degree of the second polynomial : ";
	int degree2;
	cin >> degree2;
	int* B = new int[degree2];
	cout << "Enter the coeficients : ";
	for (int i = 0; i < degree2; i++) {
		cin >> B[i];
	}
	int c = max(degree1, degree2);
	cout << "\nFirst polynomial is \n";
	print_array(A, degree1);
	cout << "\nSecond polynomial is \n";
	print_array(B, degree2);

	int* sum = array_addn(A, degree1, degree2, B);
	cout << "\nSum of the two polynomials : \n";
	print_array(sum, c);
}