#include <iostream>
#include "Node.h"



Node::Node()
{
	std::cout << "Node ..." << std::endl;
}


Node::~Node()
{
	std::cout << "~Node ..." << std::endl;
}

void Node::Calc() const
{
	std::cout << "Node::Calc() ..." << std::endl;
}

NodePtr::NodePtr(NodePtr& other) :ptr_(other.Release())
{
}

NodePtr & NodePtr::operator=(NodePtr & other)
{
	Reset(other.Release());
	return *this;
}
