#ifndef DATA_SET_CPP
#define DATA_SET_CPP

#include "Dataset.h"

Dataset::Dataset(const std::string fpath, bool isAddedIndexes) : fpath(fpath)
{
	std::ifstream in;
	in.open(fpath);

	bool flag = true; // flag for first '\n'

	std::string text;

	int length = 0;
	while (!(in.eof()))
	{
		if (flag)
		{
			in >> text;

			length++;
			setNameFromFile(text, length);

			if (in.peek() == '\n')
			{
				flag = false;
			}
		}
		else
		{
			if ((in.peek() == '\n' || (in.eof())) && !isAddedIndexes)
			{
				in >> text;
			}

			in >> text;

			if (isInteger(text))
			{
				data.PushTail(std::stoi(text));
			}
			else if (isFloat(text))
			{
				data.PushTail(std::stof(text));
			}
			else
			{
				data.PushTail(text);
			}
		}
	}

	size[0] = length;
	size[1] = data.getLen() / length;

	setIndexes(size[1]);

	in.close();
}

Dataset::Dataset(const std::string fpath, const std::string &name, bool isAddedIndexes) : fpath(fpath)
{
	int length = 0;

	std::ifstream in;
	in.open(fpath);

	bool isFirstIn = true;

	std::string text;

	while (!(in.eof()))
	{
		if (isFirstIn)
		{
			if (!isAddedIndexes)
			{
				in >> text;
			}

			isFirstIn = false;

			length++;
		}

		if (in.peek() == '\n' || (in.eof()))
		{
			if (!isAddedIndexes)
			{
				in >> text;
			}

			length++;
		}

		in >> text;

		if (isInteger(text))
		{
			data.PushTail(std::stoi(text));
		}
		else if (isFloat(text))
		{
			data.PushTail(std::stof(text));
		}
		else
		{
			data.PushTail(text);
		}
	}

	size[0] = data.getLen() / length;
	size[1] = length;

	setAutoName(size[0], name);
	setIndexes(size[1]);

	in.close();
}

Dataset::~Dataset()
{
	dispose();
}

void Dataset::printList()
{
	data.printList(data, size[0], size[1], _name, _indexes);
}

void Dataset::head(int n)
{
	data.headList(n, data, size[0], size[1], _name, _indexes);
}
void Dataset::head()
{
	data.headList(data, size[0], size[1], _name, _indexes);
}

void Dataset::tail(int n)
{
	data.tailList(n, data, size[0], size[1], _name, _indexes);
}
void Dataset::tail()
{
	data.tailList(data, size[0], size[1], _name, _indexes);
}

void Dataset::insert(int index)
{
	if (index > size[1])
	{
		std::cout << "Is not possible to insert an index that is too large. Maximum index is " << size[1] << ". Index set to " << size[1] << std::endl;
		index = size[1];
	}

	if (index < 0)
	{
		std::cout << "Is not possible to insert. Minimum index is " << 0 << ". Index set to " << 0 << std::endl;
		index = 0;
	}

	BiLinkedList inserted = getInsertionList(index);
	BiLinkedList *newList = new BiLinkedList;

	DataType type;
	void *value;

	for (int i = 0; i < size[0] * (size[1] + 1); ++i)
	{
		if (i < index * size[0])
		{
			type = data.getNodeIndex(data, i)->type;
			value = data.getNodeIndex(data, i)->data;
		}
		else if (i < (index + 1) * size[0])
		{
			type = inserted.getNodeIndex(inserted, i - index * size[0])->type;
			value = inserted.getNodeIndex(inserted, i - index * size[0])->data;
		}
		else
		{
			type = data.getNodeIndex(data, i - size[0])->type;
			value = data.getNodeIndex(data, i - size[0])->data;
		}

		if (type == DataType::INT)
		{
			int added = void_convert<int>(value);
			newList->PushTail(added);
		}
		else if (type == DataType::FLOAT)
		{
			float added = void_convert<float>(value);
			newList->PushTail(added);
		}
		else if (type == DataType::STRING)
		{
			std::string added = void_convert<std::string>(value);
			newList->PushTail(added);
		}
	}

	size[1]++;
	data = *newList;
	setIndexes(size[1]);
}
void Dataset::remove(int index)
{
	if (index > size[1] - 1 || index < 0)
	{
		std::cout << "Wrong index. Maximum index " << size[1] - 1 << ". Index set to " << size[1] - 1 << std::endl;
		index = size[1] - 1;
	}
	else
	{
		BiLinkedList *newList = new BiLinkedList;

		int i = 0;
		while (i < size[0] * size[1])
		{
			if (index == i / size[0])
			{
				i++;
			}
			else
			{
				DataType type = data.getNodeIndex(data, i)->type;
				void *value = data.getNodeIndex(data, i)->data;

				if (type == DataType::INT)
				{
					int val = *static_cast<int *>(value);
					newList->PushTail(val);
				}
				else if (type == DataType::FLOAT)
				{
					float val = *static_cast<float *>(value);
					newList->PushTail(val);
				}
				else if (type == DataType::STRING)
				{
					std::string val = *static_cast<std::string *>(value);
					newList->PushTail(val);
				}

				i++;
			}
		}

		data = *newList;
		size[1]--;
		setIndexes(size[1]);
	}
}
void Dataset::describe(const std::string name)
{
	int index_name = getIndexName(name);
	float max = 0;
	float min = 0;
	float average = 0;
	float standart_deviation = 0;

	if (index_name == -1)
	{
		std::cout << name << " does not exist in file." << std::endl;
	}
	else
	{
		BiLinkedList *list_column = getListIndexColumn(index_name);

		if (list_column->getNodeIndex(*list_column, 0)->type == DataType::FLOAT)
		{
			max = countMaximum<float>(list_column);
			min = countMinimum<float>(list_column);
			average = countAverageValue<float>(list_column);
			standart_deviation = countStandartDeviation<float>(list_column);
		}
		else
		{
			max = countMaximum<int>(list_column);
			min = countMinimum<int>(list_column);
			average = countAverageValue<int>(list_column);
			standart_deviation = countStandartDeviation<int>(list_column);
		}

		if (max == -1 || min == -1 || average == -1 || standart_deviation == -1)
		{
			std::cout << "Data sets is empty" << std::endl;
		}

		std::cout << "=============Describe column number " << index_name << ":=============" << std::endl;
		std::cout << "Maximum value of column is " << max << std::endl;
		std::cout << "Minimum value of column is " << min << std::endl;
		std::cout << "Avearage value of column is " << average << std::endl;
		std::cout << "Standart deviation value of column is " << standart_deviation << std::endl;
		std::cout << "====================================================" << std::endl;
	}
}

BiLinkedList Dataset::operator[](int index)
{
	BiLinkedList *list = new BiLinkedList;
	if (index > size[1] || index < 0)
	{
		return *list;
	}

	list = getListIndexLine(index);
	return *list;
}
std::ostream &operator<<(std::ostream &stream, const Dataset &dataset) // just list data
{
	stream << dataset.data;
	return stream;
}

void Dataset::setNameFromFile(const std::string name, int len)
{
	std::string *temp = new std::string[len];
	for (int i = 0; i < len - 1; ++i)
	{
		temp[i] = _name[i];
	}

	temp[len - 1] = name;

	_name = temp;
}
void Dataset::setAutoName(int len, const std::string name)
{
	_name = new std::string[len];
	for (int i = 0; i < len; i++)
	{
		_name[i] = name + std::to_string(i);
	}
}
void Dataset::setIndexes(int wid)
{
	_indexes = new int[wid];
	for (int i = 0; i < wid; i++)
	{
		_indexes[i] = i;
	}
}

BiLinkedList Dataset::getInsertionList(int index)
{
	BiLinkedList cin_List;
	std::string ins_str;

	int i = 0;

	while (i < size[0])
	{
		std::cout << "Write insert line of column " << _name[i] << ": ";
		std::cin >> ins_str;
		std::cout << std::endl;

		if (isInteger(ins_str))
		{
			if (data.getNodeIndex(data, i)->getNodeDataType() != DataType::INT)
			{
				std::cout << "Wrong DataType";
				std::cout << std::endl;
			}
			else
			{
				cin_List.PushTail(std::stoi(ins_str));
				i++;
			}
		}
		else if (isFloat(ins_str))
		{
			if (data.getNodeIndex(data, i)->getNodeDataType() != DataType::FLOAT)
			{
				std::cout << "Wrong DataType";
				std::cout << std::endl;
			}
			else
			{
				cin_List.PushTail(std::stof(ins_str));
				i++;
			}
		}
		else
		{
			if (data.getNodeIndex(data, i)->getNodeDataType() != DataType::STRING)
			{
				std::cout << "Wrong DataType";
				std::cout << std::endl;
			}
			else
			{
				cin_List.PushTail(ins_str);
				i++;
			}
		}
	}
	return cin_List;
}

BiLinkedList *Dataset::getListIndexLine(int index)
{
	BiLinkedList *newList = new BiLinkedList;

	DataType type;
	void *value;

	for (int i = 0; i < size[0]; ++i)
	{
		type = data.getNodeIndex(data, index * size[0] + i)->type;
		value = data.getNodeIndex(data, index * size[0] + i)->data;

		if (type == DataType::INT)
		{
			int added = void_convert<int>(value);
			newList->PushTail(added);
		}
		else if (type == DataType::FLOAT)
		{
			float added = void_convert<float>(value);
			newList->PushTail(added);
		}
		else if (type == DataType::STRING)
		{
			std::string added = void_convert<std::string>(value);
			newList->PushTail(added);
		}
	}

	return newList;
}
int Dataset::getIndexName(const std::string name)
{
	for (int i = 0; i < size[1]; ++i)
	{
		if (_name[i] == name)
		{
			return i;
		}
	}
	return -1; // if name does not exist
}
BiLinkedList *Dataset::getListIndexColumn(int index) // for string variable, we return list integer number, number is count of characters of line
{
	BiLinkedList *newList = new BiLinkedList;

	DataType type;
	void *value;

	for (int i = 0; i < size[1]; ++i)
	{
		type = data.getNodeIndex(data, i * size[0] + index)->type;
		value = data.getNodeIndex(data, i * size[0] + index)->data;

		if (type == DataType::INT)
		{
			int added = void_convert<int>(value);
			newList->PushTail(added);
		}
		else if (type == DataType::FLOAT)
		{
			float added = void_convert<float>(value);
			newList->PushTail(added);
		}
		else if (type == DataType::STRING)
		{
			std::string added = void_convert<std::string>(value);

			int length_str = added.length();
			newList->PushTail(length_str);
		}
	}

	return newList;
}

void Dataset::dispose()
{
	if (_name != nullptr)
	{
		delete[] _name;
	}

	if (_indexes != nullptr)
	{
		delete[] _indexes;
	}
}

bool Dataset::isInteger(const std::string &s)
{
	if (s.empty())
	{
		return false;
	}

	int start = 0;
	if (s[0] == '-')
	{
		if (s.length() == 1)
		{
			return false;
		}
		start = 1;
	}

	for (int i = start; i < s.length(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return false;
		}
	}

	return true;
}
bool Dataset::isFloat(const std::string &s)
{
	if (s.empty())
	{
		return false;
	}

	int start = 0;
	bool isPointFound = false;

	if (s[0] == '-')
	{
		if (s.length() == 1)
		{
			return false;
		}
		start = 1;
	}

	for (int i = start; i < s.length(); ++i)
	{
		if (s[i] == '.')
		{
			if (isPointFound)
			{
				return false;
			}
			isPointFound = true;

			if (i == start || i == s.length() - 1)
			{
				return false;
			}
		}
		else if (s[i] < '0' || s[i] > '9')
		{
			return false;
		}
	}

	return isPointFound;
}

int Dataset::getSizeDataSet()
{
	return size[0] * size[1];
}

#endif