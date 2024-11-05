#include "Array[].h"

int main(int argc, char* argv[])
{
	int masive[7]{ 1, 2 ,3 ,-4 ,5 ,6 ,7 };
	Array<int> mas(masive);
	mas.show();
	std::cout << mas.minimum(mas);
	return 0;
};