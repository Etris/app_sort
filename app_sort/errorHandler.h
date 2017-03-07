#pragma once
#include <string>
class errorHandler
{
public:
	errorHandler();
	~errorHandler();
private:
	std::string errorMsg;
	void setErrorType(int);
	void setErrorText(std::string);
	void pushError();
	void clearScreen();
	int forceExit();
};

