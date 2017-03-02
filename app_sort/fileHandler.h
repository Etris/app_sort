#include <iostream>
#include <string>
#pragma once
class fileHandler
{
public:
	fileHandler();
	~fileHandler();
private:
	std::string fileName;
	std::string data;
	int outputeType;
	int outputeSortType;
protected:
	void setFileName(std::string);
	void setOutputType(int);
	void setOutputSortType(int);
	void setOutputData(std::string);
	std::string getFileName();
	int getOutputType();
	int getOutputSortType();
	void saveDataToFile();
};

