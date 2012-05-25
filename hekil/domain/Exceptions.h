#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <string>
using namespace std;

namespace domain
{

class MyException
{
public:
	MyException(string msg):message(msg){}
	const string& getMessage() const {return message;}
private:
	string message;
};

class ValidatorException: public MyException
{
public:
	ValidatorException(string msg): MyException(msg){}
};

class RepositoryException: public MyException
{
public:
	RepositoryException(string msg): MyException(msg){}
};

}

#endif /* EXCEPTIONS_H_ */


