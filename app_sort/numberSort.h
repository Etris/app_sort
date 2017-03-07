#pragma once
class numberSort
{
private:
	int numbers;
	int* arr;
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
	void heapSort();
	void quickSort(int, int);
	void quickSortIter();
	bool checkIfSorted();
};