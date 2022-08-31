#include <iostream>
using namespace std;
class sort {
public:

	void swap(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void selectionSort(int arr[], int size) {
		for (int step = 0; step < size - 1; step++) {
			int min_idx = step;
			for (int i = step + 1; i < size; i++) {

				// To sort in descending order, change > to < in this line.
				// Select the minimum element in each loop.
				if (arr[i] < arr[min_idx])
					min_idx = i;
			}

			// put min at the correct position
			swap(&arr[min_idx], &arr[step]);
		}
	}
	void bubbleSort(int arr[], int size) {

		// loop to access each array element
		for (int step = 1; step < size; ++step) {

			// loop to compare array elements
			for (int i = 0; i < size - step; ++i) {

				// compare two adjacent elements
				// change > to < to sort in descending order
				if (arr[i] > arr[i + 1]) {

					// swapping elements if elements
					// are not in the intended order
					int temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
		}
	}
	void insertionSort(int arr[], int size) {
		for (int step = 1; step < size; step++) {
			int key = arr[step];
			int j = step - 1;

			// Compare key with each element on the left of it until an element smaller than
			// it is found.
			// For descending order, change key<array[j] to key>array[j].
			while (key < arr[j] && j >= 0) {
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = key;
		}
	}
	void Merge(int* a, int low, int high, int mid)
	{
		// We have low to mid and mid+1 to high already sorted.
		int i, j, k;
		int* temp=new int[high - low + 1];
		i = low;
		k = 0;
		j = mid + 1;

		// Merge the two parts into temp[].
		while (i <= mid && j <= high)
		{
			if (a[i] < a[j])
			{
				temp[k] = a[i];
				k++;
				i++;
			}
			else
			{
				temp[k] = a[j];
				k++;
				j++;
			}
		}

		// Insert all the remaining values from i to mid into temp[].
		while (i <= mid)
		{
			temp[k] = a[i];
			k++;
			i++;
		}

		// Insert all the remaining values from j to high into temp[].
		while (j <= high)
		{
			temp[k] = a[j];
			k++;
			j++;
		}


		// Assign sorted data stored in temp[] to a[].
		for (i = low; i <= high; i++)
		{
			a[i] = temp[i - low];
		}
	}

	// A function to split array into two parts.
	void MergeSort(int* a, int low, int high)
	{
		int mid;
		if (low < high)
		{
			mid = (low + high) / 2;
			// Split the data into two half.
			MergeSort(a, low, mid);
			MergeSort(a, mid + 1, high);

			// Merge them to get sorted output.
			Merge(a, low, high, mid);
		}
	}
	void swap(int arr[],int i,int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	int pivot(int arr[], int start, int end) {
		int p = arr[start];
		int pivotIndex;
		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] <= p) {
				count++;
			}
		}
		pivotIndex = start + count;
		swap(arr, pivotIndex, start);
		//swap(arr,pivotIndex + 1, end);
		int i = start, j = end;

		while (i < pivotIndex && j > pivotIndex) {

			while (arr[i] <= p) {
				i++;
			}

			while (arr[j] > p) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(arr,i++,j--);
			}
		}
		return pivotIndex;
	}
	void QuickSort(int arr[],int start,int end) {
		if (start < end) {
			int pivotElement = pivot(arr, start, end);

			QuickSort(arr, start, pivotElement-1);
			QuickSort(arr, pivotElement + 1,end);
		}
	}

<<<<<<< HEAD
=======



int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
 


>>>>>>> e4181a8951b3f2ef646e6b84599945af3db454f9
	// Function to print an array
	void printArray(int A[], int size)
	{
		for (auto i = 0; i < size; i++)
			cout << A[i] << " ";
	}

};
int main() {
	sort s;
	int num, i, choose;
	int ans = 1;
	do {

		cout << "Enter number of elements : ";
		cin >> num;
		cout << "Enter values of array : ";
		int* arr = new int[num];
		for (i = 0; i < num; i++) {
			cin >> arr[i];
		}

		cout << "\nArray : ";
		s.printArray(arr, num);

		cout << "\nSORTING OPERATIONS \nChoose any option from below "
			"\n1. Selection sort\n2. Bubble Sort\n3. Insertion Sort\n4. Merge Sort \n5. Quick Sort \n0. Exit ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "\nSelection Sort : " << endl;
			s.selectionSort(arr, num);
			cout << "\nSorted Array : ";
			s.printArray(arr, num);
			break;
		case 2:
			cout << "\nBubble Sort : " << endl;
			s.bubbleSort(arr, num);
			cout << "Sorted Array : ";
			s.printArray(arr, num);
			break;
		case 3:
			cout << "\nInsertion Sort : " << endl;
			s.insertionSort(arr, num);
			cout << "\nSorted Array : ";
			s.printArray(arr, num);
			break;
		case 4:
			cout << "\nMerge Sort : " << endl;
			s.MergeSort(arr, 0, num - 1);
			cout << "\nSorted array : ";
			s.printArray(arr, num);
			break;
<<<<<<< HEAD
		case 5 :
			cout << "Quick Sort : " << endl;
			s.QuickSort(arr, 0, num - 1);
			cout << "Sorted Array : ";
			s.printArray(arr, num);
			break;
		case 0:
=======
                case 5 : 
                        cout <<"\nQuick Sort : "<<endl;
                        s.quickSort(arr,0,num-1);
                        cout << "\nSorted array : ";
			s.printArray(arr, num);
			break;


		case 0 :
>>>>>>> e4181a8951b3f2ef646e6b84599945af3db454f9
			cout << "OK" << endl;
			break;
		default:
			break;
		}
		cout << "\nDO YOU WANT TO CONTINUE ?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;

	return 0;
}