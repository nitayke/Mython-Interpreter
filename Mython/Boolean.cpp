#include "Boolean.h"

Boolean::Boolean(bool val, bool isTemp)
{
	this->_val = val;
	this->_isTemp = isTemp;
}


bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::toString() const
{
	return this->_val ? "True" : "False";
}

Boolean::~Boolean()
{
}
