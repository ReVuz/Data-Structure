#include <iostream>
using namespace std;
class arrayy {
public:
	void Traverse(int data[], int lb, int ub) {
		int k;
		k = lb;
		while (k <= ub) {
			cout << data[k]<<endl;
			k = k + 1;
		}
	}
	void insert(int data[], int n, int k, int item) {
		int j = n;
		j = n-1;
		int* arr = new int [n];
		for(int i = 0; i < n;i++){
		    arr[i]=data[i];
		    }
		while (j >= k) {
			arr[j+1] = arr[j];
			j = j - 1;

		}
			arr[k] = item;
			n = n + 1;
			
			data = new int[n+1];
			/* for(int i = 0;i<n+1;i++){
			    data[i]=arr[i];
			    }*/
		cout << "Updated Array : ";
		for (int i = 0; i < n+1; i++) {
			cout << arr[i] << ",";
		}
	}
	void del(int data[], int n, int k, int item) {
		int i,found = 0;
		for (i = 0; i < k; i++)
		{
			if (data[i] == item)
			{
				for (int j = i; j < (k - 1); j++)
					data[j] = data[j + 1];
				k = k - 1;
				found++;
				i--;
			}
		}
		if (found == 0)
			cout << "\nElement doesn't found in the Array!";
		else
			cout << "\nElement Deleted Successfully!";
		cout << endl;
		cout << "\nUpdated Array : ";
		for (int j = 0; j < n; j++) {
			cout << data[j];
		}
	}
};
int main() {
	arrayy obj;
	cout << "How many elements do you want to add : ";
	int n,ans;
	int item,pos;
	cin >> n;
	int* data = new int[n];
	cout << "Enter the elements : ";
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	do
	{
		cout << "\nARRAY OPERATIONS \n1. Insert an element"
			"\n2. Delete an element\n3. Traverse array\n0. Exit : ";
		int num;
		cin >> num;
		switch (num)
		{
		case 1 :
			cout << "Enter the element to insert : ";
			cin >> item;
			cout<<"Enter position of element to be inserted : ";
			cin>>pos; 
			obj.insert(data, n, pos, item);
			break;
		case 2 :
			cout << "Enter the element to delete : ";
			cin >> item;
					obj.del(data, n, n, item);
			break;
		case 3:
			cout << "Enter the lower and upper bound : ";
			int lb, ub;
			cin >> lb >> ub;
			obj.Traverse(data, lb, ub);
			break;
		case 0 :
			cout << "OK" << endl;
			break;

		default:
			break;
		}
		cout << "\nDo you want to continue ?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you " << endl;
}
