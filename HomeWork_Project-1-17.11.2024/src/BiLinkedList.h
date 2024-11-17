#ifndef BI_LINKED_LIST_H
#define BI_LINKED_LIST_H

#include "BiNode.h"

class BiLinkedList {
public:
	BiLinkedList() : head(nullptr), tail(nullptr), length(0) {}

	~BiLinkedList() { dispose(); }

	void PushTail(int value) { addNode(new BiNode(value)); }
	void PushTail(float value) { addNode(new BiNode(value)); }
	void PushTail(const std::string value) { addNode(new BiNode(value)); }

	void headList(int n, BiLinkedList list, int len, int wid, std::string* _name, int* _indexes);
	void headList(BiLinkedList list, int len, int wid, std::string* _name, int* _indexes);

	void tailList(int n, BiLinkedList list, int len, int wid, std::string* _name, int* _indexes);
	void tailList(BiLinkedList list, int len, int wid, std::string* _name, int* _indexes);

	void printList(BiLinkedList list, int len, int wid, std::string* _name, int* _indexes);
	void printNames(int len, std::string* _name);

	BiNode* getNodeIndex(BiLinkedList data, int index);

	int getLen();

	BiNode operator[](int index);

	friend std::ostream& operator<<(std::ostream& stream, const BiLinkedList& list);
private:
	BiNode* head;
	BiNode* tail;
	int length;

	void addNode(BiNode* node);

	void dispose();
};

#endif