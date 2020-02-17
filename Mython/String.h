#ifndef STRING_H
#define STRING_H
#include "Sequence.h"

class String : public Sequence
{
	std::string _val;
public:
	String(std::string val, bool isTemp);
	//String(const String& other);
	virtual bool isPrintable() const;
	virtual std::string toString() const;
	virtual ~String();
};

#endif // STRING_H