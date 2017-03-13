#include "numberSort.h"
#include "numberGenerator.h"
#include <iostream>
#include <algorithm>
#include <time.h>
numberSort::numberSort()
{
	setNumbers(0);
}
void numberSort::swap(int * x, int * y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

numberSort::~numberSort()
{
	resetArray();
}
void numberSort::setNullArray()
{
	arr = NULL;
}
void numberSort::resetArray() {
	if (arr != NULL)
	{
		for (int i = 0; i < getNumbers() - 1; i++) {
			arr[i] = NULL;
		}
		delete[] arr;
		arr = NULL;
	}
}
void numberSort::setNumbers(int value) {
	numbers = value;
}
int numberSort::getNumbers() {
	return numbers;
}
void numberSort::printArr(int x)
{
	for (int i = 0; i < x; i++) {
		std::cout << arr[i] << ";";
	}
}
void numberSort::setArray(int tab[]) {
	arr = new int[getNumbers()];
	std::copy(tab, tab + getNumbers(), arr);
}
void numberSort::insertionSort() {
	int x, j;
	for (int i = getNumbers() - 2; i >= 0; i--) {
		x = arr[i];
		j = i + 1;
		while ((j < getNumbers()) && (x > arr[j])) {
			arr[j - 1] = arr[j];
			j++;
		}
		arr[j - 1] = x;
	}
}
void numberSort::shellSort() {
	int tmp, i, j, x;
	for (tmp = 1; tmp <= getNumbers() / 3; tmp = 3 * tmp + 1){}
	while (tmp > 0) {
		for (int i = getNumbers() - tmp - 1; i >= 0; i--) {
			x = arr[i];
			j = i + tmp;
			while ((j < getNumbers()) && (x > arr[j])) {
				arr[j - tmp] = arr[j];
				j = j + tmp;
			}
			arr[j - tmp] = x;
		}
	tmp /= 3;
	}
}
void numberSort::heapSortMax(int n, int i)
{

	int largest, temp;
	int l = 2 * i, r = (2 * i) + 1;
	if (l <= n && arr[l]>arr[i])
		largest = l;
	else largest = i;
	if (r <= n && arr[r]>arr[largest])
		largest = r;
	if (largest != i)
	{
		temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		heapSortMax(n, largest);
	}
}
void numberSort::heapSortBuild(int size)
{
	for (int i = size / 2; i>0; i--) heapSortMax(size, i);
}
void numberSort::heapSort()
{
	int size = getNumbers();
	heapSortBuild(size);
	for (int i = size - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapSortMax(i, 0);
	}
}
void numberSort::quickSort(int left, int right)
{
	int i = left;
	int j = right;
	int x = arr[(left+right)/2];
	do{
		while (arr[i] < x)
			i++;
		while (arr[j] > x)
			j--;
		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quickSort(left, j);
	if (right > i) quickSort(i, right);
}
int numberSort::part(int left, int right)
{
	int piv = rand() % (getNumbers() - 1) + 0;
	int pivot = arr[piv];
	int pIndex = left;
	for (int i = left; i < right - 1; i++) 
	{
		if (arr[i] <= pivot) 
		{
			swap(&arr[i], &arr[pIndex]);
			pIndex++;
		}
	}
	swap(&arr[pIndex], &arr[right]);
	return pIndex;
}
void numberSort::quickSortIter(int left, int right)
{
		if (left < right) {
			srand(time(nullptr));
			int index = part(left, right);
			quickSortIter(left, index - 1);
			quickSortIter(index + 1, right);
	}
}
bool numberSort::checkIfSorted()
{
	bool status = true;
	for (int i = 0; i < 100; i++) {
		if (arr[i] <= arr[i + 1]) status = true;
		else {
			status = false;
			break;
		}
	}
	return status;
}
void numberSort::selectionSort() {
	int k;
	for (int i = 0; i < getNumbers(); i++)
	{
		k = i;
		for (int j = i + 1; j < getNumbers(); j++)
			if (arr[j] < arr[k]) 
			{
				k = j;
			}
		swap(&arr[k], &arr[i]);
	}
}
