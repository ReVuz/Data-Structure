#include<iostream>
using namespace std;
class IADEFAA {
	int size;
	int* data = new int[size];
public:
	IADEFAA() {
		cout << "Enter the size of an array : ";
		cin >> size;
		cout << "Enter the array elements : ";
		for (int i = 0; i < size; i++) {
			cin >> data[i];
		}
	}
	void traverse() {
		cout << "\nTRAVERSING AN ARRAY : \n";
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
	}
	void insert(int item, int pos) {
		size += 1;
		cout << "\nUPDATED ARRAY SIZE : " << size << endl;
		for (int i = size; i >= pos; i--) {				//n-pos
			data[i] = data[i - 1];
		}
		data[pos - 1] = item;
		cout << "\nUPDATED ARRAY : " << endl;
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
	}
	void del(int item) {
		int temp;
		for (int i = 0; i < size; i++) {
			if (data[i] == item) {
				temp = data[i + 1];
				data[i + 1] = data[i];
				data[i] = temp;
			}
		}
		size -= 1;
		cout << "\nUPDATED ARRAY SIZE : " << size << endl;
		cout << "\nUPDATED ARRAY : ";
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
	}
};
int main() {
	IADEFAA op;
	int ans = 0;
	int option;
	do {
		cout << "\nArray Operations : "
			"\n1. Traverse an array "
			"\n2. Insert an element "
			"\n3. Delete an element "
			"\n4. Exit "
			"\nChoose any option from above : ";
		cin >> option;
		switch (option)
		{
		case 1:
			op.traverse();
			break;
		case 2:
			cout << "Enter the element to be inserted : ";
			int item;
			cin >> item;
			cout << "Enter the position of element to be inserted : ";
			int pos;
			cin >> pos;
			op.insert(item, pos);
			break;
		case 3:
			cout << "Enter the element to be deleted : ";
			cin >> item;
			op.del(item);
			break;
		case 4:
			break;
		default:
			break;
		}

		cout << "\nDo you want to continue ?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you!" << endl;

}