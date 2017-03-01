#pragma once
class numberSort
{
public:
	numberSort();
	~numberSort();
private:
	int numbers;
	int* arr;
protected:
	void resetArray();
	void setNumbers(int);
	int getNumbers();
	void getArray();
	void insertionSort();
	void selectionSort();
	void shellSort();
	void heapSort();
	void quickSort();
};