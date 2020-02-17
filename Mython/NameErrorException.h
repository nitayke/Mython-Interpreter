#ifndef NAME_ERROR_EXCEPTION_H
#define NAME_ERROR_EXCEPTION_H
#include "InterperterException.h"
#include <string>
#include <iostream>

class NameErrorException : public InterperterException
{
	std::string _name;
public:
	NameErrorException(std::string name);
	virtual const char* what() const throw();
};

#endif // NAME_ERROR_EXCEPTION_H