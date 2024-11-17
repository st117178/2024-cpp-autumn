#ifndef BI_NODE_CPP
#define BI_NODE_CPP

#include "BiNode.h"

DataType BiNode::getNodeDataType()
{
	DataType datatype;
	if (next != nullptr)
	{
		datatype = type;
	}

	return datatype;
}

std::ostream& operator<<(std::ostream& stream, const BiNode& node)
{
	if (node.type == DataType::INT)
	{
		stream << *static_cast<int*>(node.data);
	}
	else if (node.type == DataType::FLOAT)
	{
		stream << *static_cast<float*>(node.data);
	}
	else if (node.type == DataType::STRING)
	{
		stream << *static_cast<std::string*>(node.data);
	}
	return stream;
}

#endif