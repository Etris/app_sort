#include "numberSort.h"
#include "numberGenerator.h"
#include <iostream>
#include <algorithm>
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
void numberSort::resetArray() {
	if (arr != NULL) {
		delete[] arr;
	}
	arr = NULL;
}
void numberSort::setNumbers(int value) {
	numbers = value;
}
int numberSort::getNumbers() {
	return numbers;
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
	for (tmp = 1; tmp < getNumbers(); tmp = 3 * tmp + 1) {
		tmp = tmp / 9;
	}
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
void numberSort::heapSortBuild(int)
{
	for (int i = getNumbers() / 2; i>0; i--)
		heapSortMax(getNumbers(), i);
}
void numberSort::heapSort()
{
	int size = getNumbers();
	int temp;
	heapSortBuild(size);
	for (int i = size; i>1; i--)
	{
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
		size--;
		heapSortMax(size, 1);
	}
}
void numberSort::quickSort(int right, int left)
{
	if (right <= left) return;
	int i = left, j = right + 1;
	int pivot = arr[(left + right) / 2];
	while (1) {
		while (pivot > arr[++i]);
		while (pivot < arr[--j]);
		if (i <= j) std::swap(arr[i], arr[j]);
		else break;
	}
	if (j > left) quickSort(left, j);
	if (i < right) quickSort(i, right);
}
void numberSort::quickSortIter()
{
 //
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
