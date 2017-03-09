#include "errorHandler.h"
#include <iostream>

errorHandler::errorHandler()
{
}


errorHandler::~errorHandler()
{
}

void errorHandler::setErrorType(int type)
{
	std::string value;
	switch (type) {
		//wrong data
	case 1:
		value = "ERROR: You enter wrong type of data or wrong number!";
		break;
		//data not set
	case 2:
		value = "ERROR: range or amount of numbers is not setted!";
		break;
		//array error
	case 3:
		value = "ERROR: Array not setted!";
		break;
	}
	this->setErrorText(value);
}

void errorHandler::setErrorText(std::string value)
{
	errorMsg = value;
	this->pushError();
}

void errorHandler::pushError()
{
	this->clearScreen();
	std::cout << errorMsg << std::endl;
}

void errorHandler::clearScreen()
{
}

int errorHandler::forceExit()
{
	return 0;
}