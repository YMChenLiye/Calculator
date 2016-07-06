#include <iostream>
#include <string>
#include "Parser.h"
#include "Scanner.h"
#include "Calc.h"
#include "Exception.h"
#include "CommandParser.h"

using namespace std;

int main(void)
{
	Calc calc;
	STATUS status = STATUS_OK;
	do
	{
		std::cout << "> ";
		//std::string buf;
		//std::getline(std::cin, buf);
		//std::cout << buf << endl;
		Scanner scanner(std::cin);
		if (!scanner.IsEmpty())
		{
			if (scanner.IsCommand())
			{
				CommandParser parser(scanner, calc);
				status = parser.Execute();
			}
			else
			{
				Parser parse(scanner, calc);
				try
				{
					status = parse.Parse();
					if (status == STATUS_OK)
					{
						std::cout << parse.Calculate() << std::endl;
					}
				}
				catch (SyntaxError& se)
				{
					status = STATUS_QUIT;
					std::cout << se.what() << std::endl;
					//std::cout << se.StackTrace() << std::endl;
				}
				catch (Exception& e)
				{
					status = STATUS_QUIT;
					std::cout << e.what() << std::endl;
				}
				catch (std::bad_alloc& e)
				{
					status = STATUS_QUIT;
					std::cout << e.what() << std::endl;
				}
				catch (...)
				{
					status = STATUS_QUIT;
					std::cout << "Internl error" << std::endl;
				}
			}
			
		}
		else
		{
			status = STATUS_QUIT;
			std::cout << "Expression is empty" << std::endl;
		}
			


	} while (status != STATUS_QUIT);
	return 0;
}