#include "DataType.h"
#include "BiNode.h"
#include "BiLinkedList.h"
#include "Dataset.h"

int main(int argc, char* argv[])
{
	Dataset data1("./data_set_file/file1.txt", 0);
	std::cout << data1 << std::endl;
	data1.describe("nameC");
	std::cout << data1[1] << std::endl;
	std::cout << data1[1][3] << std::endl;
	data1.head();
	std::cout << std::endl;
	data1.head(3);
	std::cout << std::endl;
	data1.tail();
	std::cout << std::endl;
	data1.tail(2);
	std::cout << std::endl;
	data1.remove(2);
	data1.printList();
	std::cout << std::endl;
	data1.insert(0);
	data1.printList();
	std::cout << std::endl;
	std::cout << "====================================================" << std::endl;

	Dataset data2("./data_set_file/file2.txt", 1);
	std::cout << data2 << std::endl;
	data2.describe("feature2");
	std::cout << data2[3] << std::endl;
	std::cout << data2[1][2] << std::endl;
	data2.head();
	std::cout << std::endl;
	data2.head(3);
	std::cout << std::endl;
	data2.tail();
	std::cout << std::endl;
	data2.tail(2);
	std::cout << std::endl;
	data2.remove(3);
	data2.printList();
	std::cout << std::endl;
	data2.insert(10);
	data2.printList();
	std::cout << "====================================================" << std::endl;

	Dataset data3("./data_set_file/file3.txt", "col", 0);
	std::cout << data3 << std::endl;
	data3.describe("col1");
	std::cout << data3[1] << std::endl;
	std::cout << data3[2][2] << std::endl;
	data3.head();
	std::cout << std::endl;
	data3.head(3);
	std::cout << std::endl;
	data3.tail();
	std::cout << std::endl;
	data3.tail(2);
	std::cout << std::endl;
	data3.remove(0);
	data3.printList();
	std::cout << std::endl;
	data3.insert(1);
	data3.printList();
	std::cout << "====================================================" << std::endl;

	Dataset data4("./data_set_file/file4.txt", "col", 1);
	std::cout << data4 << std::endl;
	data4.describe("cols1");
	std::cout << data4[5] << std::endl;
	std::cout << data4[3][1] << std::endl;
	data4.head();
	std::cout << std::endl;
	data4.head(3);
	std::cout << std::endl;
	data4.tail();
	std::cout << std::endl;
	data4.tail(2);
	std::cout << std::endl;
	data4.remove(10);
	data4.printList();
	std::cout << std::endl;
	data4.insert(3);
	data4.printList();
	std::cout << std::endl;
	return EXIT_SUCCESS;
};