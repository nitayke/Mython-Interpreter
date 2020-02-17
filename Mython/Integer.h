#ifndef INTEGER_H
#define INTEGER_H
#include "type.h"

class Integer : public Type
{
	int _val;
public:
	Integer(int val, bool isTemp);
	//Integer(const Integer& other);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
	virtual ~Integer();
};

#endif // INTEGER_H