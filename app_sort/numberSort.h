#pragma once
class numberSort
{
private:
	int numbers;
	int* arr;
	void swap(int*, int*);
public:
	numberSort();
	~numberSort();
	void resetArray();
	void setNumbers(int);
	int getNumbers();
	void setArray(int[]);
	void insertionSort();
	void selectionSort();
	void shellSort();
	void heapSortMax(int, int);
	void heapSortBuild(int);
	void heapSort();
	void quickSort(int, int);
	void quickSortIter();
	bool checkIfSorted();
};