#include "Integer.h"

Integer::Integer(int val, bool isTemp)
{
	this->_val = val;
	this->_isTemp = isTemp;
}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::toString() const
{
	return std::to_string(this->_val);
}

Integer::~Integer()
{
}
