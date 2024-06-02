#include "ScalarConverter.hpp"   

int main(int argc, char **arg)
{
	if (argc != 2)
	{
		std::cerr << "One Argument required." << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert(arg[1]);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
