#include<iostream>
#include<fstream>
#include<string>
#include"MaxHeap.h"
#include<time.h>
using namespace std;

// Function protototypes

// Read the file and return the number of elements in the file which contains all integers
// Make sure to close the file before return the number of elements in the file
int FindNumberofElements1(const string & fileName);

// Sequnetially read the data in the file and load them one-by-one in arrayPtr
// Make sure to close the file after reading the data
void GetInputfromFile1(int *arrayPtr, const string & fileName);

// Read the file and return the number of elements in the file which contains all words
// Make sure to close the file before return the number of elements in the file
int FindNumberofElements2(const string & fileName);

// Sequnetially read the data in the file
// Convert the data into nonnegative integers using the strategy mentioned in assignment 5
// Load nonnegative integers one-by-one in arrayPtr
// Make sure to close the file after reading the data
void GetInputfromFile2(int *arrayPtr, const string & fileName);

// Perform various sorting algorithms to sort the data in the ascending order
void HeapSort(int *arrayPtr, int size);
void MergeSort(int *arrayPtr, int low, int high);
void QuickSort(int *arrayPtr, int low, int high);

// Other function prototypes go here
void merge(int arr[], int left, int mid, int right);

int main()
{
	clock_t startTime;
	double heap1, heap2, merge1, merge2, quick1, quick2;
	int *A;
	int n; // the number of elements stored in A
	string inputFileName1 = "Assign7Data.txt"; // the name of the input file 

	n = FindNumberofElements1(inputFileName1);
	cout << "the number of data in the input file is " << n << endl;

	// dynamically allocate n spaces in A to hold the n numbers
	// Add your code here ... ... 
	A = new int[n];


	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1);

	// call the heap sort procedure
	startTime = clock();
	HeapSort(A, n);
	heap1 = ((float)(clock()-startTime)) / CLOCKS_PER_SEC;
	cout << "Heap1: " << heap1 << endl;
	system("pause");
	cout << "Heapsorted:" << endl;
	// print the numbers of A out on the screen/console 
	for (int i = 0; i < n; i++)
		cout << A[i] << "  ";

	cout << endl;

	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1);

	// call the merge sort procedure
	startTime = clock();
	MergeSort(A, 0, n - 1);
	merge1 = ((float)(clock() - startTime)) / CLOCKS_PER_SEC;

	cout << "Mergesorted:" << endl;
	// print the numbers of A out on the screen/console 
	for (int i = 0; i < n; i++)
		cout << A[i] << "  ";

	cout << endl;


	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1);

	// call the quick sort procedure
	startTime = clock();
	QuickSort(A, 0, n - 1);
	quick1 = ((float)(clock() - startTime)) / CLOCKS_PER_SEC;

	cout << "Quicksorted:\n";
	// print the numbers of A out on the screen/console 
	for (int i = 0; i < n; i++)
		cout << A[i] << "  ";

	cout << endl;

	delete[] A;
	A = NULL;

	cout << "*******************************************************************************************" << endl;
	cout << "*******************************************************************************************" << endl;


	string inputFileName2 = "dictionary.txt"; // the name of the input file

	n = FindNumberofElements2(inputFileName2);
	cout << "the number of data in the input file is " << n << endl;

	// dynamically allocate n spaces in A to hold the n numbers
	// Add your code here ... ... 
	A = new int[n];

	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2);

	// call the heap sort procedure
	startTime = clock();
	HeapSort(A, n);
	heap2 = ((float)(clock() - startTime)) / CLOCKS_PER_SEC;

	// print the numbers of A out on the screen/console 
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2);

	// call the merge sort procedure
	startTime = clock();
	MergeSort(A, 0, n - 1);
	merge2 = ((float)(clock() - startTime)) / CLOCKS_PER_SEC;

	cout << "Mergsorted:\n";
	// print the numbers of A out on the screen/console 
	for (int i = 0; i < n; i++)
		cout << A[i] << "  ";

	cout << endl;

	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2);

	
	// call the quick sort procedure
	startTime = clock();
	QuickSort(A, 0, n - 1);
	quick2 = ((float)(clock() - startTime)) / CLOCKS_PER_SEC;

	cout << "Quicksorted:\n";
	// print the numbers of A out on the screen/console 
	for (int i = 0; i < n; i++)
		cout << A[i] << "  ";

	cout << endl;

	delete[] A;
	A = NULL;

	cout << "Summary:\n";
	cout << "Heap(data): " << heap1 << " Heap(dict): " << heap2 << endl;
	cout << "Merge(data): " << merge1 << " Merge(dict): " << merge2 << endl;
	cout << "Quick(data): " << quick1 << " Quick(dict): " << quick2 << endl;
	system("pause");

	return 0;
}

// Add your code for each function

// Read the file and return the number of elements in the file containing integers
int FindNumberofElements1(const string & fileName)
{
	int num = -1;
	int tmp;
	fstream fin;
	fin.open(fileName);
	//reads a file that has no newlines. use stream extraction operator.
	while(!fin.eof()) {
		num++;
		fin >> tmp;
	}
	fin.close();
	return num;
}


// Sequnetially read the data in the file and load them one-by-one in arrayPtr
void GetInputfromFile1(int *arrayPtr, const string & fileName)
{
	fstream fin;
	fin.open(fileName);
	for (int i = 0; i < FindNumberofElements1(fileName); i++) {
		fin >> arrayPtr[i];
	}
	fin.close();
}

// Read the file and return the number of elements in the file containing words
int FindNumberofElements2(const string & fileName)
{
	int num = 0;
	string tmp;
	fstream fin;
	fin.open(fileName);
	while (!fin.eof()) {
		num++;
		getline(fin,tmp);
	}
	return num;
}


// Sequnetially read the data in the file, convert them to integers, and load integers one-by-one in arrayPtr
void GetInputfromFile2(int *arrayPtr, const string & fileName)
{
	string tmp;
	int num = 0;
	int index = 0;
	fstream fin;
	fin.open(fileName);
	while (!fin.eof()) {
		fin >> tmp;
		for (int i = 0; i < tmp.length(); i++) {
			num += (int)tmp[i];
		}
		arrayPtr[index] = num;
		num = 0;
		index++;
	}
}

// Perform heap sort and sort the data in ascending order
void HeapSort(int *arrayPtr, int size)
{
	//first, make a heap out of it.
	MaxHeap* myHeap = new MaxHeap(arrayPtr, size);
	//now simply grab every item from heap, placing in array.
	for (int i = size - 1; i > -1; i--) {
		arrayPtr[i] = myHeap->DeleteMax();
	}
}

// Perform merge sort and sort the data in ascending order
void MergeSort(int *arrayPtr, int low, int high)
{
	if (low < high)
	{
		//find midpoint.
		int mid = low + (high - low) / 2;

		//recursively sort each subarray.
		MergeSort(arrayPtr, low, mid);
		MergeSort(arrayPtr, mid + 1, high);
		//then merge them.
		merge(arrayPtr, low, mid, high);
	}
}

void merge(int arr[], int left, int mid, int right)
{
	int* L;
	int* R;
	int i, j, k;
	int sizeL = mid - left + 1;
	int sizeR = right - mid;

	//temporary arrays
	L = new int[sizeL];
	R = new int[sizeR];

	//Copy from original array into subarrays.
	for (i = 0; i < sizeL; i++)
		L[i] = arr[left + i];
	for (j = 0; j < sizeR; j++)
		R[j] = arr[mid + 1 + j];

	//Merge the temp arrays back into arr[l..r], sorting as we go.
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = left; // Initial index of merged subarray
	while (i < sizeL && j < sizeR)//read through each subarray from left to right, comparing each element with the others.
	{
		if (L[i] <= R[j])//if left item is smaller, assign left item to result.
		{
			arr[k] = L[i];
			i++;
		}
		else//otherwise, right is larger, assign right element to results.
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//Copy L's remnants.
	while (i < sizeL)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy R's remnants.
	while (j < sizeR)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// Perform quick sort and sort the data in ascending order
void QuickSort(int *arrayPtr, int low, int high){
	int tmp;
	int i = low;//left iterator
	int j = high;//right iterator
	int test;
	//find midpoint
	int pivot = arrayPtr[low];
	//move everything smaller to the left.
	while (i <= j) {
		while (arrayPtr[i] < pivot) {//find first element on left that is larger than pivot.
			i++;
		}
		while (arrayPtr[j] > pivot) {//find first element on right that is smaller than pivot.
			test = arrayPtr[j];
			j--;
		}
		if (i <= j) {
			tmp = arrayPtr[i];
			arrayPtr[i] = arrayPtr[j];
			arrayPtr[j] = tmp;
			i++;
			j--;
		}
	};

	//run quicksort on each half.
	if (low < j)
		QuickSort(arrayPtr, low, j);
	if (i < high)
		QuickSort(arrayPtr, i, high);
}


// Implementation of other functions