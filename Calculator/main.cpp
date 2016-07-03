#include <iostream>
#include <string>
#include "Parser.h"
#include "Scanner.h"

using namespace std;

int main(void)
{

	do
	{
		std::cout << "> ";
		std::string buf;
		std::getline(std::cin, buf);
		std::cout << buf << endl;
		Scanner scanner(buf);
		Parser parse(scanner);
		parse.Parse();
		parse.Calculate();

	} while (1);
	return 0;
}