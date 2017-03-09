#pragma once
#include "fileHandler.h"
#include "numberGenerator.h"
#include "numberSort.h"
#include "timer.h"
#include "errorHandler.h"
#include <string>
class menuHandler
{
private:
	int numbers;
	int minimum;
	int maximum;
	std::string name = "";
	numberGenerator *genControler = new numberGenerator;
	numberSort *sortControler = new numberSort;
	timer *timerControler = new timer;
	fileHandler *fileControler = new fileHandler;
	errorHandler *errorMsg = new errorHandler;
public:
	menuHandler();
	~menuHandler();
	void startMenu();
	void schemasMenu();
	void newSchemaMenu();
	void schemaMenuElements();
	void schemaMenuRange();
	void schemaMenuType();
	int checkerInt(int, int);
	void testChoiceMenu();
	void dataSetter(int, int);
	void runTest(int);
	void runAllTests();
	void exportData(double);
};

