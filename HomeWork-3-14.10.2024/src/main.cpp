#include "Str-operator[].h"

int main(int argc, char* argv[])
{
	String hello("hello");
	std::cout << hello << std::endl;
	String const hell = hello[0][4];
	std::cout << hell << std::endl;
	String const ell = hello[1][4];
	std::cout << ell << std::endl;
	String const empty = hello[1][1];
	std::cout << empty << std::endl;
};