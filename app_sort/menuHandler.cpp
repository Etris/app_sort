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
}

void menuHandler::newSchemaMenu()
{

}

void menuHandler::schemaMenuElements()
{
	// 10k elements, 100k elements, 250k elements, 750k, 500k elements, 1m elements, 2m elements, 5m elements, 10m elements, 20m elements
	cout << "choose number of elements:\n[1]10k\[2]100k elements\n[3]250k elements\n[4]500k elements\n[5]750k\n[6]1m\n[7]2m\n[8]5m\n[9]10m\n[10]20m\nUse: ";
	//cin
}

void menuHandler::schemaMenuRange()
{
	//(0,1k), (0,10k), (0,25k), (0,50k), (0,100k)
	cout << "choose range of elements:\n[1]0-1k\n[2]0-10k\n[3]0-25k\n[4]0-50k\n[5]0-100k\nUse: ";
	//cin;
}

void menuHandler::schemaMenuType()
{
	//rand, nearly sorted, sorted, reverted, A-Shape, V-Shape
}

int menuHandler::checkerInt(int set, int value)
{
	switch (set) {
	//set 1: numbers;
	case 1:
		if (value >= 0 && value <= 99999999999) {
			return value;
		}
		else {
			this->schemaMenuElements();
		}
		break;
	//set 2: range
	case 2:
		if (value >= 0 && value <= 9000000000) {
			return value;
		}
		else {
			this->schemaMenuRange();
		}
		break;
	default:

		break;
	}
}

void menuHandler::testChoiceMenu()
{
}

void menuHandler::dataSetter(int set, int value)
{
	switch (set) {
		//set 1: numbers
			
		//set 2: range
	}
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
