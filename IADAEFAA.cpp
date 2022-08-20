#include<iostream>
using namespace std;
class IADEFAA {
public:
	void traverse(int data[], int size) {
		cout << "\nArray Traversal : ";
		for (int i = 0; i < size; i++) {
			cout << data[i]<<" ";
		}
	}
	int* insert(int data[], int *size,int item,int pos) {
		*size += 1;
		cout << "UPDATED ARRAY SIZE : " << *size<< endl;
		for (int i = *size; i >= pos; i--) {				//n-pos
			data[i] = data[i - 1];
		}
		data[pos - 1] =  item;
		cout << "Updated array : \n" << endl;
		for (int i = 0; i < *size; i++) {
			cout << data[i] <<" ";
		}
		return data;
	}
	int* del(int data[], int *size, int item) {
		int temp;
		for (int i = 0; i < *size; i++) {
			if (data[i] == item) {
				temp = data[i+1];
				data[i + 1] = data[i];
				data[i] = temp;
			}
		}
		*size -= 1;
		cout << "UPDATED ARRAY SIZE : " << *size << endl;
		cout << "Updated array : ";
		for (int i = 0; i < *size; i++) {
			cout << data[i] << " ";
		}
		return data;
	}
};
int main() {
	IADEFAA op;
	cout << "Enter the size of an array : ";
	int size, ans = 0;
	int option;
	cin >> size;
	cout << "Enter the array elements : ";
	int* data = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> data[i];
	}
	do {
		cout << "\nArray Operations : "
			"\n1. Traverse an array "
			"\n2. Insert an element "
			"\n3. Delete an element "
			"\nChoose any option from above : ";
		cin >> option;
		switch (option)
		{
		case 1:
			op.traverse(data, size);
			break;
		case 2:
			cout << "Enter the element to be inserted : ";
			int item;
			cin >> item;
			cout << "Enter the position of element to be inserted : ";
			int pos;
			cin >> pos;
			op.insert(data, &size, item, pos);
			break;
		case 3 :
			cout << "Enter the element to be deleted : ";
			cin >> item;
			op.del(data ,&size ,item);
			break;

		default:
			break;
		}

		cout << "\nDo you want to continue ?(1/0) : ";
		cin >> ans;
	} while (ans);

}