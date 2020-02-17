#ifndef BOOLEAN_H
#define BOOLEAN_H
#include "type.h"

class Boolean : public Type
{
	bool _val;
public:
	Boolean(bool val, bool isTemp);
	//Boolean(const Boolean& other);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
	virtual ~Boolean();
};

#endif // BOOLEAN_H