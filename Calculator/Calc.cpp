#include "Calc.h"

Storage & Calc::GetStorage()
{
	return storage_;
}

unsigned int Calc::AddSymbol(const std::string & str)
{
	return symTbl_.Add(str);
}

unsigned int Calc::FindSymbol(const std::string & str) const
{
	return symTbl_.Find(str);
}
