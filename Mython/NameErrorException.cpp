#include "NameErrorException.h"

NameErrorException::NameErrorException(std::string name)
{
	this->_name = name;
}

const char* NameErrorException::what() const throw()
{
	std::string error = "NameError : name '" + this->_name + "' is not defined";
	char* n = new char[error.length() - 4];
	for (size_t i = 0; i < error.length(); i++)
	{
		n[i] = error[i];
	}
	return n;
}
