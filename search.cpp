#include <iostream>
using namespace std;
class search {
public:
	void linear(int data[], int n, int item) {
		int loc = -1;
		for (int i = 0; i <= n; i++) {
			if (item == data[i]) {
				loc = i;
				cout << "\nThe item " << item << " is in the location : " << loc + 1 << endl;
			}
		}
		if (loc == -1) {
			cout << "\nThere is no item " << item << " found in the list" << endl;
		}
	}
	int binarySearch(int arr[],int low,int high,int item){
	int mid;
	 mid = (low + high)/2;
	    if (item == arr[mid])
		return mid;
	    else if (item > arr[mid]) // x is on the right side
		low = mid + 1;
	    else                       // x is on the left side
		high = mid - 1;
}

	void ternary(int data[], int n, int item) {
		int loc = -1;
		int begin = 0; int end = n;
		while (begin <= end) {
			int mid1 = ((end - begin) / 3) + begin;
			int mid2 = (2 * (end - begin) / 3) + begin;
			if (item == data[mid1]) {
				loc = mid1;
				cout << "\nThe item " << item << " is in the location : " << loc + 1 << endl;

				break;
			}
			else if (item == data[mid2]) {
				loc = mid2;
				cout << "\nThe item " << item << " is in the location : " << loc + 1 << endl;

				break;
			}
			else if (item < data[mid1]) {
				end = mid1 - 1;
			}
			else if (item > data[mid2]) {
				begin = mid2 + 1;
			}
			else {
				begin = mid1 + 1;
				end = mid2 - 1;
			}
		}
		if (loc == -1) {
			cout << "\nThere is no item " << item << " found in the list" << endl;
		}
	}
	int interpolation(int arr[], int n, int x)
	{
		// Find indexes of two corners
		int begin = 0, end = (n - 1);

		// Since array is sorted, an element present
		// in array must be in range defined by corner
		while (begin <= end && x >= arr[begin] && x <= arr[end])
		{
			if (begin == end)
			{
				if (arr[begin] == x) return begin;
				return -1;
			}
			// Probing the position with keeping
			// uniform distribution in mind.
			int pos = begin + (((double)(end - begin) /
				(arr[end] - arr[begin])) * (x - arr[begin]));

			// Condition of target found
			if (arr[pos] == x)
				return pos;

			// If x is larger, x is in upper part
			if (arr[pos] < x)
				begin = pos + 1;

			// If x is smaller, x is in the lower part
			else
				end = pos - 1;
		}
		return -1;
	}

	// Utility function to find minimum of two elements
	int min(int x, int y) { return (x <= y) ? x : y; }

	/* Returns index of x if present, else returns -1 */
	int fibonacci(int arr[], int x, int n)
	{
		/* Initialize fibonacci numbers */
		int fib2 = 0; // (m-2)'th Fibonacci No.
		int fib1 = 1; // (m-1)'th Fibonacci No.
		int fib = fib2 + fib1; // m'th Fibonacci

		/* fib is going to store the smallest Fibonacci
		Number greater than or equal to n */
		while (fib < n) {
			fib2 = fib1;
			fib1 = fib;
			fib = fib2 + fib1;
		}

		// Marks the eliminated range from front
		int offset = -1;

		/* while there are elements to be inspected. Note that
		we compare arr[fib2] with x. When fib becomes 1,
		fib2 becomes 0 */
		while (fib > 1) {
			// Check if fib2 is a valid location
			int i = min(offset + fib2, n - 1);

			/* If x is greater than the value at index fib2,
			cut the subarray array from offset to i */
			if (arr[i] < x) {
				fib = fib1;
				fib1 = fib2;
				fib2 = fib - fib1;
				offset = i;
			}

			/* If x is greater than the value at index fib2,
			cut the subarray after i+1 */
			else if (arr[i] > x) {
				fib = fib2;
				fib1 = fib1 - fib2;
				fib2 = fib - fib1;
			}

			/* element found. return index */
			else
				return i;
		}

		/* comparing the last element with x */
		if (fib1 && arr[offset + 1] == x)
			return offset + 1;

		/*element not found. return -1 */
		return -1;
	}

};
int main()
{
	int n, num, item = 0;
	int ans = 0;
	int result,index, ind;
	search s;
	cout << "How many elements do you want to add : ";
	cin >> n;
	cout << "Enter the elements : ";
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "\nARRAY : ";
	for (int i = 0; i < n; i++) {
		cout<< arr[i];
	}
	do {
		cout << "\nSEARCH OPERATIONS\nCHOOSE FROM THE OPTIONS BELOW " << endl;
		cout << "1. Linear search" << endl;
		cout << "\n2. Binary Search" << endl;
		cout << "\n3. Ternary Search" << endl;
		cout<<"\n4. Interpolation Search" << endl;
		cout << "\n5. Fibonacci Search" << endl;
		cout << "\n0. Exit : ";
		cin >> num;
		if (num != 0) {
			cout << "Enter the item to search : ";
			cin >> item;
		}
		switch (num)
		{
		case 1:
			s.linear(arr, n, item);
			break;
		case 2:
			result = s.binarySearch(arr, 0, n - 1, item);
			(result == -1)
				? cout << "\nThere is no item " << item << " found in the list" << endl
				: cout << "\nThe item " << item << " is in the location : " << result + 1 << endl;
			break;
		case 3:
			s.ternary(arr, n, item);
			break;
		case 4 :
			index = s.interpolation(arr, n, item);
			if (index != -1)
				cout << "\nThe item " << item << " is in the location : " << index + 1<<endl;
			else
				cout << "\nThere is no item " << item << " found in the list" << endl;
			break;
		case 5 :
			ind = s.fibonacci(arr, item, n);
			if (ind >= 0)
				cout << "\nThe item " << item << " is in the location : " << ind + 1<<endl;
			else
				cout << "\nThere is no item " << item << " found in the list" << endl;
			break;
		case 0:
			cout << "OK" << endl;
			break;
		default:
			break;
		}
		cout << "\nDo you want to continue ?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank You!" << endl;
	return 0;
}
