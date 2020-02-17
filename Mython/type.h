#ifndef TYPE_H
#define TYPE_H
#include <string>

class Type
{
protected:
	bool _isTemp = false;
public:
	virtual bool getIsTemp() const;
	virtual void setIsTemp(bool isTemp);
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
	virtual ~Type();
};

#endif //TYPE_H
