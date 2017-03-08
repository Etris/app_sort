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
	void sort();
public:
	//settery
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
	void aShape();
	void vShape();
	void sorted();
	void nearlySorted();
	void reverted();
	//additional fc
	void swap(int*, int*);
	//cons & decons
	numberGenerator();
	~numberGenerator();
};

