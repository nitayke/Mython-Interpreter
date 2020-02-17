#include "String.h"

String::String(std::string val, bool isTemp)
{
	this->_val = val;
	this->_isTemp = isTemp;
}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	for (char i : this->_val)
	{
		if (i == '\'')
		{
			return '\"' + this->_val + '\"';
		}
	}
	return "\'" + this->_val + "\'";
}

String::~String()
{
}
