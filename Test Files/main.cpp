/**
* Standard includes
*/
#include <iostream>

/**
* Include the cpp test!
*/
#include "Test.hpp"

int main(void)
{
	BigNumber bg[2]{std::string("165"),std::string("935")};
	std::cout << bg[0] << std::endl;
	std::cout << bg[1] << std::endl;
	std::cout << bg[0] + bg[1] << std::endl;
	std::cout << bg[1] + bg[0] << std::endl;

	bg[0] = "200";
	std::cout << bg[1] + bg[0] << std::endl;

 	return 0;
}