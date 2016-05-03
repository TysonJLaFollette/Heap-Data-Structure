#pragma once

class MaxHeap {
private:
	int arraySize; // the size of the array, index from 0 to array_size-1
	int heapSize; // number of elements in the heap; heapSize is smaller than arraySize
	int* H; // elements of heap are in H[1]…H[heapSize], cell at index 0 is not used
	int Left(int i); // return the index of the left child of node i
	int Right(int i); // return the index of the right child of node i
	int Parent(int i); // return the index of the parent of node i
	void PercolateDown(int); // DownHeap method. It will be called in MaxHeap and DeleteMax
public:
	MaxHeap(); // Generate an empty heap with the default array size of 30.
	MaxHeap(int* A, int arraySize); // A contains a sequence of elements
	~MaxHeap();
	void Insert(int x); // Insert a new element containing word and its weight
	int DeleteMax(); // Find, return, and remove the element with the maximum weight
	void PrintHeap(); // Print the heap in tree structure; each node containing word and weight
	void Merge(const MaxHeap &newHeap); // Merge with another heap to form a larger heap
};