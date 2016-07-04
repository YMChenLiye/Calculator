#include <iostream>
#include <string>
#include "Parser.h"
#include "Scanner.h"
#include "Calc.h"

using namespace std;

int main(void)
{
	Calc calc;
	STATUS status = STATUS_OK;
	do
	{
		std::cout << "> ";
		std::string buf;
		std::getline(std::cin, buf);
		//std::cout << buf << endl;
		Scanner scanner(buf);
		if (!scanner.IsEmpty())
		{
			Parser parse(scanner, calc);
			status = parse.Parse();
			if (status == STATUS_OK)
			{
				std::cout << parse.Calculate() << std::endl;
			}
			else
				std::cout << "Syntax Error." << std::endl;
		}
		else
			std::cout << "Expression is empty" << std::endl;


	} while (status != STATUS_QUIT);
	return 0;
}