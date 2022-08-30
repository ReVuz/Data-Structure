#include <iostream>
using namespace std;
class sort {
public:

	void swap(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void selectionSort(int array[], int size) {
		for (int step = 0; step < size - 1; step++) {
			int min_idx = step;
			for (int i = step + 1; i < size; i++) {

				// To sort in descending order, change > to < in this line.
				// Select the minimum element in each loop.
				if (array[i] < array[min_idx])
					min_idx = i;
			}

			// put min at the correct position
			swap(&array[min_idx], &array[step]);
		}
	}
	void bubbleSort(int array[], int size) {

		// loop to access each array element
		for (int step = 1; step < size; ++step) {

			// loop to compare array elements
			for (int i = 0; i < size - step; ++i) {

				// compare two adjacent elements
				// change > to < to sort in descending order
				if (array[i] > array[i + 1]) {

					// swapping elements if elements
					// are not in the intended order
					int temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
				}
			}
		}
	}
	void insertionSort(int array[], int size) {
		for (int step = 1; step < size; step++) {
			int key = array[step];
			int j = step - 1;

			// Compare key with each element on the left of it until an element smaller than
			// it is found.
			// For descending order, change key<array[j] to key>array[j].
			while (key < array[j] && j >= 0) {
				array[j + 1] = array[j];
				--j;
			}
			array[j + 1] = key;
		}
	}
	void merge(int array[], int const left, int const mid,
		int const right)
	{
		auto const subArrayOne = mid - left + 1;
		auto const subArrayTwo = right - mid;

		// Create temp arrays
		auto* leftArray = new int[subArrayOne],
			* rightArray = new int[subArrayTwo];

		// Copy data to temp arrays leftArray[] and rightArray[]
		for (auto i = 0; i < subArrayOne; i++)
			leftArray[i] = array[left + i];
		for (auto j = 0; j < subArrayTwo; j++)
			rightArray[j] = array[mid + 1 + j];

		auto indexOfSubArrayOne
			= 0, // Initial index of first sub-array
			indexOfSubArrayTwo
			= 0; // Initial index of second sub-array
		int indexOfMergedArray
			= left; // Initial index of merged array

		// Merge the temp arrays back into array[left..right]
		while (indexOfSubArrayOne < subArrayOne
			&& indexOfSubArrayTwo < subArrayTwo) {
			if (leftArray[indexOfSubArrayOne]
				<= rightArray[indexOfSubArrayTwo]) {
				array[indexOfMergedArray]
					= leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
			}
			else {
				array[indexOfMergedArray]
					= rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
			}
			indexOfMergedArray++;
		}
		// Copy the remaining elements of
		// left[], if there are any
		while (indexOfSubArrayOne < subArrayOne) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
			indexOfMergedArray++;
		}
		// Copy the remaining elements of
		// right[], if there are any
		while (indexOfSubArrayTwo < subArrayTwo) {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
			indexOfMergedArray++;
		}
		delete[] leftArray;
		delete[] rightArray;
	}

	// begin is for left index and end is
	// right index of the sub-array
	// of arr to be sorted */
	void mergeSort(int array[], int const begin, int const end)
	{
		if (begin >= end)
			return; // Returns recursively

		auto mid = begin + (end - begin) / 2;
		mergeSort(array, begin, mid);
		mergeSort(array, mid + 1, end);
		merge(array, begin, mid, end);
	}




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
 


	// Function to print an array
	void printArray(int A[], int size)
	{
		for (auto i = 0; i < size; i++)
			cout << A[i] << " ";
	}

};
int main() {
	sort s;
	int num, i,choose;
	int ans = 1;
	cout << "Enter number of elements : ";
	cin >> num;
	cout << "Enter values of array : ";
	int* arr = new int[num];
	for (i = 0; i < num; i++) {
		cin >> arr[i];
	}

	cout << "\nArray : ";
	s.printArray(arr, num);
	do {
		cout << "\nSORTING OPERATIONS \nChoose any option from below "
			"\n1. Selection sort\n2. Bubble Sort\n3. Insertion Sort\n4. Merge Sort \n5. Quick Sort \n0. Exit ";
		cin >> choose;
		switch (choose)
		{
		case 1 :
			cout << "\nSelection Sort : " << endl;
			s.selectionSort(arr,num);
			cout << "\nSorted Array : ";
			s.printArray(arr, num);
			break;
		case 2:
			cout << "\nBubble Sort : " << endl;
			s.bubbleSort(arr, num);
			cout << "Sorted Array : ";
			s.printArray(arr, num);
			break;
		case 3 :
			cout << "\nInsertion Sort : " << endl;
			s.insertionSort(arr, num);
			cout << "\nSorted Array : ";
			s.printArray(arr, num);
			break;
		case 4 :
			cout << "\nMerge Sort : " << endl;
			s.mergeSort(arr, 0, num - 1);
			cout << "\nSorted array : ";
			s.printArray(arr, num);
			break;
                case 5 : 
                        cout <<"\nQuick Sort : "<<endl;
                        s.quickSort(arr,0,num-1);
                        cout << "\nSorted array : ";
			s.printArray(arr, num);
			break;


		case 0 :
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
