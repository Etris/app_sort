#include "fileHandler.h"
#include <iostream>
#include <string>

fileHandler::fileHandler()
{
}


fileHandler::~fileHandler()
{
}

void fileHandler::convertTime(double var)
{
	buildOutputData(std::to_string(var));
}

void fileHandler::setFileName(std::string name)
{
	fileName = name;
}

void fileHandler::buildOutputData(std::string text)
{
	data += ";";
	data += text;
}

std::string fileHandler::getFileName()
{
	return fileName;
}

void fileHandler::saveDataToFile()
{

}

