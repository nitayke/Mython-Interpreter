#include "Void.h"

Void::Void(bool isTemp)
{
	this->_isTemp = isTemp;
}

bool Void::isPrintable() const
{
	return false;
}

std::string Void::toString() const
{
	return "";
}

Void::~Void()
{
}
