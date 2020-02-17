#ifndef VOID_H
#define VOID_H
#include "type.h"

class Void : public Type
{
public:
	Void(bool isTemp);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
	virtual ~Void();
};

#endif // VOID_H