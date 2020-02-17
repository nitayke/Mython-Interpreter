#include "parser.h"
#include <iostream>

std::unordered_map<string, Type*> Parser::_variables;

Type* Parser::parseString(std::string str) throw()
{
	Type* type;
	if (str[0] == ' ' || str[0] == '\t')
	{
		throw IndentationException();
	}
	Helper::trim(str);
	type = getVariableValue(str); // ex: m
	if (type != nullptr)
	{
		return type;
	}

	type = getType(str, true); // ex: 'm'
	if (type != nullptr)
	{
		return type;
	}
	if (makeAssignment(str)) // ex: m = 2
		return new Void(true);
	throw SyntaxException();
}

Type* Parser::getType(std::string& str, bool isTemp)
{
	Helper::removeLeadingZeros(str);
	if (Helper::isInteger(str))
	{
		return new Integer(atoi(str.c_str()), isTemp);
	}
	if (Helper::isBoolean(str))
	{
		return new Boolean(str == "True", isTemp);
	}
	if (Helper::isString(str))
	{
		return new String(str.substr(1, str.length() - 2), isTemp);
	}
	try
	{
		std::list<Type*> typeList = list(str);
		return new List(typeList);
	}
	catch (const std::exception&)
	{}
	return nullptr;
}

void Parser::clearVariables()
{
	_variables.clear();
}

bool Parser::isLegalVarName(const std::string& str)
{
	if (Helper::isDigit(str[0]))
	{
		return false;
	}
	for (char i : str)
	{
		if (!Helper::isUnderscore(i) && !Helper::isDigit(i) && !Helper::isLetter(i))
		{
			return false;
		}
	}
	return true;
}

bool Parser::makeAssignment(const std::string& str)
{
	string varName, varValue;
	bool found = false;
	unsigned int count = 0;
	for (char i : str)
	{
		if (i == '=')
		{
			count++;
		}
	}
	if (count != 1)
	{
		return false;
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '=')
		{
			found = true;
			continue;
		}
		if (!found)
		{
			varName += str[i];
		}
		else
		{
			varValue += str[i];
		}
	}
	Helper::trim(varName);
	Helper::trim(varValue);
	if (!isLegalVarName(varName))
	{
		throw SyntaxException();
	}
	Type* type = getType(varValue, false);
	if (type == nullptr)
	{
		if (isLegalVarName(varValue))
		{
			type = getVariableValue(varValue);
			if (type == nullptr)
			{
				throw NameErrorException(varValue);
			}
			string value = type->toString();
			_variables[varName] = getType(value, false);
			return true;
		}
		throw SyntaxException();
	}
	_variables[varName] = type;
	return true;
}

Type* Parser::getVariableValue(const std::string& str)
{
	if (_variables.find(str) == _variables.end())
	{
		return nullptr;
	}
	return _variables[str];
}

std::list<Type*> Parser::list(std::string& s)
{
	std::list<Type*> typeList;
	Helper::trim(s);
	if (s[0] != '[' || s[s.size() - 1] != ']')
	{
		throw SyntaxException();
	}
	std::string delimiter = ",";
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(1, pos - 1);
		try
		{
			typeList.push_back(Parser::getType(token, true));
		}
		catch (const std::exception& e)
		{
			throw SyntaxException();
		}
		s.erase(0, pos + delimiter.length());
	}
	token = s.substr(1, s.size() - 2);
	try
	{
		typeList.push_back(Parser::getType(token, true));
	}
	catch (const std::exception& e)
	{
		throw SyntaxException();
	}
	return typeList;
}
