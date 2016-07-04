#include "Calc.h"

Storage & Calc::GetStorage()
{
	return storage_;
}

PtrFun Calc::GetFunction(unsigned int id) const
{
	return funTbl_.GetFunction(id);
}

bool Calc::IsFunction(unsigned int id) const
{
	return id < funTbl_.Size();
}

unsigned int Calc::AddSymbol(const std::string & str)
{
	return symTbl_.Add(str);
}

unsigned int Calc::FindSymbol(const std::string & str) const
{
	return symTbl_.Find(str);
}
