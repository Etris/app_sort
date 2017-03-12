#include "menuHandler.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int menuHandler::brexit()
{
	return 0;
	exit(0);
}

menuHandler::menuHandler()
{
	this->startMenu();
}


menuHandler::~menuHandler()
{
	delete genControler, sortControler, timerControler, fileControler, errorMsg;
}

void menuHandler::startMenu()
{
	int x;
	cout << "Do you want use one of schema or make new one?\n[1]Schemas\n[2]New schema\n\nUse: ";
	// cin
	cin >> x;
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
	schemaMenuElements();
	schemaMenuRange();
	schemaMenuType();
	testChoiceMenu();
}

void menuHandler::newSchemaMenu()
{
	int x, y;
	cout << "enter n:" << endl;
	x = checkerInt(1);
	cout << "enter max range: " << endl;
	y = checkerInt(2);
	dataSetter(1, x);
	dataSetter(2, y);
	schemaMenuType();
	testChoiceMenu();
}

void menuHandler::schemaMenuElements()
{
	// 10k elements, 100k elements, 250k elements, 750k, 500k elements, 1m elements, 2m elements, 5m elements, 10m elements, 20m elements
	cout << "choose number of elements:\n[1]5k\n[2]10k\n[3]15k\n[4]20k\n[5]25k\n[6]40k\n[7]50k\n[8]60k\n[9]75k\n[10]100k\nUse: ";
	int x;
	cin >> x;
	switch (x) {
	case 1:
		dataSetter(1, 5000);
		break;
	case 2:
		dataSetter(1, 10000);
		break;
	case 3:
		dataSetter(1, 15000);
		break;
	case 4:
		dataSetter(1, 20000);
		break;
	case 5:
		dataSetter(1, 25000);
		break;
	case 6:
		dataSetter(1, 40000);
		break;
	case 7:
		dataSetter(1, 50000);
		break;
	case 8:
		dataSetter(1, 60000);
		break;
	case 9:
		dataSetter(1, 75000);
		break;
	case 10:
		dataSetter(1, 100000);
		break;
	default:
		errorMsg->setErrorType(1);
		schemaMenuElements();
	}
}

void menuHandler::schemaMenuRange()
{
	//(0,1k), (0,10k), (0,25k), (0,50k), (0,100k)
	cout << "choose range of elements:\n[1]0-1k\n[2]0-10k\n[3]0-25k\n[4]0-50k\n[5]0-100k\nUse: ";
	int x;
	cin >> x;
	switch (x) {
	case 1:
		dataSetter(2, 1000);
		break;
	case 2:
		dataSetter(2, 10000);
		break;
	case 3:
		dataSetter(2, 25000);
		break;
	case 4:
		dataSetter(2, 50000);
		break;
	case 5:
		dataSetter(2, 100000);
		break;
	default:
		errorMsg->setErrorType(1);
		schemaMenuRange();
		break;
	}
}

void menuHandler::schemaMenuType()
{
	//rand, sorted, reverted, A-Shape, V-Shape
	cout << "choose type of data:\n[1]random\n[2]sorted\n[3]reverted\n[4]A-Shape\n[5]V-Shape\n[6]Const type\nUse: ";
	int x;
	cin >> x;
	switch (x) {
	case 1:
		dataSetter(3, 1);
		break;
	case 2:
		dataSetter(3, 2);
		break;
	case 3:
		dataSetter(3, 3);
		break;
	case 4:
		dataSetter(3, 4);
		break;
	case 5:
		dataSetter(3, 5);
		break;
	case 6:
		dataSetter(3, 6);
		break;
	default:
		errorMsg->setErrorType(1);
		schemaMenuType();
		break;
	}
}

int menuHandler::checkerInt(int set)
{
	int value;
	cin >> value;
	switch (set) {
	//set 1: numbers;
	case 1:
		if (value >= 0 && value <= 99999999999) {
			return value;
		}
		else {
			this->newSchemaMenu();
		}
		break;
	//set 2: range
	case 2:
		if (value >= 0 && value <= 9000000000) {
			return value;
		}
		else {
			this->newSchemaMenu();
		}
		break;
	default:

		break;
	}
}

void menuHandler::testChoiceMenu()
{
	int x;
	cout << "Sort methods:\n[1]Quick\n[2]Shell\n[3]Insertion\n[4]Selection\n[5]Heap\n[6]All methods\n[7]Exit\nUse:";
	cin >> x;
	switch (x) {
	case 1:
		runTest(1);
		break;
	case 2:
		runTest(2);
		break;
	case 3:
		runTest(3);
		break;
	case 4:
		runTest(4);
		break;
	case 5:
		runTest(5);
		break;
	case 6:
		runAllTests();
		break;
	case 7:
		brexit();
		break;
	default:
		errorMsg->setErrorType(1);
		testChoiceMenu();
		break;
	}
	brexit();
}

void menuHandler::dataSetter(int set, int value)
{
	switch (set) {
		//set 1: numbers
	case 1:
		genControler->setNumbers(value);
		sortControler->setNumbers(value);
		name = "-" + std::to_string(value);
		break;
		//set 2: range
	case 2:
		genControler->setMinimumValue(0);
		genControler->setMaximumValue(value);
		name += "-";
		name += std::to_string(value);
		break;
		//set 3:type
	case 3:
		switch (value) {
		case 1:
			name += "-rand";
			genControler->genereteNumbers();
			break;
		case 2:
			name += "-sorted";
			genControler->sorted();
			break;
		case 3:
			name += "-reverse";
			genControler->reverted();
			break;
		case 4:
			name += "-ashape";
			genControler->aShape();
			break;
		case 5:
			name += "-vshape";
			genControler->vShape();
			break;
		case 6:
			name += "const";
			genControler->constType();	
		}
	}
}

void menuHandler::runTest(int testID)
{
	double times = 0;
	std::string nameFinal = "";
	switch(testID) {
	case 1:
		nameFinal = "quick" + name;
		fileControler->setFileName(nameFinal);
		sortControler->setNullArray();
		for (int i = 0; i < 10; i++) {
			//genControler->printArr(5);
			//cout << endl;
			sortControler->resetArray();
			sortControler->setArray(genControler->getCopyOfArray());
			//sortControler->printArr(5);
			genControler->setCopyArrayNull();
			//cout << endl;
			timerControler->start();
			sortControler->quickSort(0, sortControler->getNumbers() - 1);
			//sortControler->quickSortIter(0, sortControler->getNumbers() - 1);
			timerControler->end();
			//sortControler->printArr(5);
			//cout << endl;
			sortControler->checkIfSorted();
			times += timerControler->getLastTime();
			cout << i << ": " << timerControler->getLastTime() << endl;
			fileControler->convertTime(timerControler->getLastTime());
		}
		times /= 10;
		fileControler->convertTime(times);
		fileControler->saveDataToFile();
		cout << "Average time: " << times << endl;
		break;
	case 2:
		nameFinal = "shell" + name;
		fileControler->setFileName(nameFinal);
		sortControler->setNullArray();
		for (int i = 0; i < 10; i++) {
			//genControler->printArr(5);
			//cout << endl;
			sortControler->resetArray();
			sortControler->setArray(genControler->getCopyOfArray());
			//sortControler->printArr(5);
			genControler->setCopyArrayNull();
			//cout << endl;
			timerControler->start();
			sortControler->shellSort();
			timerControler->end();
			//sortControler->printArr(5);
			//cout << endl;
			sortControler->checkIfSorted();
			times += timerControler->getLastTime();
			cout << i << ": " << timerControler->getLastTime() << endl;
			fileControler->convertTime(timerControler->getLastTime());
		}
		times /= 10;
		fileControler->convertTime(times);
		fileControler->saveDataToFile();
		cout << "Average time: " << times << endl;
		break;
	case 3:
		nameFinal = "ins" + name;
		fileControler->setFileName(nameFinal);
		sortControler->setNullArray();
		for (int i = 0; i < 10; i++) {
			//genControler->printArr(5);
			//cout << endl;
			sortControler->resetArray();
			sortControler->setArray(genControler->getCopyOfArray());
			//sortControler->printArr(5);
			genControler->setCopyArrayNull();
			//cout << endl;
			timerControler->start();
			sortControler->insertionSort();
			timerControler->end();
			//sortControler->printArr(5);
			//cout << endl;
			sortControler->checkIfSorted();
			times += timerControler->getLastTime();
			cout << i << ": " << timerControler->getLastTime() << endl;
			fileControler->convertTime(timerControler->getLastTime());
		}
		times /= 10;
		fileControler->convertTime(times);
		fileControler->saveDataToFile();
		cout << "Average time: " << times << endl;
		break;
	case 4:
		nameFinal = "sel" + name;
		fileControler->setFileName(nameFinal);
		sortControler->setNullArray();
		for (int i = 0; i < 10; i++) {
			//genControler->printArr(5);
			//cout << endl;
			sortControler->resetArray();
			sortControler->setArray(genControler->getCopyOfArray());
			//sortControler->printArr(5);
			genControler->setCopyArrayNull();
			//cout << endl;
			timerControler->start();
			sortControler->selectionSort();
			timerControler->end();
			//sortControler->printArr(5);
			//cout << endl;
			sortControler->checkIfSorted();
			times += timerControler->getLastTime();
			cout << i << ": " << timerControler->getLastTime() << endl;
			fileControler->convertTime(timerControler->getLastTime());
		}
		times /= 10;
		fileControler->convertTime(times);
		fileControler->saveDataToFile();
		cout << "Average time: " << times << endl;
		break;
	case 5:
		nameFinal = "heap" + name;
		fileControler->setFileName(nameFinal);
		sortControler->setNullArray();
		for (int i = 0; i < 10; i++) {
			//genControler->printArr(5);
			//cout << endl;
			sortControler->resetArray();
			sortControler->setArray(genControler->getCopyOfArray());
			//sortControler->printArr(5);
			genControler->setCopyArrayNull();
			//cout << endl;
			timerControler->start();
			sortControler->heapSort();
			timerControler->end();
			//sortControler->printArr(5);
			//cout << endl;
			sortControler->checkIfSorted();
			times += timerControler->getLastTime();
			cout << i << ": " << timerControler->getLastTime() << endl;
			fileControler->convertTime(timerControler->getLastTime());
		}
		times /= 10;
		fileControler->convertTime(times);
		fileControler->saveDataToFile();
		cout << "Average time: " << times << endl;
		break;
	default:
		errorMsg->setErrorType(1);
		testChoiceMenu();
		break;
	}
	//system("pause");
	this->brexit();
}

void menuHandler::runAllTests()
{
	cout << "Start test #1: " << endl;
	runTest(1);
	cout << "Start test #2: " << endl;
	runTest(2);
	cout << "Start test #3: " << endl;
	runTest(3);
	cout << "Start test #4: " << endl;
	runTest(4);
	cout << "Start test #5: " << endl;
	runTest(5);
	system("pause");
	this->brexit();
}

void menuHandler::exportData(double)
{

}
