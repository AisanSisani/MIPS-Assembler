#include <iostream>
#include <exception>
//#include "exceptions.h"

using namespace std;

class mnemonicException : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "mnemonic is not found";
	}
};


