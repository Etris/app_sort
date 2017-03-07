#include "menuHandler.h"
#include <iostream>
using namespace std;

menuHandler::menuHandler()
{
	this->startMenu();
}


menuHandler::~menuHandler()
{

}

void menuHandler::startMenu()
{
	int x;
	cout << "Do you want use one of schema or make new one?\n[1]Schemas\n[2]New schema\n\nUse: ";
	// cin
	switch (x) {
	case 1:
		this->schemasMenu();
		break;
	case 2:
		this->newSchemaMenu();
		break;
	default:
		cout << "Undefinded function. Try again" << endl;
		this->startMenu();
		break;
	}
}

void menuHandler::schemasMenu()
{
	cout << "";
	cout << "choose number of elements:\n[1]10k"
}

void menuHandler::newSchemaMenu()
{
}

int menuHandler::checkerInt(int)
{
	return 0;
}

void menuHandler::testChoiceMenu()
{
}

void menuHandler::dataSetter()
{
}

void menuHandler::runTest(int)
{
}

void menuHandler::runAllTests()
{
}

void menuHandler::exportData(int, int, double)
{
}
