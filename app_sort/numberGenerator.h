#pragma once
class numberGenerator
{
private:
	int numbers;
	int minimumValue;
	int maximumValue;
	int *arr;
	int randNumber();
	void checkIfArrayIsSet();
	void sort(int, int);
	void reSort(int, int);
	int *copyOfArray;
public:
	//settery
	void setCopyArrayNull();
	void setNullArray();
	void setNumbers(int);
	void setMinimumValue(int);
	void setMaximumValue(int);
	//gettery
	int getNumbers();
	int getMinimumValue();
	int getMaximumValue();
	int *getCopyOfArray();
	int *getPrimalArray();
	//main
	void genereteNumbers();
	//specTypes
	void constType();
	void aShape();
	void vShape();
	void sorted();
	void nearlySorted();
	void reverted();
	//additional fc
	void printArr(int);
	void swap(int*, int*);
	//cons & decons
	numberGenerator();
	~numberGenerator();
};

