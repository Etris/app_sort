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
void numberGenerator::sort()
{

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
	int *copyOfArray = new int[getNumbers()];
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
void numberGenerator::aShape()
{
	this->checkIfArrayIsSet();
	int realNumbers = getNumbers();
	setNumbers(getNumbers() / 2);
	this->genereteNumbers();
	this->sort();
	int *copyOfArray = new int[getNumbers()];
	std::copy(arr, arr + getNumbers(), copyOfArray);
	this->checkIfArrayIsSet();
	setNumbers(realNumbers);
	arr = new int[getNumbers()];
	for (int i = 0; i < getNumbers(); i++) {
		if (i < getNumbers() / 2) {
			arr[i] = copyOfArray[i];
		}
		else {
			arr[i] = copyOfArray[(getNumbers() / 2) - 1 - i];
		}
	}
}
void numberGenerator::vShape() 
{
	this->checkIfArrayIsSet();
	int realNumbers = getNumbers();
	setNumbers(getNumbers() / 2);
	this->genereteNumbers();
	this->sort();
	int *copyOfArray = new int[getNumbers()];
	std::copy(arr, arr + getNumbers(), copyOfArray);
	this->checkIfArrayIsSet();
	setNumbers(realNumbers);
	arr = new int[getNumbers()];
	for (int i = 0; i < getNumbers(); i++) {
		if (i < getNumbers() / 2) {
			arr[i] = copyOfArray[(getNumbers() / 2) - 1 - i];
		}
		else {
			arr[i] = copyOfArray[i];
		}
	}
}

void numberGenerator::sorted()
{
	this->checkIfArrayIsSet();
	this->genereteNumbers();
	this->sort();
}

void numberGenerator::nearlySorted()
{

}

void numberGenerator::reverted()
{
	this->sorted();
	for (int i = 0; i < getNumbers(); i++) {
		swap(&arr[i], &arr[getNumbers() - 1 - i]);
	}
}

void numberGenerator::swap(int * x, int * y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
