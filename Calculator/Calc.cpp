#include "Calc.h"
#include <iostream>

void Calc::Serialize(Serializer & out) const
{
	symTbl_.Serialize(out);
	storage_.Serialize(out);
}

void Calc::DeSerialize(DeSerializer & in)
{
	symTbl_.DeSerialize(in);
	storage_.DeSerialize(in);
}

void Calc::ListFun() const
{
	for (unsigned int i = 0; i < funTbl_.Size(); ++i)
	{
		std::cout << symTbl_.GetSymbolName(i) << "  ";
	}
	std::cout << std::endl;
}

void Calc::ListVar() const
{
	for (unsigned int i = funTbl_.Size(); i < symTbl_.GetCurId(); ++i)
	{
		std::string name = symTbl_.GetSymbolName(i);
		double val;
		if (GetVariableValue(i, val))
			std::cout << name << " = " << val << std::endl;
		else
			std::cout << name << " = ?" << std::endl;
		
	}
}

bool Calc::GetVariableValue(unsigned int id, double & val) const
{
	if (storage_.IsInit(id))
	{
		val = storage_.GetValue(id);
		return true;
	}
	return false;
}

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
