#include "numberGenerator.h"
#include <iostream>
#include <time.h>


numberGenerator::numberGenerator(int numbers, int min, int max)
{
	setNullArray();
	setNumbers(numbers);
	setMinimumValue(min);
	setMaximumValue(max);
	genereteNumbers();
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

}
void numberGenerator::vShape() 
{

}