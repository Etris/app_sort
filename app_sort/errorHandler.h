#pragma once
#include <string>
class errorHandler
{
public:
	errorHandler();
	~errorHandler();
	void setErrorType(int);
private:
	std::string errorMsg;
	void setErrorText(std::string);
	void pushError();
	void clearScreen();
	int forceExit();
};

