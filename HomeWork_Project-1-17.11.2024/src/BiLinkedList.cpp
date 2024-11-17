#ifndef BI_LINKED_LIST_CPP
#define BI_LINKED_LIST_CPP

#include "BiLinkedList.h"

void BiLinkedList::headList(int n, BiLinkedList list, int len, int wid, std::string* _name, int* _indexes)
{
	if (n > wid || n < 0)
	{
		std::cout << "Out of List";
	}
	else
	{
		printNames(len, _name);

		int i = 0;
		while ((i / len) != n)
		{
			if (i % len == 0)
			{
				std::cout << _indexes[i / len] << " ";
			}

			std::cout << *(list.head);

			if ((i + 1) % len == 0)
			{
				std::cout << std::endl;
			}
			else
			{
				std::cout << " ";
			}

			list.head = list.head->next;

			i++;
		}
	}

	list.head = list.tail->next;
}
void BiLinkedList::headList(BiLinkedList list, int len, int wid, std::string* _name, int* _indexes)
{
	int n = 5;

	if (n > wid)
	{
		list.printList(list, len, wid, _name, _indexes);
	}
	else
	{
		printNames(len, _name);

		int i = 0;
		while ((i / len) != n)
		{
			if (i % len == 0)
			{
				std::cout << _indexes[i / len] << " ";
			}

			std::cout << *(list.head);

			if ((i + 1) % len == 0)
			{
				std::cout << std::endl;
			}
			else
			{
				std::cout << " ";
			}

			list.head = list.head->next;

			i++;
		}
	}

	list.head = list.tail->next;
}

void BiLinkedList::tailList(int n, BiLinkedList list, int len, int wid, std::string* _name, int* _indexes)
{
	if (n > wid || n < 0)
	{
		std::cout << "Out of List";
	}
	else
	{
		printNames(len, _name);

		int i = 0;
		while (list.head != nullptr)
		{
			if (i >= (wid - n) * len)
			{
				if (i % len == 0)
				{
					std::cout << _indexes[i / len] << " ";
				}

				std::cout << *(list.head);

				if ((i + 1) % len == 0)
				{
					std::cout << std::endl;
				}
				else
				{
					std::cout << " ";
				}
			}

			list.head = list.head->next;

			i++;
		}
	}
}
void BiLinkedList::tailList(BiLinkedList list, int len, int wid, std::string* _name, int* _indexes)
{
	int n = 5;

	if (n > wid)
	{
		list.printList(list, len, wid, _name, _indexes);
	}
	else
	{
		printNames(len, _name);

		int i = 0;
		while (list.head != nullptr)
		{
			if (i >= (wid - n) * len)
			{
				if (i % len == 0)
				{
					std::cout << _indexes[i / len] << " ";
				}

				std::cout << *(list.head);

				if ((i + 1) % len == 0)
				{
					std::cout << std::endl;
				}
				else
				{
					std::cout << " ";
				}
			}

			list.head = list.head->next;

			i++;
		}
	}

	list.head = list.tail->next;
}

void BiLinkedList::printList(BiLinkedList list, int len, int wid, std::string* _name, int* _indexes)
{
	printNames(len, _name);

	int i = 0;
	while (list.head != nullptr)
	{
		if (i % len == 0)
		{
			std::cout << _indexes[i / len] << " ";
		}

		std::cout << *(list.head);

		if ((i + 1) % len == 0)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << " ";
		}

		list.head = list.head->next;

		i++;
	}
}
void BiLinkedList::printNames(int len, std::string* _name)
{
	std::cout << " ";

	for (int i = 0; i < len; i++)
	{
		std::cout << _name[i] << " ";
	}

	std::cout << std::endl;
}

BiNode* BiLinkedList::getNodeIndex(BiLinkedList data, int index)
{
	if (index > data.length)
	{
		return nullptr;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			data.head = data.head->next;
		}
		BiNode* result = data.head;
		data.head = data.tail->next;
		return result;
	}
}

int BiLinkedList::getLen()
{
	return length;
}

BiNode BiLinkedList::operator[](int index)
{
	BiNode* nodeIndex = head;
	if (index > (length - 1) || index < 0)
	{
		std::cout << "Wrong index" << std::endl;
		nodeIndex = nullptr;
		return *nodeIndex;
	}
	else
	{
		for (int i = 0; i < index; ++i)
		{
			nodeIndex = nodeIndex->next;
		}

		return *nodeIndex;
	}
}

std::ostream& operator<<(std::ostream& stream, const BiLinkedList& list) {
	BiNode* temp = list.head;

	while (temp != nullptr)
	{
		stream << *temp << " ";
		temp = temp->next;
	}
	return stream;
}

void BiLinkedList::addNode(BiNode* node)
{
	if (!head)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	++length;
}

void BiLinkedList::dispose() {
	BiNode* current = head;

	while (current) {
		BiNode* temp = current;
		current = current->next;

		delete temp;
	}
}

#endif