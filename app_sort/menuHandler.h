#pragma once
#include "fileHandler.h"
#include "numberGenerator.h"
#include "numberSort.h"
#include "timer.h"
class menuHandler
{
public:
	menuHandler();
	~menuHandler();
private:
	int numbers;
	int minimum;
	int maximum;
	numberGenerator genControler;
	numberSort sortControler;
	timer timerControler;
	fileHandler fileControler;
protected:
	void startMenu();
	void schemasMenu();
	void newSchemaMenu();
	void schemaMenuElements();
	void schemaMenuRange();
	int checkerInt(int, int);
	void testChoiceMenu();
	void dataSetter();
	void runTest(int);
	void runAllTests();
	void exportData(int, int, double);
};

