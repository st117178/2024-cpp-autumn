#ifndef BI_NODE_H
#define BI_NODE_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include "DataType.h"

struct BiNode {
	void* data;
	DataType type;
	BiNode* next;
	BiNode* prev;

	BiNode() : type(DataType::INT), next(nullptr), prev(nullptr), data(nullptr) {}
	BiNode(int value) : type(DataType::INT), next(nullptr), prev(nullptr), data(new int(value)) {}
	BiNode(float value) : type(DataType::FLOAT), next(nullptr), prev(nullptr), data(new float(value)) {}
	BiNode(const std::string& value) : type(DataType::STRING), next(nullptr), prev(nullptr), data(new std::string(value)) {}

	DataType getNodeDataType();

	friend std::ostream& operator<<(std::ostream& stream, const BiNode& node);
};

#endif