#ifndef _FUNCTION_TABLE_H_
#define _FUNCTION_TABLE_H_

class SymbolTable;
typedef double(*PtrFun)(double);

class FunctionTable
{
public:
	FunctionTable(SymbolTable& tbl);
	~FunctionTable();
	void Init(SymbolTable& tbl);
	PtrFun GetFunction(unsigned int id) const;
	unsigned int Size() const;
private:
	PtrFun* pFuns_;
	unsigned int size_;

};

#endif //_FUNCTION_TABLE_H_
