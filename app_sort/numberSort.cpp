#include "numberSort.h"
#include <iostream>
#include <algorithm>
numberSort::numberSort()
{
	setNumbers(0);
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
void numberSort::heapSort()
{
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

}
bool numberSort::checkIfSorted()
{
	return false;
}
void numberSort::selectionSort() {

}
