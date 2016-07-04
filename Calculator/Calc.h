#ifndef _CALC_H_
#define _CALC_H_

#include "SymbolTable.h"
#include "Storage.h"
#include "FunctionTable.h"

#include <string>

class Parser;


class Calc
{
	friend class Parser;
public:
	Calc() :funTbl_(symTbl_),storage_(symTbl_)  {}
private:
	Storage& GetStorage();
	PtrFun GetFunction(unsigned int id) const;
	bool IsFunction(unsigned int id) const;
	unsigned int AddSymbol(const std::string& str);
	unsigned int FindSymbol(const std::string& str) const;
	SymbolTable symTbl_;
	FunctionTable funTbl_;
	Storage storage_;
};

#endif //_CALC_H_
