#include"MaxHeap.h"
#include<iostream>
#include<math.h>
using namespace std;

MaxHeap::MaxHeap() {// Generate an empty heap with the default array size of 30.
	arraySize = 30;
	H = new int[arraySize];
	heapSize = 0;
};
MaxHeap::MaxHeap(int* A, int size) {// A contains a sequence of elements
	arraySize = size;
	//array size is the max capacity for the new array.
	heapSize = 0;//starts at 0, modified within Insert();
	H = new int[size];
	for (int i = 0; i < size - 1; i++) {
		this->Insert(A[i]);
	}
};
MaxHeap::~MaxHeap() {

};

int MaxHeap::Left(int i) {// return the index of the left child of node i
	return 2 * i;
};

int MaxHeap::Right(int i) {// return the index of the right child of node i
	return 2 * i + 1;
};

int MaxHeap::Parent(int i) {// return the index of the parent of node i
	return i / 2;     // It returns floored value (truncated value)
};

void MaxHeap::PercolateDown(int nodeIndex) { // DownHeap method. It will be called in MaxHeap and DeleteMax
	int leftChildIndex, rightChildIndex, minIndex, tmp;
	leftChildIndex = Left(nodeIndex);
	rightChildIndex = Right(nodeIndex);
	if (rightChildIndex >= heapSize) {
		if (leftChildIndex >= heapSize)
			return;
		else
			minIndex = leftChildIndex;
	}
	else {
		if (H[leftChildIndex] <= H[rightChildIndex])
			minIndex = leftChildIndex;
		else
			minIndex = rightChildIndex;
	}
	if (H[nodeIndex] > H[minIndex]) {
		tmp = H[minIndex];
		H[minIndex] = H[nodeIndex];
		H[nodeIndex] = tmp;
		PercolateDown(minIndex);
	}
};


void MaxHeap::Insert(int x) {// Insert a new element containing word and its weight
	heapSize++;
	H[heapSize] = x; // Find the insertion node, whose index is determined by heap_size 
	int i = heapSize; // UpHeap Operation using Swap Operations 
	while (i > 1 && H[i] > H[Parent(i)]) { // swap H[i] with H[Parent(i)] 
		int temp = H[i];
		H[i] = H[Parent(i)];
		H[Parent(i)] = temp;
		i = Parent(i);
	}
};

int MaxHeap::DeleteMax() {// Find, return, and remove the element with the maximum weight
	int temp = H[1];
	H[1] = H[heapSize];
	H[heapSize] = 0;
	heapSize--;
	PercolateDown(1);  // restore the heap-order property starting from the root 
	return temp;
};

void MaxHeap::PrintHeap() {// Print the heap in tree structure; each node containing word and weight
						   //round two!
	int cellsForHeight = 1;
	for (int i = 1; i < arraySize; i++) {
		cout << "[" << H[i] << "]";
		if (i == cellsForHeight) {
			//end of row.
			cout << endl;
			cellsForHeight = (cellsForHeight * 2) + 1;
		}
	}
	cout << endl;
};

void MaxHeap::Merge(const MaxHeap &secondHeap) {// Merge with another heap to form a larger heap
												//duplicate original.
	int* copy = this->H;
	//extend original heap's size to be the sum of both.
	arraySize = arraySize + secondHeap.arraySize - 1;
	H = new int[arraySize];
	//write all of copy into H.
	for (int i = 1; i < heapSize + 1; i++) {
		H[i] = copy[i];
	}
	//write all of secondHeap into array.
	for (int i = 1; i < secondHeap.heapSize + 1; i++) {
		Insert(secondHeap.H[i]);
	}
};