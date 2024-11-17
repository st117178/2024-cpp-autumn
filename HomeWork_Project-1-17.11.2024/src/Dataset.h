#ifndef DATA_SET_H
#define DATA_SET_H

#include "BiLinkedList.h"

class Dataset {
public:
	Dataset(const std::string fpath, bool isAddedIndexes);

	Dataset(const std::string fpath, const std::string& name, bool isAddedIndexes);

	~Dataset();

	void printList();

	void head(int n);
	void head();

	void tail(int n);
	void tail();

	void insert(int index);
	void remove(int index);
	void describe(const std::string name);

	BiLinkedList operator[](int index);
	friend std::ostream& operator<<(std::ostream& stream, const Dataset& dataset);

private:
	const std::string fpath;
	BiLinkedList data;

	int* size = new int[2] {0};// size[0] - count of column, size[1] - count of line

	std::string* _name;
	int* _indexes;

	void setNameFromFile(const std::string name, int len);
	void setAutoName(int len, const std::string name);
	void setIndexes(int wid);

	BiLinkedList getInsertionList(int index);

	BiLinkedList* getListIndexLine(int index);
	int getIndexName(const std::string name);
	BiLinkedList* getListIndexColumn(int index);

	template<class T>
	T countMaximum(BiLinkedList* list)
	{
		if (size[1] == 0)
		{
			return 0;
		}
		else
		{
			BiNode* max_node = list->getNodeIndex(*list, 0);
			T max = void_convert<T>(max_node->data);

			for (int i = 0; i < size[1];++i)
			{
				if (void_convert<T>(list->getNodeIndex(*list, i)->data) > max)
				{
					max_node = list->getNodeIndex(*list, i);
					max = void_convert<T>(max_node->data);
				}
			}

			return max;
		}
	}

	template<class T>
	T countMinimum(BiLinkedList* list)
	{
		if (size[1] == 0)
		{
			return -1;
		}
		else
		{
			BiNode* min_node = list->getNodeIndex(*list, 0);
			T min = void_convert<T>(min_node->data);

			for (int i = 0; i < size[1];++i)
			{
				if (void_convert<T>(list->getNodeIndex(*list, i)->data) < min)
				{
					min_node = list->getNodeIndex(*list, i);
					min = void_convert<T>(min_node->data);
				}
			}

			return min;
		}
	}

	template<class T>
	float countAverageValue(BiLinkedList* list)
	{
		if (size[1] == 0)
		{
			return -1;
		}
		else
		{
			float sum = 0;

			for (int i = 0; i < size[1];++i)
			{
				sum += void_convert<T>(list->getNodeIndex(*list, i)->data);
			}

			float average_value = sum / size[1];

			return average_value;
		}
	}

	template<class T>
	float countStandartDeviation(BiLinkedList* list)
	{
		if (size[1] == 0)
		{
			return -1;
		}
		else
		{
			float sum_square = 0;
			float average = countAverageValue<T>(list);

			for (int i = 0; i < size[1];++i)
			{
				sum_square += (void_convert<T>(list->getNodeIndex(*list, i)->data) - average) * (void_convert<T>(list->getNodeIndex(*list, i)->data) - average);
			}

			float standart_deviation = sqrt((sum_square) / (size[1] - 1));
			return standart_deviation;
		}
	}

	template<class T>
	T void_convert(void* value)//void* to int
	{
		return *static_cast<T*>(value);
	}

	void dispose();

	bool isInteger(const std::string& s);
	bool isFloat(const std::string& s);
};

#endif