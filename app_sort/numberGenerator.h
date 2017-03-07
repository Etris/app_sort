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
	//
	void genereteNumbers();
	//specTypes
	void aShape();
	void vShape();
	void sorted();
	void nearlySorted();
	void reverted();
	numberGenerator();
	~numberGenerator();
};

