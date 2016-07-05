#include "Exception.h"



const char * Exception::what() const throw()
{
	return message_.c_str();
}

const char * Exception::StackTrace() const throw()
{
	return stackTrace_.c_str();
}

void Exception::FillStackTrace()
{
}
