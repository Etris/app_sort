#include "numberGenerator.h"
#include <iostream>
#include <time.h>


numberGenerator::numberGenerator()
{
	setNullArray();
}

numberGenerator::~numberGenerator()
{
	delete[] arr;
}
/* Private section:: */
int numberGenerator::randNumber() 
{
	return rand() % (getMaximumValue() - getMinimumValue()) + getMinimumValue();
}

void numberGenerator::checkIfArrayIsSet() 
{
	if (arr != NULL) 
	{
		delete[] arr;
		arr = NULL;
	}
}
void numberGenerator::reSort(int left, int right) {
	int i = left;
	int j = right;
	int x = arr[(left + right) / 2];
	do {
		while (arr[i] > x)
			i++;
		while (arr[j] < x)
			j--;
		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left > j) sort(left, j);
	if (right < i) sort(i, right);
}
void numberGenerator::sort(int left, int right)
{
	int i = left;
	int j = right;
	int x = arr[(left + right) / 2];
	do {
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
	if (left < j) sort(left, j);
	if (right > i) sort(i, right);
}
void numberGenerator::setCopyArrayNull()
{
	if (copyOfArray != NULL) {
		delete[] copyOfArray;
	}
}
/* Protection section:: */
void numberGenerator::setNullArray()
{
	arr = NULL;
}
void numberGenerator::setNumbers(int value) 
{
	numbers = value;
}
void numberGenerator::setMinimumValue(int value) 
{	
	minimumValue = value;
}
void numberGenerator::setMaximumValue(int value)
{
	maximumValue = value;
}

int numberGenerator::getNumbers() 
{
	return numbers;
}

int numberGenerator::getMinimumValue()
{
	return minimumValue;
}

int numberGenerator::getMaximumValue()
{
	return maximumValue;
}

int* numberGenerator::getCopyOfArray()
{
	copyOfArray = new int[getNumbers()];
	std::copy(arr, arr + getNumbers(), copyOfArray);
	return copyOfArray;
}

int* numberGenerator::getPrimalArray() 
{
	return arr;
}
void numberGenerator::genereteNumbers()
{
	srand(time(nullptr));
	checkIfArrayIsSet();
	arr = new int[getNumbers()];
	for (int i = 0; i < getNumbers(); i++) 
	{
		arr[i] = randNumber();
	}
}
void numberGenerator::constType()
{
	checkIfArrayIsSet();
	arr = new int[getNumbers()];
	for (int i = 0; i < getNumbers(); i++)
	{
		arr[i] = 7;
	}
}
void numberGenerator::aShape()
{
	this->checkIfArrayIsSet();
	int realNumbers = getNumbers();
	setNumbers(getNumbers() / 2);
	this->genereteNumbers();
	this->sort(0, getNumbers()-1);
	int *stp = new int[getNumbers()];
	std::copy(arr, arr + getNumbers(), stp);
	int *tab = new int[getNumbers()];
	for (int i = 0; i < getNumbers(); i++) {
		tab[i] = stp[getNumbers()-1-i];
	}
	this->checkIfArrayIsSet();
	setNumbers(realNumbers);
	arr = new int[getNumbers()];
	for (int i = 0; i < getNumbers() / 2; i++) {
		arr[i] = stp[i];
	}
	int a = 0;
	for (int i = getNumbers() / 2; i < getNumbers(); i++) {
		arr[i] = tab[a++];
	}
	delete[] tab, stp;
}
void numberGenerator::vShape() 
{
	this->checkIfArrayIsSet();
	int realNumbers = getNumbers();
	setNumbers(getNumbers() / 2);
	this->genereteNumbers();
	this->sort(0, getNumbers() - 1);
	int *stp = new int[getNumbers()];
	std::copy(arr, arr + getNumbers(), stp);
	int *tab = new int[getNumbers()];
	for (int i = 0; i < getNumbers(); i++) {
		tab[i] = stp[getNumbers() - 1 - i];
	}
	this->checkIfArrayIsSet();
	setNumbers(realNumbers);
	arr = new int[getNumbers()];
	for (int i = 0; i < getNumbers() / 2; i++) {
		arr[i] = tab[i];
	}
	int a = 0;
	for (int i = getNumbers() / 2; i < getNumbers(); i++) {
		arr[i] = stp[a++];
	}
	delete[] tab, stp;
}

void numberGenerator::sorted()
{
	this->checkIfArrayIsSet();
	this->genereteNumbers();
	this->sort(0, getNumbers()-1);
}

void numberGenerator::nearlySorted()
{

}

void numberGenerator::reverted()
{
	this->sorted();
	int *tab = new int[getNumbers()];
	for (int i = 0; i < getNumbers(); i++) {
		tab[i] = arr[i];
	}
	for (int i = 0; i < getNumbers(); i++) {
		arr[i] = tab[getNumbers() - 1 - i];
	}
	delete[] tab;
}

void numberGenerator::printArr(int x)
{
	for (int i = 0; i < x; i++) {
		std::cout << arr[i] << ";";
	}
}

void numberGenerator::swap(int * x, int * y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
