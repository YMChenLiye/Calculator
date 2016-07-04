#include "Parser.h"
#include "Scanner.h"
#include "Node.h"

#include <cassert>
#include <iostream>


Parser::Parser(Scanner& scanner) :scanner_(scanner), tree_(0)
{
}

void Parser::Parse()
{
	tree_ = Expr();
}

Node* Parser::Expr()
{
	Node* node = Term();
	EToken token = scanner_.Token();
	//if (token == TOKEN_PLUS)
	//{
	//	scanner_.Accept();
	//	Node* nodeRight = Expr();
	//	node = new AddNode(node, nodeRight);
	//}
	//else if (token == TOKEN_MINUS)
	//{
	//	scanner_.Accept();
	//	Node* nodeRight = Expr();
	//	node = new SubNode(node, nodeRight);
	//}

	//Expr := Term { ('+' | '-') Term }
	if (token == TOKEN_PLUS || token == TOKEN_MINUS)
	{
		MultipleNode* multipleNode = new SumNode(node);
		do
		{
			scanner_.Accept();
			Node* nextNode = Term();
			multipleNode->AppendChild(nextNode, (token == TOKEN_PLUS));
			token = scanner_.Token();
		} while (token == TOKEN_PLUS || token==TOKEN_MINUS);
		node = multipleNode;
	}
	return node;
}

Node* Parser::Term()
{
	Node* node = Factor();
	EToken token = scanner_.Token();
	//if (token == TOKEN_MULTIPLY)
	//{
	//	scanner_.Accept();
	//	Node* nodeRight = Term();
	//	node = new MultiplydNode(node, nodeRight);
	//}
	//else if (token == TOKEN_DIVIDE)
	//{
	//	scanner_.Accept();
	//	Node* nodeRight = Term();
	//	node = new DivideNode(node, nodeRight);
	//}
	
	//Term := Factor { ('*' | '/') Factor }
	if (token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE)
	{
		MultipleNode* multipleNode = new ProductNode(node);
		do
		{
			scanner_.Accept();
			Node* nextNode = Factor();
			multipleNode->AppendChild(nextNode, (token == TOKEN_MULTIPLY));
			token = scanner_.Token();
		} while (token == TOKEN_MULTIPLY || token == TOKEN_DIVIDE);
		node = multipleNode;
	}
	return node;
}

Node* Parser::Factor()
{
	Node* node = 0;
	EToken token = scanner_.Token();
	if (token == TOKEN_LPARENTHESIS)
	{
		scanner_.Accept();	//accept '('
		node = Expr();
		if (scanner_.Token() == TOKEN_RPARENTHESIS)
		{
			scanner_.Accept();	//accept ')'
		}
		else
		{
			status_ = STATUS_ERROR;
			//todo:throw exception
			std::cout << "missing parenthesis" << std::endl;
			node = 0;
		}
	}
	else if (token == TOKEN_NUMBER)
	{
		node = new NumberNode(scanner_.Number());
		scanner_.Accept();
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.Accept();	//accept '-'
		node = new UMinusNode(Factor());
	}
	else
	{
		status_ = STATUS_ERROR;
		std::cout << "Not a valid expression" << std::endl;
	}

	return node;
}

double Parser::Calculate() const
{
	assert(tree_ != 0);
	return tree_->Calc();
}


