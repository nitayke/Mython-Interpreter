#include "type.h"

bool Type::getIsTemp() const
{
	return this->_isTemp;
}

void Type::setIsTemp(bool isTemp)
{
	this->_isTemp = isTemp;
}

Type::~Type()
{
}
