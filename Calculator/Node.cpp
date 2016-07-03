#include "Node.h"
#include <cmath>
#include <iostream>

double NumberNode::Calc() const
{
	return number_;
}

BinaryNode::~BinaryNode()
{
	delete left_;
	delete right_;
}

double AddNode::Calc() const
{
	return left_->Calc() + right_->Calc();
}

double SubdNode::Calc() const
{
	return left_->Calc() - right_->Calc();
}

double MultiplydNode::Calc() const
{
	return left_->Calc() * right_->Calc();
}

double DivideNode::Calc() const
{
	double divisor = right_->Calc();
	if(divisor != 0.0)
		return left_->Calc() / right_->Calc();
	else
	{
		std::cout << "Error: Divisor by zero" << std::endl;
		return HUGE_VAL;
	}
}

UnaryNode::~UnaryNode()
{
	delete child_;
}

double UMinusNode::Calc() const
{
	return -(child_->Calc());
}
