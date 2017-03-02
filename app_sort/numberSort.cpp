#include "numberSort.h"
#include <iostream>

//public zone:
numberSort::numberSort()
{
}


numberSort::~numberSort()
{

}
//protected zone:
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

}
void numberSort::selectionSort() {

}
